#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("Lena.png", IMREAD_COLOR);
    CV_Assert(image.data);

    Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
    flip(image, x_axis, 0); // X축 기준
    flip(image, y_axis, 1); // Y축 기준
    flip(image, xy_axis, -1); // 전체 뒤집기

    repeat(image, 1,2,rep_img);
    transpose(image, trans_img);

    imshow("image", image);
    imshow("x_axis", x_axis);
    imshow("y_axis", y_axis);
    imshow("xy_axis", xy_axis);
    imshow("rep_img", rep_img);
    imshow("trans_img", trans_img);
    waitKey();

    return 0;
}