#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

int windowWidth = 800, windowHeight = 600;
float Txval = 0, Tyval = 0;
int direction = -1;

void drawLimon()
{
    glLineWidth(20.0); // Thicker lines
    glBegin(GL_LINES);

    // L
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-9, 4);
    glVertex2f(-9, -4);
    glVertex2f(-9, -4);
    glVertex2f(-7, -4);

    // I
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-6, 4);
    glVertex2f(-6, -4);

    // M
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-5, -4);
    glVertex2f(-5, 4);
    glVertex2f(-5, 4);
    glVertex2f(-3, 0);
    glVertex2f(-3, 0);
    glVertex2f(-1, 4);
    glVertex2f(-1, 4);
    glVertex2f(-1, -4);

    // O
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0, -4);
    glVertex2f(0, 4);
    glVertex2f(0, 4);
    glVertex2f(2, 4);
    glVertex2f(2, 4);
    glVertex2f(2, -4);
    glVertex2f(2, -4);
    glVertex2f(0, -4);

    // N
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(3, -4);
    glVertex2f(3, 4);
    glVertex2f(3, 4);
    glVertex2f(6, -4);
    glVertex2f(6, -4);
    glVertex2f(6, 4);

    glEnd();
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'r': direction = 0; break;
        case 'l': direction = 1; break;
        case 'u': direction = 2; break;
        case 'd': direction = 3; break;
        case 's': direction = -1; break;
        case 'a': direction = -1; Txval = 0; Tyval = 0; break;
        case 27: exit(1);
    }
    glutPostRedisplay();
}

void animate()
{
    if (direction == 0) Txval += 0.01;
    else if (direction == 1) Txval -= 0.01;
    else if (direction == 2) Tyval += 0.01;
    else if (direction == 3) Tyval -= 0.01;
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, windowWidth, windowHeight);

    glPushMatrix();
        glTranslatef(Txval, Tyval, 0);
        drawLimon();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(500, 100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("LIMON Animation");

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);

    glutMainLoop();
    return 0;
}
