//
// Created by Ram on 13-06-2021.
//

#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H

#include <iostream>
#include "Coordinates.h"
#include "Utils.h"

class Snake {
public:
    Snake();
    Snake(int height, int width);
    ~Snake() = default;
    [[nodiscard]] auto CreateSnake() const;
private:
    int _height{};
    int _width{};
};

Snake::Snake() = default;

Snake::Snake(int height, int width) : _height(height), _width(width) {}

auto Snake::CreateSnake() const {
    return Coordinates(Utils::GetRandomValue(1, _height-1),
                       Utils::GetRandomValue(1, _width-1));
}

#endif //SNAKE_GAME_SNAKE_H
