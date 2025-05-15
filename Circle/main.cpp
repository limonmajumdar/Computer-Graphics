#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void circle() {
    float radius = 5.0;
    int numSegments = 25;  // Lower value = less smooth but simpler

    glBegin(GL_POLYGON);  // Draw a filled circle
    glColor3f(1.0, 1.0, 0.0); // Yellow
    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * M_PI * i / numSegments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    circle();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Circle");

    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
