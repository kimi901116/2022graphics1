#include <GL/glut.h>
float angle = 45,oldx = 0;
void mouse(int button,int state,int x,int y)///�ƹ��ƥ�
{
    oldx = x;
}
void motion(int x,int y)///���ʨƥ�
{
    angle += (x - oldx);
    oldx = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);///���(�k�WX,�k�WY,���UX,���UY)
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///(3)���u���^����A��Ӧ�m
        glRotatef(angle,0,0,1);///(2)��Z�b����
        glTranslatef(-0.3,-0.4,0);///(1)���u���त�ߡA������
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
    glutMouseFunc(mouse);///�I�smouse�禡
    glutMotionFunc(motion);///�I�smotion�禡
    glutDisplayFunc(display);
    glutMainLoop();
}
