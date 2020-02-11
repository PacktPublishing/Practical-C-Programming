#include <GL/glut.h>

int noOfClicks = 0;
int coord[2][2];
int leftPressed = 0;

void drawLine(void)
{
  	glClearColor(0.0, 0.0, 0.0, 1.0);  
	glClear(GL_COLOR_BUFFER_BIT);
   	glBegin(GL_LINES);
   	for(int i=0; i<noOfClicks; i++) {
      		glVertex2f(coord[i][0],coord[i][1]);
   	}
   	glEnd();
  	glutSwapBuffers();
}

void projection(int width, int height)
{
	glViewport(0, 0, width, height);
  	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
  	gluOrtho2D(0, width, height, 0);
  	glMatrixMode(GL_MODELVIEW);
}

void mouseEvents(int button, int state, int x, int y)
{
	switch (button) {
    		case GLUT_LEFT_BUTTON:
   			if (state == GLUT_DOWN) {
            				leftPressed = 1;
        			} 
        			if (state == GLUT_UP) {
            				if(leftPressed) {
                				coord[noOfClicks][0]=x;
                				coord[noOfClicks][1]=y;
                				noOfClicks++;
                				leftPressed = 0;
            				}
            				glutIdleFunc(NULL);
        			}
        			break;
    		default:
        			break; 
    	}
    	drawLine();
}

int main(int argc, char **argv)
{
  	glutInit(&argc, argv);
  	glutInitWindowSize(1000, 1000);
  	glutCreateWindow("Displaying lines between two mouse clicks");
  	glutDisplayFunc(drawLine);
  	glutReshapeFunc(projection);
  	glutMouseFunc(mouseEvents);
  	glutMainLoop();
  	return 0;            
}