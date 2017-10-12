#include "opencv2/highgui.hpp"
#include"opencv/cv.h"
#include<iostream>
using namespace cv;

int main(int argc, char** argv) {
	try {
		CvSize size = CvSize(720, 640);
		IplImage* img = cvLoadImage(argv[1]);
		IplImage* img2 = img; //cvCreateImage(size, 1, 3);
		cvResize(img, img2);
		cvNamedWindow("e2");
		cvShowImage("e2", img);
		cvNamedWindow("e1");
		cvShowImage("e1", img2);
	}
	catch (const std::exception & e) {
		std::cout << "Doesn't work : " << e.what();
		system("pause");
	}
		cvWaitKey(0);
}