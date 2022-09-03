#include"Morpholgy.h"
#include<opencv2\imgproc\imgproc.hpp>
void Morpholgy::openReconstruction(Mat &src, Mat &des)
{
	Mat structElement(51,1,CV_8UC1,cv::Scalar::all(255));
	Mat pre(src.size(), src.type());
	Mat current(src.size(), src.type());
	Mat compareRul(src.size(), src.type());
	cv::erode(src, current, structElement);
	do
	{
		pre=current.clone();
		cv::dilate(current,current,cv::noArray());
		cv::bitwise_and(current, src, current);
		cv::compare(pre, current, compareRul,cv::CMP_EQ);
	} while (compareRul.total()-cv::countNonZero(compareRul));
	des = current.clone();
}
