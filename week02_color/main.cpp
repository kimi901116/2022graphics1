#include <GL/glut.h>///glut�~��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�M�e��
    glColor3f(1,1,0);///�]�w�C��
    //glutSolidTeapot(0.3);///��߯����j�p
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);///��
    glVertex2f(-1,-1);

    glColor3f(0,1,0);///��
    glVertex2f(+1,-1);

    glColor3f(0,0,1);///��
    glVertex2f(0,+1);
    glEnd();
    glutSwapBuffers();///�e�n�洫
}
int main(int argc,char**argv)///�D�{��
{
    glutInit(&argc,argv);///�ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///���w��+3D�`��
    glutCreateWindow("�ĤG�g�{��");///�����W��

    glutDisplayFunc(display);///��ܨ禡

    glutMainLoop();///�{���j��
}
