#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
  
void animball (void) 
{ 
	int x,y;
    	glClearColor(0.0, 0.0, 0.0, 1.0); 
    	glColor3f(0.0, 1.0, 0.0); 
    	glPointSize(1.0); 
    	glMatrixMode(GL_PROJECTION); 
    	glLoadIdentity(); 
    	gluOrtho2D(-350, 350, -350, 350); 
   	 for (float j = 0; j < 1000; j += 0.01) 
    	{ 
        		glClear(GL_COLOR_BUFFER_BIT); 
        		glBegin(GL_POINTS);          
 			for (int i=0; i <360; i++)
        			{ 
            				x = 100 * cos(i); 
            				y = 100 * sin(i); 
            				glVertex2i(x / 2 - 1 * cos(j), y / 2 - 150* sin(j)); 
        			} 
       		glEnd(); 
        		glFlush(); 
    	} 
} 
  
int main (int argc, char** argv) 
{ 
    	glutInit(&argc, argv); 
    	glutCreateWindow("Animating a ball"); 
    	glutInitWindowSize(1000, 1000); 
    	glutInitWindowPosition(0, 0); 
    	glutDisplayFunc(animball); 
    	glutMainLoop(); 
} 