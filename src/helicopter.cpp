/**
 * @author Armando Rodríguez
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

void display();
void specialKeys();

double rotate_y = 0;
double rotate_x = 0;





/**
 * DIbujado del entro del cuerpo del helicuptero.
 **/
void drawBodyCentral(){
    
    
    //Side front - Gray
    glBegin(GL_POLYGON);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(-0.10, -0.25, -0.25); 
    glVertex3f(0.0, 0.0, -0.25); 
    glVertex3f(0.0, 0.25, -0.25); 
    glVertex3f(-0.50, 0.25, -0.25); 
    glVertex3f(-0.65, 0.0, -0.25);
    glVertex3f(-0.50, -0.25, -0.25); 
    glEnd();

    //Side back - White
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.10, -0.25, 0.10);
    glVertex3f(0.0, 0.0, 0.10);
    glVertex3f(0.0, 0.25, 0.10);
    glVertex3f(-0.50, 0.25, 0.10);
    glVertex3f(-0.65, 0.0, 0.10);
    glVertex3f(-0.50, -0.25, 0.10);
    glEnd();

    //Side rigth - Purple 
    // --------------------------------------
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0); 
    glVertex3f(0.0, 0.0, -0.25);
    glVertex3f(0.0, 0.25, -0.25);
    glVertex3f(0.0, 0.25, 0.10);
    glVertex3f(0.0, 0.0, 0.10);
    glVertex3f(-0.10, -0.25, 0.10);
    glVertex3f(-0.10, -0.25, -0.25);
    glEnd();

    //Side left - Green
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    // 2 nuevos vertices
    glVertex3f(-0.65, 0.0, 0.10);
    glVertex3f(-0.50, 0.25, 0.10);
    glVertex3f(-0.50, 0.25, -0.25);
    // 2 nuevos vertices
    glVertex3f(-0.65, 0.0, -0.25);
    glVertex3f(-0.50, -0.25, -0.25);
    glVertex3f(-0.50, -0.25, 0.10);
    glEnd();

    //Side up - Blue
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.25, 0.10);
    glVertex3f(0.0, 0.25, -0.25);
    glVertex3f(-0.50, 0.25, -0.25);
    glVertex3f(-0.50, 0.25, 0.10);
    glEnd();

    //Side down - Red
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.10, -0.25, -0.25);
    glVertex3f(-0.10, -0.25, 0.10);
    glVertex3f(-0.50, -0.25, 0.10);
    glVertex3f(-0.50, -0.25, -0.25);
    glEnd();

    
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
    case 's':
        rotate_x -= 5;
        break;
    case 'a':
        rotate_y += 5;
        break;
    case 'd':
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


void interactionDescription(){
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
