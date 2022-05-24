#include <stdio.h>
int main()
{
    ///檔案指標fout
    FILE * fout = fopen("file.txt","w+");///開啟檔案(檔名,模式)
    printf("Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///關閉檔案
}
