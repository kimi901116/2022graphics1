#include <stdio.h>
#include <GL/glut.h>
float angle[20],oldx = 0;
int angleID = 0;
FILE * fout = NULL,* fin =NULL;
void myWrite()
{
    if(fout == NULL)fout =fopen("file.txt","w+");
    for(int i=0;i<20;i++)
    {
        printf("%.1f",angle[i]);///�L�p��
        fprintf(fout,"%.1f",angle[i]);///�L�ɮ�
    }
}
void myRead()
{
    if(fout != NULL)
    {
        fclose(fout);
        fout = NULL;
    }
    if(fin == NULL)fin = fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///���e�e��
}
void keybord(unsigned  char  key,int x , int y)
{
    if(key=='r')myRead();
    if(key=='0')angleID = 0;
    if(key=='1')angleID = 1;
    if(key=='2')angleID = 2;
    if(key=='3')angleID = 3;
}
void mouse(int button,int state,int x,int y)///�ƹ��ƥ�
{
    oldx = x;
}
void motion(int x,int y)///���ʨƥ�
{
    angle[angleID] += (x - oldx);
    oldx = x;
    glutPostRedisplay();
    myWrite();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);///���(�k�WX,�k�WY,���UX,���UY)
    glPushMatrix();///�k��
        glTranslatef(0.3,0.4,0);///(3)���u���^����A��Ӧ�m
        glRotatef(angle[0],0,0,1);///(2)��Z�b����
        glTranslatef(-0.3,-0.4,0);///(1)���u���त�ߡA������
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)���u���^����A��Ӧ�m
            glRotatef(angle[1],0,0,1);///(2)��Z�b����
            glTranslatef(-0.7,-0.4,0);///(1)���u���त�ߡA������
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.1,0.3);
            /*
            glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)���u���^����A��Ӧ�m
            glRotatef(angle,0,0,1);///(2)��Z�b����
            glTranslatef(-0.7,-0.4,0);///(1)���u���त�ߡA������
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.1,0.3);
            */
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///����
        glTranslatef(-0.3,0.4,0);///(3)���u���^����A��Ӧ�m
        glRotatef(angle[2],0,0,1);///(2)��Z�b����
        glTranslatef(0.3,-0.4,0);///(1)���u���त�ߡA������
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///(3)���u���^����A��Ӧ�m
            glRotatef(angle[3],0,0,1);///(2)��Z�b����
            glTranslatef(0.7,-0.4,0);///(1)���u���त�ߡA������
            glColor3f(0,1,0);
            glRectf(-0.7,0.5,-1.1,0.3);
            /*
            glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)���u���^����A��Ӧ�m
            glRotatef(angle,0,0,1);///(2)��Z�b����
            glTranslatef(-0.7,-0.4,0);///(1)���u���त�ߡA������
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
    glutCreateWindow("week14_angle_fprintf");
    glutKeyboardFunc(keybord);
    glutMouseFunc(mouse);///�I�smouse�禡
    glutMotionFunc(motion);///�I�smotion�禡
    glutDisplayFunc(display);
    glutMainLoop();
}