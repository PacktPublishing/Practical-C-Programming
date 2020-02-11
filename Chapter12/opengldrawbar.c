#include <GL/glut.h>

void display(){
    	float x,y,width, result[] = {10.0, 15.0, 5.0};
    	int i, barCount = 3;
    	x=1.0;
	y = 0.0;
	width = 2.0;
    	glColor3f(1.0, 0.0, 0.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);
    	gluOrtho2D(-5, 20, -5, 20); 
    	glBegin(GL_LINES);
        		glVertex2f(-30, 0.0);
        		glVertex2f(30, 0.0);
        		glVertex2f(0.0, -30);
        		glVertex2f(0.0, 30);
    	glEnd();
    	for(i=0; i<barCount; i++){
        		x = (i * width) + i + 1;
		glBegin(GL_POLYGON);
        			glVertex2f(x, y);
        			glVertex2f(x, y+result[i]);
        			glVertex2f(x+width, y+result[i]);
        			glVertex2f(x+width, y);
    		glEnd();
    	}
    	glFlush();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
    	glutInitWindowPosition(0, 0);
    	glutInitWindowSize(500, 500);
    	glutCreateWindow("Drawing Bar Chart");
    	glutDisplayFunc(display);
    	glutMainLoop();
    	return 0;
}