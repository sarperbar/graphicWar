#include <GLUT//glut.h>
#include "Ship.h"
#include "Color.h"
#include "SquareEnemy.h"
#include "BulletPool.h"

#define NUM_OF_ENEMY 20

Ship* player;
SquareEnemy enemy[NUM_OF_ENEMY];
BulletPool bulletPool(20);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    player->draw(); 
    
    for (int i = 0; i < NUM_OF_ENEMY; i++) {
        enemy[i].draw();
    }

    bulletPool.draw();

    glutSwapBuffers();
}

// Keyboard
void keyboard(unsigned char key, int x, int y) {
    //ive changed the GLUT_KEY_LEFT and GLUT_KEY_RIGHT, because they are defined as d,f button.
    if (key == 'a') player->moveLeft();
    if (key == 'd') player->moveRight();
    glutPostRedisplay();
}


void keyboard2(int key, int, int) {
    float step = 0.3f;
    if (key == GLUT_KEY_LEFT) player->moveLeft();
    if (key == GLUT_KEY_RIGHT) player->moveRight();
    glutPostRedisplay();
}

void timer(int value) {
    glutPostRedisplay();

    static int bulletCounter = 0;
    

    for (int i = 0; i < NUM_OF_ENEMY; i++) {
        enemy[i].update();
    }

    if (bulletCounter % 15 == 0) {
        player->shoot();
        bulletCounter = 0;
    }
    bulletCounter++;

    bulletPool.update();

    glutTimerFunc(1000 / 60, timer, 0);
}

void createShip() {
    Color shipColor = { 1.0f, 0.0f, 0.0f };
    player = new Ship(0.0f, -4.0f, 1.5f, 0.8f, shipColor, &bulletPool);
}

void createSquareEnemies() {
    Color enemyColor = { 0.0f, 0.0f, 1.0f };
    float x = -4.0f;
    float y = 3.0f;
    int i = 0, j = 0;
    for (; i < 2; i++) {
        for (; j < 10 * (i + 1); j++) {
            enemy[j] = SquareEnemy(x, y, 0.5f, enemyColor);
            x += 0.8f;
        }
        y -= 1.2f;
        x = -4.0f;
    }
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(80, 80);
    glutCreateWindow("202011001 Sarper ERBAR");

    createShip();
    createSquareEnemies();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutTimerFunc(1000 / 60, timer, 0);

    glutMainLoop();
    return 0;
}
