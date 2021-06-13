//
// Created by Ram on 13-06-2021.
//

#ifndef SNAKE_GAME_GAMEPLAY_H
#define SNAKE_GAME_GAMEPLAY_H

#include <iostream>
#include "Food.h"
#include "Border.h"
#include "snake.h"

class GamePlay {
public:
    GamePlay(int height, int width);
    ~GamePlay() = default;
    void Play();
private:
    int height{};
    int width{};
    Border border{};
    Food food{};
    Snake snake{};
};

GamePlay::GamePlay(int height, int width) : height(height),
                                            width(width),
                                            border(height, width),
                                            food(height, width),
                                            snake(height, width) {}

void GamePlay::Play() {
    Coordinates foodCoord = food.CreateFood();
    Coordinates snakeCoord = snake.CreateSnake();

    while (foodCoord.x == snakeCoord.x || foodCoord.y == snakeCoord.y) {
        foodCoord = food.CreateFood();
        snakeCoord = snake.CreateSnake();
    }
    border.SetBorderCoordinates();

    border.Draw(snakeCoord, foodCoord, 1);
//    std::printf("snake: x: %d, y: %d\n", snakeCoord.x, snakeCoord.y);
//    std::printf("food:  x: %d, y: %d", foodCoord.x, foodCoord.y);
}

#endif //SNAKE_GAME_GAMEPLAY_H
