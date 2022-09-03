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

/*形态学平滑*/
/*
	由于开运是抑制比规定结构元小的亮细节，同时几乎不影响暗细节，而闭运算的效果相反，
	因此我们通常组合使用者两种运算来平滑图像和去除噪声
*/
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

 /*形态学梯度*/
 /*
	边缘得到增强、同质区域的贡献得到抑制的一幅图像，进而产生“类导图”（梯度）的效果。
 */
 void GrayscaleMorpholgy::morphGradient(Mat &src, Mat &des, short ksize)
 {
	 if (ksize % 2 == 0)
	 {
		 ksize += 1;
	 }
	 //Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, Size(abs(ksize), abs(ksize)));
	 Mat openVal(src.size(), src.type(), cv::Scalar::all(0));
	 Mat closVal(src.size(), src.type(), cv::Scalar::all(0));
	 morphOpening(src, openVal, Mat());
	 morphClosing(src, closVal, Mat());
	 des = closVal-openVal;
	 des.convertTo(des, CV_32FC1);
	 cv::log(des + 1, des);
	 cv::normalize(des, des, 0, 255, cv::NORM_MINMAX);
	 des.convertTo(des, CV_8UC1);

 }