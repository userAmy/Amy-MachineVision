#pragma once
/*
˵��: �������һЩͼ���и�����
		1:������ɫ(HSV)�и�
		2:���������и�
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
		Mat pendingProcessed;  //������ͼ��
		//����HSV�и�
		static Mat HSV(Mat pendingProcessed, HsvThreshold hsvThreshold);
};