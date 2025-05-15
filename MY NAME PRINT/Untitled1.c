
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float Txval = 0.0, Tyval = 0.0, Tzval = 0.0;
float Sval = 1.0;
float Rval = 0.0;

void cube() {
    glutSolidCube(1);
}

void drawL() {
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.4, 0);
    glScalef(0.6, 0.2, 0.2);
    cube();
    glPopMatrix();
}

void drawI() {
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();
}

void drawM() {
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, 0.2, 0);
    glRotatef(-45, 0, 0, 1);
    glScalef(0.2, 0.6, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8, 0.2, 0);
    glRotatef(45, 0, 0, 1);
    glScalef(0.2, 0.6, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2, 0, 0);
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();
}

void drawO() {
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0);
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.4, 0);
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0.9, 0);
    glScalef(0.6, 0.2, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, -0.1, 0);
    glScalef(0.6, 0.2, 0.2);
    cube();
    glPopMatrix();
}

void drawN() {
    glPushMatrix();
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.0, 0);
    glScalef(0.2, 1.0, 0.2);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0.0, 0);
    glRotatef(-45, 0, 0, 1);
    glScalef(0.2, 1.1, 0.2);
    cube();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

    glPushMatrix();
    glTranslatef(-5.0, 0.0, 0.0);
    drawL();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.5, 0.0, 0.0);
    drawI();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    drawM();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5, 0.0, 0.0);
    drawO();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.0, 0.0, 0.0);
    drawN();
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("LIMON in 3D Cubes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

