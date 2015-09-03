#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

#define PI 3.14159

double cameraAngle, cameraAngleDelta;
int canDrawGrid;

double cameraHeight;	
double cameraRadius;

double carcentrex=0,carcentrey=0,carcentrez=0;	//for moving whole shape
double speed=0.5;
double wheelPostionx = 0;


void drawCarBase()
{
	glPushMatrix();
	{
		glColor3f(0,0,0.6);
		//............MAIN BASE(Between Wheels).................
		glPushMatrix();
		{
			glScalef(2.5,2.5,.5);
			glTranslatef(0,0,20);
			glutSolidCube(20);
		}
		glPopMatrix();
		//...........Back BASE(Behind back Wheels).................
		glPushMatrix();
		{
			glScalef(.8,2.5,.5);
			glTranslatef(-65,0,20);
			glutSolidCube(20);
	
		}
		glPopMatrix();
		//............Front BASE(Infront of Wheels).................
		glPushMatrix();
		{
			glScalef(1.5,2.5,.5);
			glTranslatef(40,0,20);
			glutSolidCube(20);
		}
		glPopMatrix();
		//............BASE(Between front Wheels).................
		glPushMatrix();
		{

			glScalef(1.4,1.5,.5);
			glTranslatef(25,0,20);
			glutSolidCube(20);
		}
		glPopMatrix();
		//............BASE(Between Back Wheels).................
		glPushMatrix();
		{
			glScalef(1.4,1.5,.5);
			glTranslatef(-25,0,20);
			glutSolidCube(20);
		}
		glPopMatrix();
		//............UPPER BASE PLATE .................
		glPushMatrix();
		{
			
			glTranslatef(-6,0,15);
			glScalef(5.4,2.5,.1);
			glutSolidCube(20);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void drawWheel(double x,double y,double z){
	glPushMatrix();
	{
		glTranslatef(x, y, z);
		glScalef(4,4,4);
		glPushMatrix();{
		
			glRotatef(90,1,0,0);					
			glPushMatrix();{
				glColor3f(0,0,0);				
				//** wheel's Gray outer part **//
				glutSolidTorus(.55,1.8,25,25); 

				//** wheel's inner disc part **//
				glColor3f(.6,.6,.6);
				gluDisk(gluNewQuadric(),0,1.25,100,100);  
				
				//** Loop for drawing lines in inner part of wheel **/
				//inner lines
				glColor3f(.2,.2,.2);
				double i=.25*wheelPostionx;
				while(i<2*PI+.25*wheelPostionx)
				{
					glBegin(GL_LINES);
					{
						glVertex3f(0,0,.1);
						glVertex3f(1.25*cos(i),1.25*sin(i),.1);
					}
					glEnd();
					i+=PI/4;	//distance from one lines to another is 45 degree 
				}

				//outer lines
				i =.25*wheelPostionx;
				while(i<2*PI+.25*wheelPostionx)
				{
					glBegin(GL_LINES);
					{
						glColor3f(.2,.2,.2);
						glVertex3f(0,0,-.1);
						glVertex3f(1.25*cos(i),1.25*sin(i),-.1);
					}
					glEnd();
					i+=PI/4;
				}
			}
			glPopMatrix();
		}glPopMatrix();		
	}
	glPopMatrix();
	
}
void drawCarSide(double x, double y,double z)
{
	glPushMatrix();
	{
		glTranslatef(x,y,z);
		glColor3f(0,0,0.6);

		glPushMatrix();
		{
			//left arm
			glBegin(GL_QUADS);{
				glVertex3f(-5,0,0);
				glVertex3f(5,0,0);
				glVertex3f(10,0,20);
				glVertex3f(5,0,20);
			}glEnd();
			//left upper arm 
			glBegin(GL_QUADS);{
				glVertex3f(8,0,15);
				glVertex3f(35,0,15);
				glVertex3f(35,0,20);
				glVertex3f(10,0,20);
			}glEnd();
			//left bottom arm
			glBegin(GL_QUADS);{
				glVertex3f(5,0,0);
				glVertex3f(6,0,5);
				glVertex3f(35,0,5);
				glVertex3f(35,0,0);
			}glEnd();
			//Middle arm
			glBegin(GL_QUADS);{
				glVertex3f(35,0,0);
				glVertex3f(40,0,0);
				glVertex3f(40,0,20);
				glVertex3f(35,0,20);
			}glEnd();
			//Upper Right arm
			glBegin(GL_QUADS);{
				glVertex3f(40,0,15);
				glVertex3f(40,0,20);
				glVertex3f(65,0,20);
				glVertex3f(70,0,15);
			}glEnd();
			//Right arm
			glBegin(GL_QUADS);{
				glVertex3f(65,0,20);
				glVertex3f(70,0,20);
				glVertex3f(95,0,0);
				glVertex3f(80,0,0);
			}glEnd();
			//Right bottom arm
			glBegin(GL_QUADS);{
				glVertex3f(40,0,0);
				glVertex3f(40,0,5);
				glVertex3f(90,0,5);
				glVertex3f(90,0,0);
			}glEnd();

			//Window Glass
			glPushMatrix();
			{
				glEnable (GL_BLEND);
				glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glColor4f(0,0,0,.6);
				glBegin(GL_QUADS);{
					glVertex3f(6,0,5);
					glVertex3f(8,0,15);
					glVertex3f(35,0,15);
					glVertex3f(35,0,5);
				}glEnd();
				glEnable (GL_BLEND);
				glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glColor4f(0,0,0,.6);
				glBegin(GL_QUADS);{
					glVertex3f(40,0,5);
					glVertex3f(40,0,15);
					glVertex3f(69,0,15);
					glVertex3f(77,0,5);
				}glEnd();

			}
			glPopMatrix();
	
		}
		glPopMatrix();
	}
	glPopMatrix();
}
void drawFrontGlass()
{
		glPushMatrix();
		{
			glRotatef(-51.5,0,1,0);
			glTranslatef(42,-25,-27);
			glPushMatrix();
			{

				glScalef(1,1.19,1.45);
				glRotatef(90,0,0,1);
				//Square frame for Front Glass  
				glPushMatrix();
				{
					glColor3f(0,0,0.6);
					glBegin(GL_QUADS);{
							glVertex3f(0,0,0);
							glVertex3f(0,0,2);
							glVertex3f(40,0,2);
							glVertex3f(40,0,0);
						}glEnd();
					glBegin(GL_QUADS);{
							glVertex3f(0,0,2);
							glVertex3f(2,0,2);
							glVertex3f(2,0,20);
							glVertex3f(0,0,20);
						}glEnd();
					glBegin(GL_QUADS);{
							glVertex3f(0,0,20);
							glVertex3f(0,0,22);
							glVertex3f(40,0,22);
							glVertex3f(40,0,20);
						}glEnd();
					glBegin(GL_QUADS);{
							glVertex3f(40,0,0);
							glVertex3f(42,0,0);
							glVertex3f(42,0,22);
							glVertex3f(40,0,22);
						}glEnd();

					//Front Glass
					glEnable (GL_BLEND);
					glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glColor4f(0,0,1,.5);
					glBegin(GL_QUADS);{
							glVertex3f(2,0,2);
							glVertex3f(40,0,2);
							glVertex3f(40,0,20);
							glVertex3f(2,0,20);
						}glEnd();
				


				}
				glPopMatrix();
	
			}
			glPopMatrix();
		}
		glPopMatrix();

}
void drawBackGlass()
{
		glPushMatrix();
		{
			glRotatef(27,0,1,0);
			glTranslatef(-53.5,-25,-10);
			glPushMatrix();
			{

				glScalef(1,1.11,.93);
				glRotatef(90,0,0,1);
				//Square frame for Black Glass  
				glPushMatrix();
				{
					//Color
					glColor3f(0,0,0.6);
					glBegin(GL_QUADS);{
							glVertex3f(0,0,0);
							glVertex3f(0,0,5);
							glVertex3f(40,0,5);
							glVertex3f(40,0,0);
						}glEnd();
					glBegin(GL_QUADS);{
							glVertex3f(0,0,5);
							glVertex3f(5,0,5);
							glVertex3f(5,0,20);
							glVertex3f(0,0,20);
						}glEnd();
					glBegin(GL_QUADS);{
							glVertex3f(0,0,20);
							glVertex3f(0,0,25);
							glVertex3f(40,0,25);
							glVertex3f(40,0,20);
						}glEnd();
					glBegin(GL_QUADS);{
							glVertex3f(40,0,0);
							glVertex3f(45,0,0);
							glVertex3f(45,0,25);
							glVertex3f(40,0,25);
						}glEnd();

					//Front Glass
					glEnable (GL_BLEND);
					glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glColor4f(1,1,0,.5);
					glBegin(GL_QUADS);{
							glVertex3f(5,0,5);
							glVertex3f(40,0,5);
							glVertex3f(40,0,20);
							glVertex3f(5,0,20);
						}glEnd();
				


				}
				glPopMatrix();
	
			}
			glPopMatrix();
		}
		glPopMatrix();

}
void drawRoof()
{
	glPushMatrix();
	{
		//color
		glColor3f(0,0,0.6);
		glTranslatef(-9.21,-25,26);
		glScalef(1.62,2.5,1);
		glBegin(GL_QUADS);{
				glVertex3f(-20,0,10);
				glVertex3f(20,0,10);
				glVertex3f(20,20,10);
				glVertex3f(-20,20,10);
			}glEnd();
			
	}
	glPopMatrix();
}
void drawBacklight(double x, double y,double z)
{
	glTranslatef(x,y,z);
	glPushMatrix();
	{
		glColor3f(1,0,0);
		glScalef(2.5,2,2.5);
		glBegin(GL_QUADS);
		{	glVertex3f(0,0,0);
			glVertex3f(0,0,2);
			glVertex3f(0,4,2);
			glVertex3f(0,4,0);
		}glEnd();
	}
	glPopMatrix();
}
void drawHeadlight(double x, double y,double z)
{
	glTranslatef(x,y,z);
	glScalef(.5,1,.5);
	glPushMatrix();
	{
		glColor3f(1,1,1);
		glutSolidSphere(5,40,40);
		
	}
	glPopMatrix();
}
void drawSingnallight(double x, double y,double z)
{
	
	glTranslatef(x,y,z);
	glScalef(2,1.2,2.5);
	glPushMatrix();
	{
		glColor3f(1,1,0);
		glBegin(GL_QUADS);
		{	glVertex3f(0,0,0);
			glVertex3f(0,0,2);
			glVertex3f(0,2,2);
			glVertex3f(0,2,0);
		}glEnd();
	}
	glPopMatrix();
}
void drawCar(double x,double y,double z)
{
	glTranslatef(x,y,z);
	glRotatef(90,0,0,1);
	glScalef(.6,.6,.6);
	glPushMatrix();
	{
		
		drawCarBase();
		drawWheel(35,22,5);
		drawWheel(35,-22,5);
		drawWheel(-35,22,5);
		drawWheel(-35,-22,5);
		glPushMatrix();
		{
			drawCarSide(-47,-25,16);
		}
		glPopMatrix();
	
		glPushMatrix();
		{
			drawCarSide(-47, 25,16);
		}
		glPopMatrix();
		drawFrontGlass();
		drawBackGlass();
		glPushMatrix();
		{
			drawRoof();
		}
		glPopMatrix();
		
		glPushMatrix();
		{
			drawBacklight(-60.1,10,8);
		}
		glPopMatrix();
		
		glPushMatrix();
		{
			drawBacklight(-60.1,-18,8);
		}
		glPopMatrix();

		glPushMatrix();
		{
			drawSingnallight(-60.1,18,8);
		}
		glPopMatrix();

		glPushMatrix();
		{
			drawSingnallight(-60.1,-20.5,8);
		}
		glPopMatrix();
		glPushMatrix();
		{
			drawHeadlight(75,-15,10);
		}
		glPopMatrix();
		glPushMatrix();
		{
			drawHeadlight(75,15,10);
		}
		glPopMatrix();
	}
	glPopMatrix();
}
void DrawRoadSide(double x)
{
	glPushMatrix();
	{
		glPushMatrix();
			{
				glColor3f(1,0,0);
				glBegin(GL_QUADS);{
				glVertex3f(-x-2,-150,0);
				glVertex3f(-x+2,-150,0);
				glVertex3f(-x+2,200,0);
				glVertex3f(-x-2,200,0);
				}glEnd();

			}
			glPopMatrix();

			glPushMatrix();
			{
				for(int i=-150; i<200; i=i+50)
				{
					//Lamppost
					glPushMatrix();
					{
						
						glPushMatrix();
						{
							glTranslatef(-x,i,40);
							glEnable (GL_BLEND);
							glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							glColor4f(1,0,0,1);
							glutSolidSphere(1.5,50,50);
							glColor4f(1,1,1,.3);
							glutWireSphere(3,500,500);
		
						}
						glPopMatrix();

						glPushMatrix();
						{
			
								glTranslatef(-x,i,0);
							//gluCylinder(quadric,10,10,30,20,20)
							//(pointer,base radius,top radius, height, slice,stack)
								glColor4f(0,0,0,1);
								GLUquadricObj *quadric;
								quadric = gluNewQuadric();

								gluCylinder(quadric,1,1,40,20,20);
						}
						glPopMatrix();
		
					}
					glPopMatrix();
				}//end for

			}
			glPopMatrix();
	}
	glPopMatrix();
}
void DrawRoadPitch()
{
	//road color
		glPushMatrix();
		{
			//yellow divider
			for(int i=-150;i<200;i=i+20)
			{
				glColor3f(1,1,0);
				glBegin(GL_QUADS);{
					glVertex3f(-1,i,0);
					glVertex3f(1,i,0);
					glVertex3f(1,i+15,0);
					glVertex3f(-1,i+15,0);			
				}glEnd();

			}
		}
		glPopMatrix();
		//road color
		glPushMatrix();
		{
			glTranslatef(0,0,-1);
			glColor3f(.2,.2,.2);
				glBegin(GL_QUADS);{
				glVertex3f(-32,-150,0);
				glVertex3f(32,-150,0);
				glVertex3f(32,200,0);
				glVertex3f(-32,200,0);
				}glEnd();
		}
		glPopMatrix();

}
void DrawRoad()
{
	glPushMatrix();
	{
		glScalef(1,1,.5);
		DrawRoadSide(32.5);
		DrawRoadSide(-32.5);
		DrawRoadPitch();
	}
	glPopMatrix();

}




void display(){
	//codes for Models, Camera
	
	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(.7,.7,.7,0);	//color white
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//clear buffers to preset values

	/***************************
	/ set-up camera (view) here
	****************************/ 
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);		//specify which matrix is the current matrix

	//initialize the matrix
	glLoadIdentity();				//replace the current matrix with the identity matrix [Diagonals have 1, others have 0]

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(0,-150,20,	0,0,0,	0,0,1);
	gluLookAt(cameraRadius*sin(cameraAngle), -cameraRadius*cos(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	
	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/**************************************************
	/ Grid and axes Lines(You can remove them if u want)
	***************************************************/
	// draw the three major AXES
	glBegin(GL_LINES);
		//X axis
		glColor3f(0, 1, 0);	//100% Green
		glVertex3f(-150, 0, 0);
		glVertex3f( 150, 0, 0);
		
		//Y axis
		glColor3f(0, 0, 1);	//100% Blue
		glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0,  150, 0);
		
		//Z axis
		glColor3f(1, 1, 1);	//100% White
		glVertex3f( 0, 0, -150);
		glVertex3f(0, 0, 150);
	glEnd();

	//some gridlines along the field
	int i;
	if(canDrawGrid){
	glColor3f(0.5, 0.5, 0.5);	//grey
		glBegin(GL_LINES);
			for(i=-10;i<=10;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -100, 0);
				glVertex3f(i*10,  100, 0);

				//lines parallel to X-axis
				glVertex3f(-100, i*10, 0);
				glVertex3f( 100, i*10, 0);
			}
		glEnd();
	}
	
	
	


	/****************************
	/ Add your objects from here
	****************************/
	


	DrawRoad();
	glPushMatrix();
	{
		glTranslatef(carcentrex,carcentrey,carcentrez);
		drawCar(0,0,1);
	}
	glPopMatrix();
	
	
	
	

	


	

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Models, Camera
	
	//cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.
	
	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN

}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case 'd':
			if(carcentrex<=20)
			{
				carcentrex+=speed;	
				break;
			}
			else
				break;
				
			

		case 'a':	
			if(carcentrex>=-20)
			{
				carcentrex-=speed;	
				break;
			}
			else
				break;

		case 'w':	
			if(carcentrey<=150)
			{
				carcentrey+=speed;	
				break;
			}
			else
				break;
		
		case 's':	
			if(carcentrey>=-100)
			{
				carcentrey-=speed;	
				break;
			}
			else
				break;

		case '8':	//toggle grids
			canDrawGrid = 1 - canDrawGrid;
			break;
			
		case 'p':	//toggle grids
			cameraAngleDelta = 0;
			break;
		case 'r':	//toggle grids
			cameraAngleDelta = .001;
			break;		

		default:
			break;
	}
}


void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			cameraRadius += 10;
			break;
		case GLUT_KEY_UP:		// up arrow key
			if(cameraRadius > 10)
				cameraRadius -= 10;
			break;

		case GLUT_KEY_RIGHT:
			cameraAngle += 0.01;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle -= 0.01;
			break;

		case GLUT_KEY_PAGE_UP:
			cameraHeight += 10;
			break;
		case GLUT_KEY_PAGE_DOWN:
			cameraHeight -= 10;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				cameraAngleDelta = -cameraAngleDelta;	
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}



void init(){
	//codes for initialization

	cameraAngle = 0;	//angle in radian
	cameraAngleDelta = 0.001;
	canDrawGrid = 1;

	cameraHeight = 50;
	cameraRadius = 150;
	//clear the screen
	glClearColor(0,0,0, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);
	
	//initialize the matrix
	glLoadIdentity();

	/*
		gluPerspective() — set up a perspective projection matrix

		fovy -         Specifies the field of view angle, in degrees, in the y direction.
        aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
        zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
        zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
    */
	
	gluPerspective(70,	1,	0.1,	10000.0);
	
}

int main(int argc, char **argv){
	
	glutInit(&argc,argv);							//initialize the GLUT library
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	
	/*
		glutInitDisplayMode - inits display mode
		GLUT_DOUBLE - allows for display on the double buffer window
		GLUT_RGBA - shows color (Red, green, blue) and an alpha
		GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	

	glutCreateWindow("Some Title");

	init();						//codes for initialization

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL


	return 0;
}
