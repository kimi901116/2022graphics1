#include <GL/glut.h>///glut外掛
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///清畫面
    glColor3f(1,1,0);///設定顏色
    //glutSolidTeapot(0.3);///實心茶壺大小
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);///紅
    glVertex2f(-1,-1);

    glColor3f(0,1,0);///綠
    glVertex2f(+1,-1);

    glColor3f(0,0,1);///藍
    glVertex2f(0,+1);
    glEnd();
    glutSwapBuffers();///畫好交換
}
int main(int argc,char**argv)///主程式
{
    glutInit(&argc,argv);///參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝+3D深度
    glutCreateWindow("第二週程式");///視窗名稱

    glutDisplayFunc(display);///顯示函式

    glutMainLoop();///程式迴圈
}
