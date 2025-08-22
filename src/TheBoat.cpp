/**
 * Draw a boat this and control the object using keyboard and mouse.
 *
 * @keyboard: d -> Move Right
 * @keyboard: a -> Move Left
 * @keyboard: s -> Stop
 * @mouse: Left Click -> Increase Speed
 * @mouse: Right Click -> Decrease Speed
 *
 * @author: siMobin
 *
 * @attention: This project is tested by the @author with a custom task. If you have any doubts, please check the link below..
 * @link: https://github.com/siMobin/LearnOpenGL/blob/main/.vscode/tasks.json
 */
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

// Global variables for object position and speed
GLfloat position = 0.0f; // Horizontal position of the boat
GLfloat speed = 0.02f;   // Movement speed

// Function to update the object's position over time
void update(int value)
{
    // Wrap boat around screen
    if (position < -1.5f)
        position = 1.5f;

    if (position > 1.5f)
        position = -1.5f;

    // Move object
    position += speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

/**
 * @brief Draws a circle given its center (cx, cy) and radius
 * @param cx The x-coordinate of the circle's center
 * @param cy The y-coordinate of the circle's center
 * @param r The radius of the circle
 */
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * 3.1416f / 180.0f;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}

/**
 * @brief Displays a boat moving left to right on the screen
 *
 * Renders a boat with a red trapezoidal body, black windows, a mast, and a light blue
 * sail. The boat is drawn on top of a blue water background. The boat moves left to right
 * continuously.
 */
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // background black
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw blue water background
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(position, 0.0f, 0.0f);

    // Draw boat body (red trapezoid, wider and balanced)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, -0.3f);   // top-left
    glVertex2f(0.4f, -0.3f);    // top-right
    glVertex2f(0.25f, -0.50f);  // bottom-right
    glVertex2f(-0.25f, -0.50f); // bottom-left
    glEnd();

    // Draw circle (3 circles evenly spaced as windows)
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-0.2f, -0.4f, 0.03f);
    drawCircle(0.0f, -0.4f, 0.03f);
    drawCircle(0.2f, -0.4f, 0.03f);

    // Draw sail (light blue triangle)
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.35f, -0.25f);
    glVertex2f(0.35f, -0.25f);
    glEnd();

    glPopMatrix();
    glFlush();
}

/**
 * @brief Handles mouse click events.
 *
 * @param[in] button The mouse button that was pressed: one of `GLUT_LEFT_BUTTON`
 *                    or `GLUT_RIGHT_BUTTON`.
 * @param[in] state The state of the mouse button: either `GLUT_UP` or `GLUT_DOWN`.
 * @param[in] x The x-coordinate of the mouse cursor when the button was pressed.
 * @param[in] y The y-coordinate of the mouse cursor when the button was pressed.
 *
 * @details If the left mouse button was pressed, increases the movement speed of
 *          the boat by 0.01f. If the right mouse button was pressed, decreases
 *          the movement speed by 0.01f.
 */
void handleMouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        { // Increase speed
            speed += 0.01f;
        }
        else if (button == GLUT_RIGHT_BUTTON)
        { // Decrease speed
            speed -= 0.01f;
        }
    }
    glutPostRedisplay();
}

/**
 * @brief Handles keyboard press events.
 *
 * @param[in] key The keyboard key that was pressed.
 * @param[in] x The x-coordinate of the mouse cursor when the key was pressed.
 * @param[in] y The y-coordinate of the mouse cursor when the key was pressed.
 *
 * @details If the 's' key was pressed, stops the boat. If the 'd' key was
 *          pressed, moves the boat to the right. If the 'a' key was pressed,
 *          moves the boat to the left.
 */
void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's': // Stop
        speed = 0.0f;
        break;
    case 'd': // Move right
        speed = 0.02f;
        break;
    case 'a': // Move left
        speed = -0.02f;
        break;
    }
    glutPostRedisplay();
}

/**
 * @brief Main Function... Entry point of the program.
 *
 */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 300);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Boat Animation");
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
