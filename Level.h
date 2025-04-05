#pragma once
#include "SquareEnemy.h"
#include <vector>
#include <memory>

class Level {
private:
    std::vector<std::unique_ptr<Enemy>> enemies;
    float enemySpeed;

public:
    Level();
    void spawnEnemies();
    void update();
    void draw() const;

    std::vector<std::unique_ptr<Enemy>>& getEnemies();
};
