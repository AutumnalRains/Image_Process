#include<iostream>
#include<opencv2\highgui\highgui.hpp>
#include"grayscaleMorphology.h"
int main(int argc, char **argv)
{
	Mat src = cv::imread("D:/open_cv/DIP4E/cygnusloop.tif",cv::IMREAD_GRAYSCALE);
	if (src.empty())
	{
		return -1;
	}
	Mat des(src.size(), src.type(), cv::Scalar::all(0));
	GrayscaleMorpholgy::morphSmoothing(src,des,11);
	cv::namedWindow("title1",cv::WINDOW_AUTOSIZE);
	cv::imshow("title1", des);
	cv::waitKey(0);
	return 0;
}