#pragma once
#include "Bullet.h"

class BulletPool {
private:
    Bullet* bullets;
    int poolSize;

public:
    BulletPool(int initialSize); 
    ~BulletPool();

    Bullet* getBullet();
    void update();
    void draw() const;
};