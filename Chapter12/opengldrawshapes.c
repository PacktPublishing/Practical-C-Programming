#include <GL/glut.h> 

void drawshapes() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   	glClear(GL_COLOR_BUFFER_BIT);        

   	glBegin(GL_QUADS);             
      		glColor3f(0.0f, 0.0f, 1.0f);
     		glVertex2f(0.0f, 0.0f);    
      		glVertex2f( 0.0f, .75f);
      		glVertex2f( -.75f,  .75f);
      		glVertex2f(-.75f,  0.0f);
   	glEnd();
	glLineWidth(2.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
  		glVertex2f(-.25f, -0.25f); 
  		glVertex2f(0.25f, -0.25f); 
	glEnd(); 
   	glBegin(GL_TRIANGLES);
    		glColor3f( 0, 1, 0 );
    		glVertex2f( 0,0 );
    		glVertex2f( .5,.5 );
    		glVertex2f( 1,0);
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