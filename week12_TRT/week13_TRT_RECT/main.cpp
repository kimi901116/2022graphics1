///week13_TRT_RECT
#include <GL/glut.h>
float angle[20],oldx = 0;
int angleID = 0;
void keybord(unsigned  char  key,int x , int y)
{
    if(key=='0')angleID = 0;
    if(key=='1')angleID = 1;
    if(key=='2')angleID = 2;
    if(key=='3')angleID = 3;
}
void mouse(int button,int state,int x,int y)///滑鼠事件
{
    oldx = x;
}
void motion(int x,int y)///移動事件
{
    angle[angleID] += (x - oldx);
    oldx = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);///方形(右上X,右上Y,左下X,左下Y)
    glPushMatrix();///右邊
        glTranslatef(0.3,0.4,0);///(3)手臂掛回身體，原來位置
        glRotatef(angle[0],0,0,1);///(2)對Z軸旋轉
        glTranslatef(-0.3,-0.4,0);///(1)手臂旋轉中心，正中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)手臂掛回身體，原來位置
            glRotatef(angle[1],0,0,1);///(2)對Z軸旋轉
            glTranslatef(-0.7,-0.4,0);///(1)手臂旋轉中心，正中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.1,0.3);
            /*
            glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)手臂掛回身體，原來位置
            glRotatef(angle,0,0,1);///(2)對Z軸旋轉
            glTranslatef(-0.7,-0.4,0);///(1)手臂旋轉中心，正中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.1,0.3);
            */
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///左邊
        glTranslatef(-0.3,0.4,0);///(3)手臂掛回身體，原來位置
        glRotatef(angle[2],0,0,1);///(2)對Z軸旋轉
        glTranslatef(0.3,-0.4,0);///(1)手臂旋轉中心，正中心
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///(3)手臂掛回身體，原來位置
            glRotatef(angle[3],0,0,1);///(2)對Z軸旋轉
            glTranslatef(0.7,-0.4,0);///(1)手臂旋轉中心，正中心
            glColor3f(0,1,0);
            glRectf(-0.7,0.5,-1.1,0.3);
            /*
            glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)手臂掛回身體，原來位置
            glRotatef(angle,0,0,1);///(2)對Z軸旋轉
            glTranslatef(-0.7,-0.4,0);///(1)手臂旋轉中心，正中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.1,0.3);
            */
        glPopMatrix();

    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13_TRT_glRectf");
    glutKeyboardFunc(keybord);
    glutMouseFunc(mouse);///呼叫mouse函式
    glutMotionFunc(motion);///呼叫motion函式
    glutDisplayFunc(display);
    glutMainLoop();
}
