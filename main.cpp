#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace std;
using namespace cv;

int main() {
    Mat img1 = imread("/home/beka/image/1.jpg", IMREAD_GRAYSCALE);

    if (img1.empty()) {
        cout << "Cannot load image!" << endl;
        return -1;
    }
    imshow("Original", img1);

    Mat mask(img1.rows, img1.cols, CV_8UC1, Scalar(0, 0, 0));
    circle(mask, Point(img1.rows / 2, img1.cols / 2), 150, 255, -1);
    imshow("Mask", mask);

    Mat r;
    bitwise_and(img1, mask, r);

    const uchar white = 255;
    for (int i = 0; i < r.rows; i++)
        for (int j = 0; j < r.cols; j++)
            if (!mask.at<uchar>(i, j))
                r.at<uchar>(i, j) = white;

    imshow("Result", r);

    waitKey(0);
    return 0;

}