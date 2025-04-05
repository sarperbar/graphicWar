#include <GLUT//glut.h>
#include "SquareEnemy.h"

SquareEnemy::SquareEnemy(float x, float y, float size, const Color& color)
    : Enemy(x, y, size, color) {}

void SquareEnemy::update() {
    static float speed = 0.015f;

    x += speed;

    if (x + size / 2 >= 5.0f || x - size / 2 <= -5.0f) {
        speed = -speed;
    }
}

void SquareEnemy::draw() const {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    glVertex2f(x - size / 2, y - size / 2);
    glVertex2f(x + size / 2, y - size / 2);
    glVertex2f(x + size / 2, y + size / 2);
    glVertex2f(x - size / 2, y + size / 2);
    glEnd();
}

bool SquareEnemy::isDestroyed() const {
    return isHit;
}
