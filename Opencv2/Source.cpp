#include "opencv2/highgui.hpp"
#include"opencv/cv.h"
#include<iostream>
using namespace cv;

void example2_4(IplImage* image) {
	cvNamedWindow("Example4-in");
	cvNamedWindow("Example4-out");
	cvShowImage("Example4-in",image);
	IplImage* out = cvCreateImage(
		cvGetSize(image),
		IPL_DEPTH_8U,
		3
	);
	cvSmooth(image, out, CV_GAUSSIAN, 3, 3);
	cvShowImage("Example4-out", out);
	cvReleaseImage(&out);
	cvWaitKey(0);
	cvDestroyAllWindows();
}
int main(int argc, char** argv) {
	IplImage* im = cvLoadImage(argv[1]);
	example2_4(im);
}