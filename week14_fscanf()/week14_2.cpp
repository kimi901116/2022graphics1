#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt","w+");///�}���ɮ�(�ɦW,�Ҧ�)
    fprintf(fout,"3.1415926\n");
    fclose(fout);
    float angle = 0;
    FILE * fin = fopen("file.txt","r");
    fscanf(fin,"%f",&angle);///�S�[&�|��
    printf("Ū��angle:%f",angle);
    fclose(fin);
}
