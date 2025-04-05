#include <GLUT/glut.h>
#include "Ship.h"
#include <cmath>

Ship::Ship(float x, float y, float width, float height, const Color& color, BulletPool* pool)
    : x(x), y(y), width(width), height(height), color(color), bulletPool(pool) {}

void Ship::draw() const {
    glColor3f(color.r, color.g, color.b);

    // gövde
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + height * 0.5f);                         // üst
    glVertex2f(x - width * 0.3f, y - height * 0.4f);          // sol alt
    glVertex2f(x + width * 0.3f, y - height * 0.4f);          // sağ alt
    glEnd();

    // kokpit
    glColor3f(0.6f, 0.8f, 1.0f); // cam gibi
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex2f(x + cos(rad) * width * 0.15f, y + sin(rad) * height * 0.2f);
    }
    glEnd();

    // Sol kanat (yukarı doğru)
    glColor3f(color.r * 0.8f, color.g * 0.8f, color.b * 0.8f); // biraz koyu
    glBegin(GL_QUADS);
    glVertex2f(x - width * 0.3f, y);
    glVertex2f(x - width * 0.5f, y + height * 0.2f);
    glVertex2f(x - width * 0.4f, y + height * 0.3f);
    glVertex2f(x - width * 0.2f, y + height * 0.1f);
    glEnd();

    // Sağ kanat (yukarı doğru)
    glBegin(GL_QUADS);
    glVertex2f(x + width * 0.3f, y);
    glVertex2f(x + width * 0.5f, y + height * 0.2f);
    glVertex2f(x + width * 0.4f, y + height * 0.3f);
    glVertex2f(x + width * 0.2f, y + height * 0.1f);
    glEnd();

    // ayaklar
    glColor3f(0.3f, 0.3f, 0.3f); // gri
    glBegin(GL_LINES);
    glVertex2f(x - width * 0.15f, y - height * 0.4f);
    glVertex2f(x - width * 0.15f, y - height * 0.55f);

    glVertex2f(x + width * 0.15f, y - height * 0.4f);
    glVertex2f(x + width * 0.15f, y - height * 0.55f);
    glEnd();
}


void Ship::moveLeft() {
    x -= 0.1f;
}

void Ship::moveRight() {
    x += 0.1f;
}

void Ship::shoot() {
    Bullet* bullet = bulletPool->getBullet();
    bullet->activate(leftGunX(), gunY());

    bullet = bulletPool->getBullet();
    bullet->activate(rightGunX(), gunY());
}

float Ship::leftGunX() const{
    return x - width * 0.4f;
}

float Ship::rightGunX() const{
    return x + width * 0.4f;
}

float Ship::gunY() const{
    return y - height * 0.05f;
}
