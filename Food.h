//
// Created by Ram on 13-06-2021.
//

#ifndef SNAKE_GAME_FOOD_H
#define SNAKE_GAME_FOOD_H

#include <iostream>
#include <random>
#include "Coordinates.h"
#include "Utils.h"

#define FOOD 'F'

class Food {
public:
    Food() = default;
    ~Food() = default;
    Food(int height, int width) : _height(height), _width(width) {}
    [[nodiscard]] auto CreateFood() const;
public:
private:
    int _height{};
    int _width{};
};

auto Food::CreateFood() const {
    return Coordinates(Utils::GetRandomValue(1, _height-1),
                       Utils::GetRandomValue(1, _width-1));
}

#endif //SNAKE_GAME_FOOD_H
