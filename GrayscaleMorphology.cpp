#include"grayscaleMorphology.h"
#include<opencv2\imgproc\imgproc.hpp>
#include<math.h>
void GrayscaleMorpholgy::morphOpening(Mat &src, Mat &des, Mat &element)
{
	Mat temp(src.size(), src.type(), cv::Scalar::all(0));
	cv::erode(src, temp, element);
	cv::dilate(temp, des, element);
}
void GrayscaleMorpholgy::morphClosing(Mat &src, Mat &des, Mat &element)
{
	Mat temp(src.size(), src.type(), cv::Scalar::all(0));
	cv::dilate(src, temp, element);
	cv::erode(temp, des, element);
}
 void GrayscaleMorpholgy::morphSmoothing(Mat &src, Mat &des, short ksize)
{
	if (ksize % 2 == 0)
	{
		ksize += 1;
	}
	Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, Size(abs(ksize), abs(ksize)));
	Mat temp(src.size(),src.type(),cv::Scalar::all(0));
	morphOpening(src,temp,element);
	morphClosing(temp, des, element);
}