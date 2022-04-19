#include <opencv/highgui.h>
int main()
{
    IplImage*img = cvLoadImage("floor.jpg");
    cvShowImage("week09_Texture",img);
    cvWaitKey(0);
}
