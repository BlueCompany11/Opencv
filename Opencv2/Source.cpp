#include "opencv2/highgui.hpp"

using namespace cv;

int main(int argc, char** argv) {
	//zdjecie
	IplImage* img = cvLoadImage(argv[1]);
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);

	//film
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(argv[2]);
	IplImage* frame;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Example2", frame);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");

	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}