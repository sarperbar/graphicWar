#include "BulletPool.h"

BulletPool::BulletPool(int initialSize) {
    poolSize = initialSize;
    bullets = new Bullet[poolSize];
}

BulletPool::~BulletPool() {
    delete[] bullets;
}

Bullet* BulletPool::getBullet() {
    for (int i = 0; i < poolSize; i++) {
        if (!bullets[i].isActive()) {
            return &bullets[i]; 
        }
    }
    return nullptr;
}

void BulletPool::update() {
    for (int i = 0; i < poolSize; i++) {
        if (bullets[i].isActive()) {
            bullets[i].update();
        }
    }
}

void BulletPool::draw() const {
    for (int i = 0; i < poolSize; i++) {
        if (bullets[i].isActive()) {
            bullets[i].draw();
        }
    }
}
