#include <iostream>
#include "Border.h"
#include "Food.h"
#include "GamePlay.h"

int main() {
    int height = 50, width = 75;
//    Border b(height, width);
//    b.Draw();
//    Food f(height, width);
//    auto [x, y] = f.CreateFood();
//    std::cout << x << " " << y << std::endl;
    GamePlay gp(height, width);
    gp.Play();

    return 0;
}
