#include "opencv2/highgui.hpp"
#include"opencv/cv.h"
#include<iostream>
using namespace cv;

IplImage* doPyrDown(
	IplImage* in,
	int filter = CV_GAUSSIAN_5x5
) {
	assert(in->width % 2 == 0 && in->height % 2 == 0);
	IplImage* out = cvCreateImage(cvSize(in->width / 2, in->height / 2),
		in->depth,
		in->nChannels
	);
	cvPyrDown(in, out);
	return out;

}

IplImage* doCanny(
	IplImage* in,
	double lowThresh,
	double highThresh,
	double aperture
) {
	if (in->nChannels != 3)
		return (0);
	IplImage* out = cvCreateImage(
		cvGetSize(in),
		in->depth,	//IPL_DEPTH_8U,
		1);
	cvCanny(in, out, lowThresh, highThresh, aperture);
	return(out);
}


int main(int argc, char** argv) {
	cvNamedWindow("Example1");
	IplImage* img = cvLoadImage(argv[1]);
	IplImage* img1 = doPyrDown(img);
	IplImage* img2 = doPyrDown(img1);
	IplImage* img3 = doCanny(img2, 10, 100, 3);
	cvShowImage("Example1", img3);
	cvNamedWindow("Example2");
	cvShowImage("Example2", img);
	cvWaitKey(0);
	cvReleaseImage(&img1);
	cvReleaseImage(&img2);
	cvReleaseImage(&img3);

}