#pragma once
/*
说明: 此类进行一些图像切割处理操作
		1:根据颜色(HSV)切割
		2:根据轮廓切割
			   .
			   .
			   .
*/

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
struct HsvThreshold
{
	int H_MIN;
	int H_MAX;
	int S_MIN;
	int S_MAX;
	int V_MIN;
	int V_MAX;
};
class ImageSplit
{
	public:
		Mat pendingProcessed;  //待处理图像
		//根据HSV切割
		static Mat HSV(Mat pendingProcessed, HsvThreshold hsvThreshold);
};