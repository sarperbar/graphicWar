#include "Bullet.h"
#include <GLUT//glut.h>

Bullet::Bullet() : x(0), y(0), speed(0.1f), length(0.5f), animAlpha(1.0f), active(false) {}

void Bullet::activate(float startX, float startY) {
    x = startX;
    y = startY;
    active = true;
}

void Bullet::update() {
    if (active) {
        y += speed;

        //Bullet Effect
        animAlpha += 0.05f;
        if (animAlpha > 1.0f) 
            animAlpha = 0.5f;

        if (isOffScreen()) {
            deactivate();
        }
    }
}

void Bullet::draw() const {
    if (!active) return;

    //Bullet Effect
    glColor4f(1.0f - 0.5f * animAlpha, 1.0f - 0.8f * animAlpha, 0.5f + 0.5f * animAlpha, 1.0f);

    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y + length);
    glEnd();
}

void Bullet::deactivate() {
    active = false;
}

bool Bullet::isActive() const {
    return active;
}

bool Bullet::isOffScreen() const {
    return y > 5.0f;
}

float Bullet::getX() const {
    return x;
}

float Bullet::getY() const {
    return y;
}
