#include <stdio.h>
int main()
{
    ///�ɮ׫���fout
    FILE * fout = fopen("file.txt","w+");///�}���ɮ�(�ɦW,�Ҧ�)
    printf("Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///�����ɮ�
}
