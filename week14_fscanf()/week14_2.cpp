#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt","w+");///開啟檔案(檔名,模式)
    fprintf(fout,"3.1415926\n");
    fclose(fout);
    float angle = 0;
    FILE * fin = fopen("file.txt","r");
    fscanf(fin,"%f",&angle);///沒加&會當
    printf("讀到angle:%f",angle);
    fclose(fin);
}
