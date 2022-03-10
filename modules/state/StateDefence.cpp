#include "StateDefence.h"
#include <algorithm> //std::sort
#include <iostream> //std::cout
#include <string> //std::string
#include <vector> //std::vector


StateDefence::StateDefence(std::shared_ptr<Tank> tank, std::shared_ptr<Game> game, std::shared_ptr<Param> param)
        : State(tank, game,
                param) {
}


std::string StateDefence::getType() {
    return "defence";
}


std::string StateDefence::calculateAction() {
    auto position = tank->getPosition();
    
    auto shoots = game->getPossibleShoots(tank);

    auto shoot = game->selectBestShootDefence(shoots, tank);
    if (!shoot.empty())
        return shootToString(shoot);

    if (std::find(game->map.base.begin(), game->map.base.end(), position) == game->map.base.end()) {
        // Not on base
        auto path = game->map.findPath(tank->getPosition(), game->map.base, tank);
        if (!path.empty())
            return moveToString(path[1]);
    }
    auto possible_shoots = game->getPossibleShoots(tank);
    if (!possible_shoots.empty())
        return shootToString(game->selectBestShoot(possible_shoots, tank, false));

    // TODO едем к ближайшему танку на базе для выстрела
    return "";

}
