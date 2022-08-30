#include<opencv2\core\core.hpp>
using cv::Mat;
using cv::Size;
class GrayscaleMorpholgy
{
public :
	static void morphSmoothing(Mat &src,Mat &des, short ksize);
	static void morphOpening(Mat &src, Mat &des,Mat &element);
	static void morphClosing(Mat &src, Mat &des, Mat &element);
};