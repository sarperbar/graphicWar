#include "Enemy.h"

Enemy::Enemy(float x, float y, float size, const Color& color)
    : x(x), y(y), size(size), color(color), isHit(false) {}

float Enemy::getLeft() const {
    return x - size / 2;
}

float Enemy::getRight() const {
    return x + size / 2;
}