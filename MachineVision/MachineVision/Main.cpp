#include "pch.h"
#include <iostream>
#include "MachineVision.h"
using namespace std;
using namespace cv;
int main0()
{	
	cout << "hello,world" << endl;
	return 0;
}







/**********************************************************************/

//计算图像RGB空间的颜色直方图

void ColorHistogram(Mat src)
{

	//分通道显示
	vector<Mat> bgr_planes;
	split(src, bgr_planes);
	//cout << bgr_planes[0]<< endl;

	//设定像素取值范围
	int histSize = 256;
	float range[] = { 0,256 };
	const float* histRanges = { range };

	//三个通道分别计算直方图
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRanges, true, false);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges, true, false);

	//创建直方图画布并归一化处理
	int hist_h = 400;
	int hist_w = 512;
	int bin_w = hist_w / histSize;
	//Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0, 0, 0));
	//normalize(b_hist, b_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	//normalize(g_hist, g_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	//normalize(r_hist, r_hist, 0, hist_h, NORM_MINMAX, -1, Mat());
	int rinitialNum = r_hist.at<float>(0);
	int r_max = 0;
	//render histogram chart  在直方图画布上画出直方图
	for (int i = 1; i < histSize; i++)
	{
		if (rinitialNum < r_hist.at<float>(i))
		{
			rinitialNum = r_hist.at<float>(i);
			int r_max = i;
		}
	}


	int ginitialNum = g_hist.at<float>(0);
	int g_max = 0;
	for (int i = 1; i < histSize; i++)
	{
		if (ginitialNum < g_hist.at<float>(i))
		{
			ginitialNum = g_hist.at<float>(i);
			int g_max = i;
		}
	}


	int binitialNum = b_hist.at<float>(0);
	int b_max = 0;
	//render histogram chart  在直方图画布上画出直方图
	for (int i = 1; i < histSize; i++)
	{
		if (binitialNum < b_hist.at<float>(i))
		{
			binitialNum = b_hist.at<float>(i);
			int b_max = i;
		}
	}
	cout << "   r_max   " << r_max << "    g_max    " << g_max << "      b_max    " << b_max << endl;
	waitKey(0);


}

vector<vector<cv::Point> > getContours1(Mat src)
{
	vector <vector<cv::Point> > ::iterator it;
	vector <vector<cv::Point> > contours;
	vector <vector<cv::Point> > contoursBack;
	vector <cv::Point> point;
	vector <Vec4i> hireachy;
	findContours(src, contours, hireachy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < contours.size(); i++)
	{
		int epsilon = 0.01 * arcLength(contours[i], true);
		approxPolyDP(contours[i], point, epsilon, true);
		if (contourArea(point) > 10)
		{
			contoursBack.push_back(point);
		}
	}
	return contoursBack;
}

int* getPaixu(int* shuzu)
{
	/*
	
	
	
	
	*/
	int* shuzi = (int*)malloc(sizeof(int)*10);
	return shuzi;
}

int main() {

	//Mat src = imread("C:/Users/MSI-PC/Desktop/11293.jpg", 0);//二值的轮廓图
	//Mat dst = imread("C:/Users/MSI-PC/Desktop/1129y.jpg");  //原图，与二值化一样大
	////获取轮廓
	//vector <vector<cv::Point> >pointesit = getContours1(src);
	////获取外接矩形
	//cv::Rect RectRange = boundingRect(pointesit[0]);
	//Mat tempMat;//结果图
	//dst(RectRange).copyTo(tempMat);
	//ColorHistogram(tempMat);
	//imshow("结果", tempMat);
	//imshow("原图", dst);
	//imshow("轮廓", src);
	//waitKey(0);
	int number = 255;
	main();
	return 0;
}
