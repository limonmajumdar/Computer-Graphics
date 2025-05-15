#include <GL/glut.h>

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
    if (key == 'r') direction = 0;
    else if (key == 'l') direction = 1;
    else if (key == 'u') direction = 2;
    else if (key == 'd') direction = 3;
    else if (key == 's') direction = -1;
    else if (key == 'a') { direction = 0; Txval = 0; Tyval = 0; }
    else if (key == 27) exit(0); // ESC

    glutPostRedisplay();
}

void animate()
{
    if (direction == 0 && Txval < 7.0) Txval += 0.01;
    else if (direction == 1 && Txval > -7.0) Txval -= 0.01;
    else if (direction == 2 && Tyval < 6.0) Tyval += 0.01;
    else if (direction == 3 && Tyval > -6.0) Tyval -= 0.01;

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

