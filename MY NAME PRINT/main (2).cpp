#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

float Txval = 0.0, Tyval = 0.0;
int direction = -1;

void drawLimon()
{
    glLineWidth(15.0);
    glBegin(GL_LINES);

    // L
    glColor3f(1, 0, 0);
    glVertex2f(-5.5, 2); glVertex2f(-5.5, -2);
    glVertex2f(-5.5, -2); glVertex2f(-4.5, -2);

    // I
    glColor3f(0, 1, 0);
    glVertex2f(-4, 2); glVertex2f(-4, -2);

    // M
    glColor3f(0, 0, 1);
    glVertex2f(-3.5, -2); glVertex2f(-3.5, 2);
    glVertex2f(-3.5, 2); glVertex2f(-2.5, 0);
    glVertex2f(-2.5, 0); glVertex2f(-1.5, 2);
    glVertex2f(-1.5, 2); glVertex2f(-1.5, -2);

    // O
    glColor3f(1, 1, 0);
    glVertex2f(-1, -2); glVertex2f(-1, 2);
    glVertex2f(-1, 2); glVertex2f(0, 2);
    glVertex2f(0, 2); glVertex2f(0, -2);
    glVertex2f(0, -2); glVertex2f(-1, -2);

    // N
    glColor3f(1, 0, 1);
    glVertex2f(0.5, -2); glVertex2f(0.5, 2);
    glVertex2f(0.5, 2); glVertex2f(1.5, -2);
    glVertex2f(1.5, -2); glVertex2f(1.5, 2);

    glEnd();
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'r': direction = 0; break;  // Right
        case 'l': direction = 1; break;  // Left
        case 'u': direction = 2; break;  // Up
        case 'd': direction = 3; break;  // Down
        case 's': direction = -1; break; // Stop
        case 'a': direction = -1; Txval = 0.0; Tyval = 0.0; break;
        case 27: exit(0); break;
    }

    glutPostRedisplay();
}


void animate()
{
    if (direction == 0 && Txval < 7) Txval += 0.001;  // Right
    if (direction == 1 && Txval > -7) Txval -= 0.001; // Left
    if (direction == 2 && Tyval < 7) Tyval += 0.001;  // Up
    if (direction == 3 && Tyval > -7) Tyval -= 0.001; // Down

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);

    glPushMatrix();
        glTranslatef(Txval, Tyval, 0);
        drawLimon();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("LIMON Animation");

    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);

    glClearColor(0, 0, 0, 1); // Background black

    glutMainLoop();
    return 0;
}
