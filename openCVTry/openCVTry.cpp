// openCVTry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	Mat src = imread(argv[1]);
	if (!src.data) {
		cout << "Not found";
		return -1;
	}
	Mat srcGray;
	Mat grad;
	const char *windowTitle = "Sobel Edge Detection";
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	int c;
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(src, srcGray, CV_BGR2GRAY);
	namedWindow(windowTitle, CV_WINDOW_NORMAL);

	Mat gradX, gradY;
	Mat absGradX, absGradY, absGrad;
	Mat thresh;
	// Sobel(srcGray, gradX, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Scharr(srcGray, gradX, ddepth, 1, 0, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(gradX, absGradX);
	// Sobel(srcGray, gradY, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	Scharr(srcGray, gradY, ddepth, 0, 1, scale, delta, BORDER_DEFAULT);
	//Laplacian(srcGray, grad, ddepth, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(gradY, absGradY);
	//convertScaleAbs(grad, absGrad);
	addWeighted(absGradX, 0.5, absGradY, 0.5, 0, grad);
	//threshold(grad, thresh, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	//imshow(windowTitle, thresh);
	imshow(windowTitle, grad);
	waitKey(0);
	return 0;

}

