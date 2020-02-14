// g++ $(pkg-config --cflags --libs opencv4) -std=c++11 webcam.cpp -o webcam

#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{

    Mat im;
    Mat im_gray;
    Mat im_map;

    VideoCapture cam(0);

    while (1)
    {
        cam.read(im);

        cvtColor(im, im_gray, COLOR_BGR2GRAY);
        applyColorMap(im_gray, im_map, COLORMAP_HSV);

        imshow("video", im);

        if (waitKey(17) == 27)
            break;
    }
}
