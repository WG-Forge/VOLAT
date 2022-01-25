#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <winsock2.h>
#include <string>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;


class Hex {
public:
    int x;
    int y;
    int z;
    bool is_occupied;
    json data;

    Hex(int x, int y, int z, bool is_occupied = false, json data = json::parse("{}"));

    Hex &operator+=(const Hex &hex);

    friend Hex operator+(Hex &a, const Hex &b);

    Hex &operator-=(const Hex &hex);

    friend Hex operator-(Hex &a, const Hex &b);

    Hex hex_direction(int direction);

    Hex hex_neighbor(int direction);

    Hex hex_diagonal_neighbor(int direction);

    int hex_length();

    int hex_distance(Hex hex);



};




