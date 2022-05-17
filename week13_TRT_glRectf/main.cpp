#include <GL/glut.h>
float angle = 45,oldx = 0;
void mouse(int button,int state,int x,int y)///滑鼠事件
{
    oldx = x;
}
void motion(int x,int y)///移動事件
{
    angle += (x - oldx);
    oldx = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);///方形(右上X,右上Y,左下X,左下Y)
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///(3)手臂掛回身體，原來位置
        glRotatef(angle,0,0,1);///(2)對Z軸旋轉
        glTranslatef(-0.3,-0.4,0);///(1)手臂旋轉中心，正中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13_TRT_glRectf");
    glutMouseFunc(mouse);///呼叫mouse函式
    glutMotionFunc(motion);///呼叫motion函式
    glutDisplayFunc(display);
    glutMainLoop();
}
