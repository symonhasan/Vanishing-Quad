/*
    author: s y m o n h a s a n
    date: 01 / 09 / 2019
*/
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

bool def_box = false;
double ObjX[ 105 ][ 5 ], ObjY[ 105 ][ 5 ];
double gR = 239/255.0, gG = 241/255.0, gB = 243/255.0;    // background color
double tx = 0.0, ty = 0.0 ;
double theta = 45, temp;
double ObjColor[ 105 ][ 4 ];
double oR = 244 / 255.0, oG = 43 / 255.0, oB = 3 / 255.0 ;
bool mark[ 105 ];
int score;
clock_t t1, t2;
char name[ 100 ];
int finish;

void _Init_Obj()
{
    for( int i = 1; i<= 80; i++ )
    {
        ObjColor[ i ][ 1 ] = oR;
        ObjColor[ i ][ 2 ] = oG;
        ObjColor[ i ][ 3 ] = oB;
    }

                        /* Object in 1st Quad */

    for(int i = 1; i <= 20; i++ )
    {
        int a = rand() % 85;
        int b = rand() % 85;

        double ax = a / 100.0, ay = b / 100.0;

        ObjX[ i ][ 1 ] = ax, ObjY[ i ][ 1 ] = ay;
        ObjX[ i ][ 2 ] = ax + .10, ObjY[ i ][ 2 ] = ay;
        ObjX[ i ][ 3 ] = ax + .10, ObjY[ i ][ 3 ] = ay + .10;
        ObjX[ i ][ 4 ] = ax, ObjY[ i ][ 4 ] = ay + .10;
    }


    for(int i = 1; i <= 20; i++ )
    {
        int flag = 0;
        for( int j = 1; j <= 20; j++ )
        {
            if( i != j )
            {

                double max_x = max( max( max( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double min_x = min( min( min( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double max_y = max( max( max( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );
                double min_y = min( min( min( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );

                if( ObjX[ i ][ 1 ] >= min_x && ObjX[ i ][ 1 ] <= max_x && ObjY[ i ][ 1 ] >= min_y && ObjY[ i ][ 1 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 2 ] >= min_x && ObjX[ i ][ 2 ] <= max_x && ObjY[ i ][ 2 ] >= min_y && ObjY[ i ][ 2 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 3 ] >= min_x && ObjX[ i ][ 3 ] <= max_x && ObjY[ i ][ 3 ] >= min_y && ObjY[ i ][ 3 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 4 ] >= min_x && ObjX[ i ][ 4 ] <= max_x && ObjY[ i ][ 4 ] >= min_y && ObjY[ i ][ 4 ] <= max_y)
                    flag = 1;

                if( flag == 1 )
                {
                    ObjColor[ i ][ 1 ] = gR;
                    ObjColor[ i ][ 2 ] = gG;
                    ObjColor[ i ][ 3 ] = gB;
                    mark[ i ] = 1;
                    finish++;
                    break;
                }
            }
            if( flag )
                break;
        }
    }

                            /* Objects in 2nd Quad */

    for(int i = 21; i <= 40; i++ )
    {
        int a = rand() % 85;
        int b = rand() % 85;

        double ax = a / 100.0, ay = b / 100.0;

        ax *= -1;

        ObjX[ i ][ 1 ] = ax, ObjY[ i ][ 1 ] = ay;
        ObjX[ i ][ 2 ] = ax + .10, ObjY[ i ][ 2 ] = ay;
        ObjX[ i ][ 3 ] = ax + .10, ObjY[ i ][ 3 ] = ay + .10;
        ObjX[ i ][ 4 ] = ax, ObjY[ i ][ 4 ] = ay + .10;
    }

    for(int i = 21; i <= 40; i++ )
    {
        int flag = 0;
        for( int j = 21; j <= 40; j++ )
        {
            if( i != j )
            {

                double max_x = max( max( max( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double min_x = min( min( min( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double max_y = max( max( max( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );
                double min_y = min( min( min( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );

                if( ObjX[ i ][ 1 ] >= min_x && ObjX[ i ][ 1 ] <= max_x && ObjY[ i ][ 1 ] >= min_y && ObjY[ i ][ 1 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 2 ] >= min_x && ObjX[ i ][ 2 ] <= max_x && ObjY[ i ][ 2 ] >= min_y && ObjY[ i ][ 2 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 3 ] >= min_x && ObjX[ i ][ 3 ] <= max_x && ObjY[ i ][ 3 ] >= min_y && ObjY[ i ][ 3 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 4 ] >= min_x && ObjX[ i ][ 4 ] <= max_x && ObjY[ i ][ 4 ] >= min_y && ObjY[ i ][ 4 ] <= max_y)
                    flag = 1;

                if( flag == 1 )
                {
                    ObjColor[ i ][ 1 ] = gR;
                    ObjColor[ i ][ 2 ] = gG;
                    ObjColor[ i ][ 3 ] = gB;
                    mark[ i ] = 1;
                    finish++;
                    break;
                }
            }
            if( flag )
                break;
        }
    }

                        /* Objects in 3rd Quad */

    for(int i = 41; i <= 60; i++ )
    {
        int a = rand() % 85;
        int b = rand() % 85;

        double ax = a / 100.0, ay = b / 100.0;
        ax *= -1;
        ay *= -1;
        ObjX[ i ][ 1 ] = ax, ObjY[ i ][ 1 ] = ay;
        ObjX[ i ][ 2 ] = ax + .10, ObjY[ i ][ 2 ] = ay;
        ObjX[ i ][ 3 ] = ax + .10, ObjY[ i ][ 3 ] = ay + .10;
        ObjX[ i ][ 4 ] = ax, ObjY[ i ][ 4 ] = ay + .10;
    }

    for(int i = 41; i <= 60; i++ )
    {
        int flag = 0;
        for( int j = 41; j <= 60; j++ )
        {
            if( i != j )
            {

                double max_x = max( max( max( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double min_x = min( min( min( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double max_y = max( max( max( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );
                double min_y = min( min( min( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );

                if( ObjX[ i ][ 1 ] >= min_x && ObjX[ i ][ 1 ] <= max_x && ObjY[ i ][ 1 ] >= min_y && ObjY[ i ][ 1 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 2 ] >= min_x && ObjX[ i ][ 2 ] <= max_x && ObjY[ i ][ 2 ] >= min_y && ObjY[ i ][ 2 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 3 ] >= min_x && ObjX[ i ][ 3 ] <= max_x && ObjY[ i ][ 3 ] >= min_y && ObjY[ i ][ 3 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 4 ] >= min_x && ObjX[ i ][ 4 ] <= max_x && ObjY[ i ][ 4 ] >= min_y && ObjY[ i ][ 4 ] <= max_y)
                    flag = 1;

                if( flag == 1 )
                {
                    ObjColor[ i ][ 1 ] = gR;
                    ObjColor[ i ][ 2 ] = gG;
                    ObjColor[ i ][ 3 ] = gB;
                    mark[ i ] = 1;
                    finish++;
                    break;
                }
            }
            if( flag )
                break;
        }
    }

                                    /* Objects in 4th Quad */

    for(int i = 61; i <= 80; i++ )
    {
        int a = rand() % 85;
        int b = rand() % 85;

        double ax = a / 100.0, ay = b / 100.0;

        ay *= -1;

        ObjX[ i ][ 1 ] = ax, ObjY[ i ][ 1 ] = ay;
        ObjX[ i ][ 2 ] = ax + .10, ObjY[ i ][ 2 ] = ay;
        ObjX[ i ][ 3 ] = ax + .10, ObjY[ i ][ 3 ] = ay + .10;
        ObjX[ i ][ 4 ] = ax, ObjY[ i ][ 4 ] = ay + .10;
    }

    for(int i = 61; i <= 80; i++ )
    {
        int flag = 0;
        for( int j = 61; j <= 80; j++ )
        {
            if( i != j )
            {

                double max_x = max( max( max( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double min_x = min( min( min( ObjX[ j ][ 1 ], ObjX[ j ][ 2 ] ), ObjX[ j ][ 3 ] ), ObjX[ j ][ 4 ] );
                double max_y = max( max( max( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );
                double min_y = min( min( min( ObjY[ j ][ 1 ], ObjY[ j ][ 2 ] ), ObjY[ j ][ 3 ] ), ObjY[ j ][ 4 ] );

                if( ObjX[ i ][ 1 ] >= min_x && ObjX[ i ][ 1 ] <= max_x && ObjY[ i ][ 1 ] >= min_y && ObjY[ i ][ 1 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 2 ] >= min_x && ObjX[ i ][ 2 ] <= max_x && ObjY[ i ][ 2 ] >= min_y && ObjY[ i ][ 2 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 3 ] >= min_x && ObjX[ i ][ 3 ] <= max_x && ObjY[ i ][ 3 ] >= min_y && ObjY[ i ][ 3 ] <= max_y)
                    flag = 1;
                else if( ObjX[ i ][ 4 ] >= min_x && ObjX[ i ][ 4 ] <= max_x && ObjY[ i ][ 4 ] >= min_y && ObjY[ i ][ 4 ] <= max_y)
                    flag = 1;

                if( flag == 1 )
                {
                    ObjColor[ i ][ 1 ] = gR;
                    ObjColor[ i ][ 2 ] = gG;
                    ObjColor[ i ][ 3 ] = gB;
                    mark[ i ] = 1;
                    finish++;
                    break;
                }
            }
            if( flag )
                break;
        }
    }
}

void Check()
{
    for( int i = 1 ; i<= 80; i++ )
    {
        double max_x = max( max( max( ObjX[ i ][ 1 ], ObjX[ i ][ 2 ] ), ObjX[ i ][ 3 ] ), ObjX[ i ][ 4 ] );
        double min_x = min( min( min( ObjX[ i ][ 1 ], ObjX[ i ][ 2 ] ), ObjX[ i ][ 3 ] ), ObjX[ i ][ 4 ] );
        double max_y = max( max( max( ObjY[ i ][ 1 ], ObjY[ i ][ 2 ] ), ObjY[ i ][ 3 ] ), ObjY[ i ][ 4 ] );
        double min_y = min( min( min( ObjY[ i ][ 1 ], ObjY[ i ][ 2 ] ), ObjY[ i ][ 3 ] ), ObjY[ i ][ 4 ] );

        for( int k = 1; k <= 4; k++ )
        {
            if( ObjX[ 0 ][ k ] + tx >= min_x && ObjX[ 0 ][ k ] + tx <= max_x && ObjY[ 0 ][ k ] + ty >= min_y && ObjY[ 0 ][ k ] + ty <= max_y )
            {
                ObjColor[ i ][ 1 ] = gR ;
                ObjColor[ i ][ 2 ] = gG ;
                ObjColor[ i ][ 3 ] = gB ;
                if( mark[ i ] == 0 )
                {
                    score++;
                    mark[ i ] = 1;
                    finish++;
                }
            }
        }
    }
    glutPostRedisplay();
}

void DEF_BOX()   // co-ordinate of green quad
{
    ObjX[ 0 ][ 1 ] = -0.05 ;
    ObjX[ 0 ][ 4 ] = -0.05, ObjX[ 0 ][ 2 ] = 0.05, ObjX[ 0 ][ 3 ] = 0.05;
    ObjY[ 0 ][ 1 ] = ObjY[ 0 ][ 2 ] = 0.05, ObjY[ 0 ][ 3 ] = ObjY[ 0 ][ 4 ] = -0.05;
}

void drawString ( void *font, float x, float y, char *str )
{
    char *ch;
    glRasterPos3f( x, y, 0.0 );
    for( ch = str; *ch; ch++ )
        glutBitmapCharacter( font, (int)*ch );
}

static void display(void)
{
    if( !def_box )
    {
        // initialize object's position
        def_box = true;
        DEF_BOX();
        t1 = clock();
        _Init_Obj();
    }
    if( finish == 80 )   // wining
    {
        glClear( GL_COLOR_BUFFER_BIT );
        glLoadIdentity();
        glViewport( 0, 0, 900, 500 );
        glClearColor( 1, 1, 1, 1);
        char str[ 100 ], str1[ 100 ];
        glColor3f( 231/255.0, 14/255.0, 2/255.0 );
        drawString( GLUT_BITMAP_TIMES_ROMAN_24, -0.5, 0.5, "Congratulations!");
        drawString( GLUT_BITMAP_HELVETICA_18, -0.5, 0, "Your Score : ");
        drawString( GLUT_BITMAP_HELVETICA_18, -0.5, -0.20, "Total Time : ");
        drawString( GLUT_BITMAP_HELVETICA_18, -0.5, -0.5, "Press y To Play Again");
        gcvt( score, 4, str );
        glColor3f( 0 , 0 , 0);
        drawString( GLUT_BITMAP_HELVETICA_18, -0.2, 0, str);
        double diff = ( double )t2 - (double)t1;
        diff /= CLOCKS_PER_SEC;
        gcvt( diff, 4, str1 );
        drawString( GLUT_BITMAP_HELVETICA_18, -0.2, -0.20, str1 );
        glutPostRedisplay();
        glutSwapBuffers();

    }
    else{
                            /* Text */
    glClear( GL_COLOR_BUFFER_BIT );
    glClearColor( 0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport( 0, 0, 900, 500 );
    glFlush();
    glColor3f( 1, 1, 1 );
    char str[ 100 ], str1[ 100 ];
    glColor3f( 231/255.0, 14/255.0, 2/255.0 );
    drawString( GLUT_BITMAP_HELVETICA_18, 0.7, 0.9, "Score : ");
    gcvt( score, 4, str );
    glColor3f( 1, 1, 1);
    drawString( GLUT_BITMAP_HELVETICA_18, 0.85, 0.9, str);
    t2 = clock();
    double diff = ( double )t2 - (double)t1;
    diff /= CLOCKS_PER_SEC;
    gcvt( diff, 4, str1 );
    drawString( GLUT_BITMAP_HELVETICA_18, 0.85, 0.8, str1 );
    glColor3f( 231/255.0, 14/255.0, 2/255.0 );
    drawString( GLUT_BITMAP_HELVETICA_18, 0.7, 0.8, "Time : ");

    glColor3f( 231/255.0, 14/255.0, 2/255.0 );
    drawString( GLUT_BITMAP_TIMES_ROMAN_24, 0.15, 0.6, "Rules");
    glColor3f( 1, 1, 1 );
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, 0.5, "There are some object randomly at random position. The Green");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, 0.42, "Object in the middle can move in four direction and can also rotate");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, 0.34, "both clockwise & anti-clockwise. Objective of this game is to");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, 0.26, "vanish other objects within short period of time. When the green");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, 0.18, "object int the middle touch another object the object disappear and");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, 0.10, "score increases.");

    glColor3f( 231/255.0, 14/255.0, 2/255.0 );
    drawString( GLUT_BITMAP_TIMES_ROMAN_24, 0.15, -0.06, "Controls");
    glColor3f( 1, 1, 1 );
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, -0.14, "W - Move Up");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, -0.22, "S - Move Down");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, -0.30, "D - Move Right");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, -0.38, "A - Move Left");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, -0.46, "R - Rotate Clockwise");
    drawString( GLUT_BITMAP_HELVETICA_12, 0.15, -0.54, "T - Rotate Anti-Clockwise");
    glColor3f( 59/255.0, 0/255.0, 134/255.0 );
    drawString( GLUT_BITMAP_HELVETICA_12, 0.35, -0.70, "d e v e l o p e d  b y - s y m o n h a s a n");


    /*____________________________________________________________________*/

    glViewport( 0, 0, 500, 500 );
    glFlush();

                                /* Frame */

    glBegin( GL_QUADS );
    glColor3f( 0/255.0, 159/255.0, 183/255.0 );
    glVertex2f( -1, 1 );
    glVertex2f( 1, 1 );
    glVertex2f( 1, -1 );
    glVertex2f( -1, -1 );
    glColor3f( gR, gG, gB );
    glVertex2f( -0.94, 0.94 );
    glVertex2f( 0.94, 0.94 );
    glVertex2f( 0.94, -0.94 );
    glVertex2f( -0.94, -0.94 );

    /*_____________________________________________________________*/

    for( int i = 1; i <= 80; i++ )
    {
        glColor3f( ObjColor[ i ][ 1 ], ObjColor[ i ][ 2 ], ObjColor[ i ][ 3 ] );
        for( int j = 1 ; j <= 4; j++ )
        {
            glVertex2f( ObjX[ i ][ j ], ObjY[ i ][ j ] );
        }

    }

                        /* Center Object */

    glBegin( GL_QUADS );
    glColor3f( 3/255.0, 68/255.0, 12/255.0 );
    glVertex2f( ObjX[ 0 ][ 1 ] + tx, ObjY[ 0 ][ 1 ] + ty );
    glVertex2f( ObjX[ 0 ][ 2 ] + tx, ObjY[ 0 ][ 2 ] + ty );
    glColor3f( 3/255.0, 96/255.0, 22/255.0 );
    glVertex2f( ObjX[ 0 ][ 3 ] + tx, ObjY[ 0 ][ 3 ] + ty );
    glVertex2f( ObjX[ 0 ][ 4 ] + tx, ObjY[ 0 ][ 4 ] + ty );

    /*_________________________________________________________________*/
    glEnd();
    glFlush();
    glutSwapBuffers();
    }
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        ty += 0.01;
        Check();
        break;
    case 's':
        ty -= 0.01;
        Check();
        break;
    case 'd':
        tx += 0.01;
        Check();
        break;
    case 'a':
        tx -= 0.01;
        Check();
        break;
    case 'r':
        theta = 45;
        temp = ObjX[ 0 ][ 1 ] * cos( theta ) - ObjY[ 0 ][ 1 ]*sin( theta );
        ObjY[ 0 ][ 1 ] = ObjY[ 0 ][ 1 ] * cos( theta ) + ObjX[ 0 ][ 1 ]*sin( theta );
        ObjX[ 0 ][ 1 ] = temp;

        temp = ObjX[ 0 ][ 2 ] * cos( theta ) - ObjY[ 0 ][ 2 ]*sin( theta );
        ObjY[ 0 ][ 2 ] = ObjY[ 0 ][ 2 ] * cos( theta ) + ObjX[ 0 ][ 2 ]*sin( theta );
        ObjX[ 0 ][ 2 ] = temp;

        temp = ObjX[ 0 ][ 3 ] * cos( theta ) - ObjY[ 0 ][ 3 ]*sin( theta );
        ObjY[ 0 ][ 3 ] = ObjY[ 0 ][ 3 ] * cos( theta ) + ObjX[ 0 ][ 3 ]*sin( theta );
        ObjX[ 0 ][ 3 ] = temp;

        temp = ObjX[ 0 ][ 4 ] * cos( theta ) - ObjY[ 0 ][ 4 ]*sin( theta );
        ObjY[ 0 ][ 4 ] = ObjY[ 0 ][ 4 ] * cos( theta ) + ObjX[ 0 ][ 4 ]*sin( theta );
        ObjX[ 0 ][ 4 ] = temp;
        Check();
        break;
    case 't':
        theta = -45;
        temp = ObjX[ 0 ][ 1 ] * cos( theta ) - ObjY[ 0 ][ 1 ]*sin( theta );
        ObjY[ 0 ][ 1 ] = ObjY[ 0 ][ 1 ] * cos( theta ) + ObjX[ 0 ][ 1 ]*sin( theta );
        ObjX[ 0 ][ 1 ] = temp;

        temp = ObjX[ 0 ][ 2 ] * cos( theta ) - ObjY[ 0 ][ 2 ]*sin( theta );
        ObjY[ 0 ][ 2 ] = ObjY[ 0 ][ 2 ] * cos( theta ) + ObjX[ 0 ][ 2 ]*sin( theta );
        ObjX[ 0 ][ 2 ] = temp;

        temp = ObjX[ 0 ][ 3 ] * cos( theta ) - ObjY[ 0 ][ 3 ]*sin( theta );
        ObjY[ 0 ][ 3 ] = ObjY[ 0 ][ 3 ] * cos( theta ) + ObjX[ 0 ][ 3 ]*sin( theta );
        ObjX[ 0 ][ 3 ] = temp;

        temp = ObjX[ 0 ][ 4 ] * cos( theta ) - ObjY[ 0 ][ 4 ]*sin( theta );
        ObjY[ 0 ][ 4 ] = ObjY[ 0 ][ 4 ] * cos( theta ) + ObjX[ 0 ][ 4 ]*sin( theta );
        ObjX[ 0 ][ 4 ] = temp;
        Check();
        break;
    case 'y':
        def_box = 0;
            finish = 0, score = 0;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(900, 500 );
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Vanishing Quad");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
