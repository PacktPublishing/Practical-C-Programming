#include <GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

void drawshapes() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   	glClear(GL_COLOR_BUFFER_BIT);        
      	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
   		for (int i=0; i <360; i++)
   		{
      			float angle = i*pi/180;
     			glVertex2f(cos(angle)*0.5,sin(angle)*0.5);
   		}
		glEnd();	
   	glFlush();  
}
 
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 
   	glutCreateWindow("Drawing some shapes"); 
   	glutInitWindowSize(1500, 1500);   
   	glutInitWindowPosition(0, 0); 
   	glutDisplayFunc(drawshapes); 
   	glutMainLoop();          
   	return 0;
}