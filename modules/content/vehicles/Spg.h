#pragma once

#include "Tank.h"
#include "../../map/Hex.h"
#include "../Content.h"

class Spg : public Tank {
public:
    Spg(int x, int y, int z, int spawn_x, int spawn_y, int spawn_z,
        int health_points, int capture_points, int id);
};