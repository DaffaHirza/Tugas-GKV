#include <GL/glut.h>
#include <math.h>

float angle = 0.0; // Sudut rotasi roda

// Fungsi untuk menggambar lingkaran (roda & matahari)
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Fungsi untuk menggambar gunung di latar belakang
void drawMountain() {
    glColor3f(0.0, 0.5, 0.0); // Warna hijau gelap untuk gunung

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8, -0.2); // Kiri bawah
    glVertex2f(0.0, 0.9);   // Puncak lancip
    glVertex2f(0.8, -0.2);  // Kanan bawah
    glEnd();
}

// Fungsi untuk menggambar mobil
void drawCar() {
    glPushMatrix();  // Simpan transformasi awal
    
    // Body mobil
    glColor3f(0.0, 0.0, 1.0); // Biru
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, -0.1);
    glVertex2f(0.45, -0.1);
    glVertex2f(0.35, 0.15);
    glVertex2f(-0.3, 0.15);
    glEnd();
    glPopMatrix();

    // Atap mobil
    glPushMatrix();
    glTranslatef(0.1, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.15);
    glVertex2f(0.2, 0.15);
    glVertex2f(0.15, 0.3);
    glVertex2f(-0.2, 0.3);
    glEnd();
    glPopMatrix();
    
    // Antena
    glPushMatrix();
    glTranslatef(-0.1, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.15);
    glVertex2f(0.15, 0.3);
    glVertex2f(0.2, 0.3);
    glEnd();
    glPopMatrix();
    
    // Roda kiri
    glPushMatrix();
    glTranslatef(-0.2, -0.15, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0); // Rotasi roda
    glColor3f(0.0, 0.0, 0.0); // Hitam
    drawCircle(0, 0, 0.08, 20);
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
    glTranslatef(0.25, -0.15, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0); // Rotasi roda
    glColor3f(0.0, 0.0, 0.0); // Hitam
    drawCircle(0, 0, 0.08, 20);
    glPopMatrix();

    glPopMatrix();  
}

// Fungsi untuk menggambar jalan
void drawRoad() {
	glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.5); 
    glVertex2f(1.0, -0.5);  
    glVertex2f(1.0, -0.2);
    glVertex2f(-1.0, -0.2);
    glEnd();
    glPopMatrix();
    
}

// Fungsi untuk menggambar matahari
void drawSun() { 
    glColor3f(1.0, 1.0, 0.0); // Warna kuning
	drawCircle(0.7, 0.7, 0.1, 30);
}

// Fungsi untuk menampilkan semua elemen di layar
void display() {
	
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glPushMatrix();
    glTranslatef(0.0, -0.7, 0.0);
    drawMountain(); 
    drawSun();
    drawRoad();
    drawCar();
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

// Inisialisasi tampilan
void init() {
    glClearColor(0.5, 0.8, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.5, 0.5, -0.3, 0.4);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Mobil 2D dengan OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

