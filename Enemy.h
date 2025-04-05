#pragma once
#include "Color.h"

class Enemy {
protected:
    float x, y;
    float size;
    Color color;
    bool isHit;

public:
    Enemy(){}
    Enemy(float x, float y, float size, const Color& color);
    virtual ~Enemy() = default;

    virtual void update() = 0;
    virtual void draw() const = 0;
    virtual bool isDestroyed() const = 0;

    //virtual void hit();

    float getLeft() const;
    float getRight() const;
    float getTop() const;
    float getBottom() const;
};
