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

/*��̬ѧƽ��*/
/*
	���ڿ��������Ʊȹ涨�ṹԪС����ϸ�ڣ�ͬʱ������Ӱ�찵ϸ�ڣ����������Ч���෴��
	�������ͨ�����ʹ��������������ƽ��ͼ���ȥ������
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

 /*��̬ѧ�ݶ�*/
 /*
	��Ե�õ���ǿ��ͬ������Ĺ��׵õ����Ƶ�һ��ͼ�񣬽����������ർͼ�����ݶȣ���Ч����
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