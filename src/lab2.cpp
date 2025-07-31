/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display()
{
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.f);
    //
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.f);
    //
    glEnd();
    // dot
    glPointSize(5.0);
    glBegin(GL_POINTS);

    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.0f);
    //
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(-.5f, 0.5f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.2f, 0.5f);
    //
    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2f(0.8f, -0.4f);
    glVertex2f(0.95f, -0.5f);
    glVertex2f(0.95f, -0.7f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.65f, -0.7f);
    glVertex2f(0.65f, -0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("GLUT Shapes");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);

    // glutReshapeFunc(resize);
    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
