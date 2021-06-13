//
// Created by Ram on 13-06-2021.
//

#ifndef SNAKE_GAME_BORDER_H
#define SNAKE_GAME_BORDER_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Food.h"

class Border {
public:
    Border() = default;
    ~Border() = default;
    Border(int height, int width);
    [[nodiscard]] const int& GetHeight() const { return _height; }
    [[nodiscard]] const int& GetWidth() const { return _width; }
    void Draw(const Coordinates &foodCoord);
    void Draw(const Coordinates &snakeCoord, const Coordinates &foodCoord, int snakeLength) const;
    void SetBorderCoordinates();
    void PrintCoordinates() const;
private:
    int _height{};
    int _width{};
    std::vector<std::vector<int>> coordinates;
};

Border::Border(int height, int width)  : _height(height), _width(width) {}

void Border::Draw(const Coordinates &foodCoord) {
    std::system("clear");
    for (int h = 0; h < _height; h++) {
        for (int w = 0; w < _width; w++) {
            if ((h == 0 || h == _height-1) || (w == 0 || w == _width-1)) {
                std::printf("!");
            } else if (h == foodCoord.x && w == foodCoord.y) {
                // TODO: length of the snake is now 1
                //  this should be refined as snake grows
                //  consuming food
                std::printf("%c", FOOD);
            } else {
                std::printf(" ");
            }
        }
        std::printf("\n");
    }
}

void Border::Draw(const Coordinates &snakeCoord, const Coordinates &foodCoord, int snakeLength) const {
    std::system("clear");
    for (int h = 0; h < _height; h++) {
        for (int w = 0; w < _width; w++) {
            if ((h == 0 || h == _height-1) || (w == 0 || w == _width-1)) {
                std::printf("!");
            } else if (h == foodCoord.x && w == foodCoord.y) {
                std::printf("%c", FOOD);
            } else if (h == snakeCoord.x && w == snakeCoord.y) {
                // TODO: length of the snake is now 1
                //  this should be refined as snake grows
                //  consuming food
                std::printf("*");
            } else {
                std::printf(" ");
            }
        }

        std::printf("\n");
    }
}

void Border::PrintCoordinates() const {
    for (const auto & coordinate : coordinates) {
        for (int j : coordinate) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void Border::SetBorderCoordinates() {
    for (int h = 0; h < _height; h++) {
        std::vector<int> horizontal;

        for (int w = 0; w < _width; w++) {
            if ((h == 0 || h == _height - 1) || (w == 0 || w == _width - 1)) {
                horizontal.push_back(1);
            } else {
                horizontal.push_back(0);
            }
        }
        coordinates.push_back(horizontal);
    }
}

#endif //SNAKE_GAME_BORDER_H
