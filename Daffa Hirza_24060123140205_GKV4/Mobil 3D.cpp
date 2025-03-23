#include <stdlib.h> // standard definitions  
#include <stdio.h>  // C I/O (for sprintf)  
#include <math.h>   // standard definitions  
#include <GL/glut.h> // GLUT  

// Variabel global untuk rotasi dan pergerakan
double rotAngle = 10; // rotation angle (global)  
double rotAngle1 = 10; // rotation angle (global)  
double deltaAngle = 0.0f;
double deltaMove = 0.0;
double posX = 0.0, posZ = 0.0; // Posisi mobil

// Inisialisasi OpenGL  
void init() {  
  glClearColor(1, 1, 1, 0); // Warna background hitam  
  glClearDepth(1.0); // Background depth value  
  glEnable(GL_DEPTH_TEST); // Aktifkan depth test

  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity();  
  gluPerspective(60, 1, 1, 1000); // Setup perspektif kamera  

  glMatrixMode(GL_MODELVIEW);  
  glLoadIdentity();  
  gluLookAt( // Setup posisi kamera  
        0.0, 2.0, 10.0,  // Posisi mata  
        0.0, 0.0, 0.0,  // Posisi fokus kamera  
        0.0, 1.0, 0.0); // Arah atas  
}  



void drawCar() {
    // Badan mobil
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    glScalef(2.0, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Atap mobil
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1.2, 0.5, 0.8);
    glutSolidCube(1.0);
    glPopMatrix();

    // Roda mobil
    glColor3f(0.0, 0.0, 0.0); // Warna hitam
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            glPushMatrix();
            glTranslatef(i * 0.9, -0.4, j * 0.5);
            glutSolidTorus(0.1, 0.2, 10, 10);
            glPopMatrix();
        }
    }
}

void display() {  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  glPushMatrix(); 
    
    glTranslatef(posX, 0.0, posZ);
    glRotated(rotAngle, 0, 1, 0);  
    glRotated(rotAngle1, 1, 0, 0); 
    
    drawCar(); 

  glPopMatrix(); 
  glFlush(); 
  glutSwapBuffers(); 
}  

void keyboard(unsigned char k, int x, int y) {  
  switch (k) {  
   case 'a':  
     rotAngle += 5; 
     break;  
   case 'w':  
     rotAngle1 += 5; 
     break;  
   case 's':  
     rotAngle1 -= 5; 
     break;  
   case 'd':  
     rotAngle -= 5; 
     break;  
   case 'q':  
    exit(0); 
  }  
  glutPostRedisplay(); 
}  

void pressKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            posX -= 0.5; \
            break;
        case GLUT_KEY_RIGHT:
            posX += 0.5; 
            break;
        case GLUT_KEY_UP:
            posZ -= 0.5; 
            break;
        case GLUT_KEY_DOWN:
            posZ += 0.5; 
            break;
    }
    glutPostRedisplay();
}

int main() {  
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB); 
  glutCreateWindow("Mobil 3D dengan OpenGL");  
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard); 
  glutSpecialFunc(pressKey); 
  init();
  glutMainLoop(); 
  return 0;  
}
