/**
 * @version 1.0
 * @author Armando Rodríguez Hdz
 * @Description Modelado 3D de un helicoptero para la materia Intro. Graficación por Computadora
 * como práctica No. 4.
 * 
 **/
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

float rotate_x = -10;
float rotate_y = -10;

// Position of three helixes
float position_helixes[][2] = {{-1, -0.095},
                               {0.45, -0.1},
                               {-0.6, -0.8},
                               {0.09, 0.6},
                               {-0.7, 0.5},
                               {0.2, -0.7}};
// true = add | false = subtract
bool add_helix_0_x = true;
bool add_helix_0_z = false;
bool add_helix_1_x = false;
bool add_helix_1_z = true;

bool add_helix_2_x = true;
bool add_helix_2_z = false;
bool add_helix_3_x = false;
bool add_helix_3_z = true;

bool add_helix_4_x = true;
bool add_helix_4_y = false;
bool add_helix_5_x = true;
bool add_helix_5_y = true;

float rotate_helix11_x = -1;
float rotate_helix11_z = -0.095;
float rotate_helix12_x = 0.45;
float rotate_helix12_z = -0.1;
float rotate_helix21_x = -0.6;
float rotate_helix21_z = -0.8;
float rotate_helix22_x = 0.09;
float rotate_helix22_z = 0.6;
float rotate_helix31_x = -0.7;
float rotate_helix31_z = 0.5;
float rotate_helix32_x = 0.2;
float rotate_helix32_z = -0.7;

/**
 * Dibujado del centro del cuerpo del helicuptero.
 **/
void drawBodyCentral()
{

    // Side front - Gray
    glBegin(GL_POLYGON);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(-0.10, -0.20, -0.23);
    glVertex3f(0.0, 0.0, -0.23);
    glVertex3f(0.0, 0.25, -0.23);
    glVertex3f(-0.50, 0.25, -0.25);
    glVertex3f(-0.65, 0.0, -0.25);
    glVertex3f(-0.50, -0.20, -0.25);
    glEnd();

    // Side back - White
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.10, -0.20, 0.03);
    glVertex3f(0.0, 0.0, 0.03);
    glVertex3f(0.0, 0.25, 0.03);
    glVertex3f(-0.50, 0.25, 0.05);
    glVertex3f(-0.65, 0.0, 0.05);
    glVertex3f(-0.50, -0.20, 0.05);
    glEnd();

    // Side rigth - Purple
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, -0.23);
    glVertex3f(0.0, 0.25, -0.23);
    glVertex3f(0.0, 0.25, 0.03);
    glVertex3f(0.0, 0.0, 0.03);
    glVertex3f(-0.10, -0.20, 0.03);
    glVertex3f(-0.10, -0.20, -0.23);
    glEnd();

    // Side left - Green
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.65, 0.0, 0.05);
    glVertex3f(-0.50, 0.25, 0.05);
    glVertex3f(-0.50, 0.25, -0.25);
    glVertex3f(-0.65, 0.0, -0.25);
    glVertex3f(-0.50, -0.20, -0.25);
    glVertex3f(-0.50, -0.20, 0.05);
    glEnd();

    // Side up - Blue
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.25, 0.03);
    glVertex3f(0.0, 0.25, -0.23);
    glVertex3f(-0.50, 0.25, -0.25);
    glVertex3f(-0.50, 0.25, 0.05);
    glEnd();

    // Side down - Red
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.10, -0.20, -0.23);
    glVertex3f(-0.10, -0.20, 0.03);
    glVertex3f(-0.50, -0.20, 0.05);
    glVertex3f(-0.50, -0.20, -0.25);
    glEnd();
}

/**
 * Dibujado de la parte trasera del helicopero
 **/
void drawTail()
{

    // front - red
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.1, 0.1);
    glVertex3f(0.0, 0.0, -0.23);
    glVertex3f(0.0, 0.25, -0.23);
    glVertex3f(0.6, 0.25, -0.15);
    glVertex3f(0.6, 0.15, -0.15);
    glEnd();

    // back - green
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.7, 0.3);
    glVertex3f(0.0, 0.0, 0.03);
    glVertex3f(0.0, 0.25, 0.03);
    glVertex3f(0.6, 0.25, -0.05);
    glVertex3f(0.6, 0.15, -0.05);
    glEnd();

    // down - purple
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.1, 0.6);
    glVertex3f(0.0, 0.0, -0.23);
    glVertex3f(0.0, 0.0, 0.03);
    glVertex3f(0.6, 0.15, -0.05);
    glVertex3f(0.6, 0.15, -0.15);
    glEnd();

    // up - yellow
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.7, 0.1);
    glVertex3f(0.0, 0.25, -0.23);
    glVertex3f(0.0, 0.25, 0.03);
    glVertex3f(0.6, 0.25, -0.05);
    glVertex3f(0.6, 0.25, -0.15);
    glEnd();

    // Objeto No.3 del pdf
    // front - blue
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.7);
    glVertex3f(0.6, 0.25, -0.15);
    glVertex3f(0.6, 0.15, -0.15);
    glVertex3f(0.75, 0.15, -0.10);
    glVertex3f(0.8, 0.4, -0.10);
    glVertex3f(0.7, 0.4, -0.10);
    glEnd();

    // back -  blue
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.7);
    glVertex3f(0.6, 0.25, -0.05);
    glVertex3f(0.6, 0.15, -0.05);
    glVertex3f(0.75, 0.15, -0.10);
    glVertex3f(0.8, 0.4, -0.10);
    glVertex3f(0.7, 0.4, -0.10);
    glEnd();

    // up - white
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0.6, 0.25, -0.05);
    glVertex3f(0.6, 0.25, -0.15);
    glVertex3f(0.7, 0.4, -0.10);
    glEnd();

    // down - gray
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.6, 0.15, -0.05);
    glVertex3f(0.6, 0.15, -0.15);
    glVertex3f(0.75, 0.15, -0.10);
    glEnd();
}

/**
 *  Dibujado de la base de las hélices 
 **/
void drawHelixBase()
{

    // up - red
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.1, 0.1);
    glVertex3f(-0.15, 0.29, -0.017);
    glVertex3f(-0.15, 0.29, -0.17);
    glVertex3f(-0.35, 0.29, -0.18);
    glVertex3f(-0.35, 0.29, -0.017);
    glEnd();

    // left - white
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-0.35, 0.29, -0.18);
    glVertex3f(-0.35, 0.29, -0.017);
    glVertex3f(-0.38, 0.25, 0.007);
    glVertex3f(-0.38, 0.25, -0.20);
    glEnd();

    // right - purple
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.2, 0.9);
    glVertex3f(-0.15, 0.29, -0.18);
    glVertex3f(-0.15, 0.29, -0.017);
    glVertex3f(-0.12, 0.25, 0.01);
    glVertex3f(-0.12, 0.25, -0.19);
    glEnd();

    // back - green
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.9, 0.2);
    glVertex3f(-0.35, 0.29, -0.017);
    glVertex3f(-0.38, 0.25, 0.007);
    glVertex3f(-0.12, 0.25, 0.007);
    glVertex3f(-0.15, 0.29, -0.017);
    glEnd();

    // front - yellow
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.6, 0.0);
    glVertex3f(-0.15, 0.29, -0.17);
    glVertex3f(-0.35, 0.29, -0.18);
    glVertex3f(-0.38, 0.25, -0.20);
    glVertex3f(-0.12, 0.25, -0.19);
    glEnd();
}

/**
 * Dibujado de las hélices con un cilindro en el centro.
 */
void drawHelixes()
{

    // Cilindro central
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j < 360; j += 1)
    {
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f((cos(j) / 24) - 0.25, 0.20, (sin(j) / 24) - 0.1);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f((cos(j) / 24) - 0.25, 0.35, (sin(j) / 24) - 0.1);
    }
    glEnd();
    for (int i = 0; i >= -1; i -= 2)
    {
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0, 0.0, 0.1);
        //glVertex3f(-0.80, i/24, 0.0);
        for (int k = 0; k < 360; k += 1)
        {
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f((i * cos(k) / 24) - 0.25, i, (sin(k) / 24) - 0.1);
        }
        glEnd();
    }

    glTranslatef(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(position_helixes[0][0], 0.32, position_helixes[0][1]); // helice1
    glVertex3f(position_helixes[1][0], 0.32, position_helixes[1][1]);
    glVertex3f(position_helixes[2][0], 0.32, position_helixes[2][1]); // helice2
    glVertex3f(position_helixes[3][0], 0.32, position_helixes[3][1]);
    glVertex3f(position_helixes[4][0], 0.32, position_helixes[4][1]); // helice3
    glVertex3f(position_helixes[5][0], 0.32, position_helixes[5][1]);
    glEnd();

    //TODO: girar Hélices
    /*for (int i = 0; i < 6; i++)
    {
        if (i == 0) // helice1
        {
            if(add_helix_0_x)
                position_helixes[0][0] +=0.01;
            else
                position_helixes[0][0] -=0.01;
            if(position_helixes[0][0] <= -1)
                add_helix_0_x = true;
            if(position_helixes[0][0] >= 0.45)
                add_helix_0_x = false;
            if(add_helix_0_z)
                position_helixes[0][1] += 0.01;
            else
                position_helixes[0][1] -= 0.01;    
            if(position_helixes[0][1] <= -0.9)
                add_helix_0_z = true;
            if(position_helixes[0][1] >= 0.75)
                add_helix_0_z = false;       

            if(add_helix_1_x)
                position_helixes[1][0] +=0.01;
            else
                position_helixes[1][0] -=0.01;
            if(position_helixes[1][0] <= -1)
                add_helix_0_x = true;
            if(position_helixes[1][0] >= 0.45)
                add_helix_0_x = false;
            if(add_helix_0_z)
                position_helixes[1][1] += 0.01;
            else
                position_helixes[1][1] -= 0.01;    
            if(position_helixes[1][1] <= -0.9)
                add_helix_0_z = true;
            if(position_helixes[1][1] >= 0.75)
                add_helix_0_z = false;       

        }
        else if (i == 2) // helice2
        {
        }
        else if (i == 4) // helice3
        {
        }
    }*/
}

void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar cuando el usuario cambie “rotate_x” y “rotate_y”
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    drawBodyCentral();
    drawTail();
    drawHelixBase();
    drawHelixes();

    glutPostRedisplay();

    glFlush();
    glutSwapBuffers();
}

void KeyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        rotate_x += 5;
        break;
    case 'W':
        rotate_x += 5;
        break;
    case 's':
        rotate_x -= 5;
        break;
    case 'S':
        rotate_x -= 5;
        break;
    case 'a':
        rotate_y += 5;
        break;
    case 'A':
        rotate_y += 5;
        break;
    case 'd':
        rotate_y -= 5;
        break;
    case 'D':
        rotate_y -= 5;
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void interactionDescription()
{
    cout << "Press w/s/a/d to rotate the helicopter." << endl;
    cout << "Press [Escape] to exit" << endl;
}

int main(int argc, char *argv[])
{
    interactionDescription();
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc, argv);
    //  Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Helicopter");
    //  Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(KeyInput);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
