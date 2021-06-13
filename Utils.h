//
// Created by Ram on 13-06-2021.
//

#ifndef SNAKE_GAME_UTILS_H
#define SNAKE_GAME_UTILS_H

#include <iostream>
#include <random>

class Utils {
public:
    static auto GetRandomValue(int min, int max);
};

auto Utils::GetRandomValue(int min, int max) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

#endif //SNAKE_GAME_UTILS_H
