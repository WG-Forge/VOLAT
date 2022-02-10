#include "State.h"

State::State(std::shared_ptr<Tank> tank, std::shared_ptr<Game> game, std::shared_ptr<Param> param) : tank(tank),
                                                                                                     game(game),
                                                                                                     param(param) {
};

std::string State::moveToString(std::shared_ptr<Hex> hex) {
    game->updateTank(tank->id, hex->x, hex->y, hex->z);

    return "{\"type\":\"MOVE\",\"data\":{\"vehicle_id\":" + std::to_string(tank->id) +
           ",\"target\":{\"x\":" + std::to_string(hex->x) + ",\"y\":" + std::to_string(hex->y) + ",\"z\":" +
           std::to_string(hex->z) + "}}}";
}

std::string State::shootToString(std::vector<std::shared_ptr<Tank>> tanks) {
    for (auto tank: tanks) {
        tank->update(tank->getHealthPoints() - 1);
    }

    Hex hex = tanks[0]->getPosition();
    if (tank->getTankType() == TankType::AT_SPG) {
        Hex hex_mis_dis = hex;
        int min_dis = 1e9;
        for (auto pos: tank->getPosition().neighbors) {
            if (hex.getDistance(*pos) < min_dis) {
                min_dis = hex.getDistance(*pos);
                hex_mis_dis = *pos;
            }
        }
        hex = hex_mis_dis;
    }

    return "{\"type\":\"SHOOT\",\"data\":{\"vehicle_id\":" + std::to_string(tank->id) +
           ",\"target\":{\"x\":" + std::to_string(hex.x) + ",\"y\":" + std::to_string(hex.y) + ",\"z\":" +
           std::to_string(hex.z) + "}}}";
}

