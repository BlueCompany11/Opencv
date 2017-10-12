/**
* @function cornerDetector_Demo.cpp
* @brief Demo code for detecting corners using OpenCV built-in functions
* @author OpenCV team
*/

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include"opencv\cv.h"
#include <iostream>

using namespace cv;
using namespace std;

void mouse_ev(int event, int x, int y, int flags, void* param) {
	IplImage* img = ((IplImage*)param);
	switch (event) {
	case CV_EVENT_LBUTTONDBLCLK: cout << x << " " << y << endl;
		break;
	case CV_EVENT_RBUTTONDBLCLK: cout << "prawy" << endl;
		break;
	case CV_EVENT_MOUSEMOVE: cout << "poruszono myszka" << endl;
		break;
	}
}
int main(int argc, char** argv) {
	IplImage* lena = cvLoadImage(argv[1]);
	cvNamedWindow("Test myszy", CV_WINDOW_AUTOSIZE);
	cvShowImage("Test myszy", lena);
	cvSetMouseCallback("Test myszy", mouse_ev, NULL);
	cvWaitKey(0);
}