#include "pch.h"
#include "MachineVision.h"
 /**
  ************************************************************************
  *@brief       初始化图片信息
  *@parameter
  *
  *             Binary      二值图
  *
  *@version     v1.0.1
  *@author      ZJH
  *@date        2019/08/21
  *----------------------------------------------------------------------
  *@修改时间:
  *@修改人+联系方式:
  *@说明(你为什么修改):
  ************************************************************************
  */
vector<MyPicture> MachineVision::initPictureInformation(Mat Binary)
{
	vector<MyPicture>         Pictures;            // 所有图片信息
	vector<vector<cv::Point>> ContoursSet;         // 轮廓信息
	Mat                       HsvMat;              // HSV图	
	ContoursSet = getContours(Binary);             // 初始化轮廓信息

	for (int i = 0; i < ContoursSet.size(); i++)
	{
		MyPicture tempPicture;
		// 计算轮廓
		tempPicture.point        =   ContoursSet[i];

		// 计算面积				    
		tempPicture.area         =   contourArea(ContoursSet[i]);

		// 计算中心点			    
		tempPicture.center       =   getCenter(ContoursSet[i]);

		// 得到二值化轮廓矩形图	    
		tempPicture.Canny_Rect   =   getMatCutRect(Binary, tempPicture.point);

		// 计算矩形				    
		tempPicture.Rect         =   boundingRect(tempPicture.point);

		// 计算最小面积			    
		tempPicture.RectArea     =   getRectArea(tempPicture.Rect);

		// 加入集合
		Pictures.push_back(tempPicture);
	}
	return Pictures;
}



 /**
  ************************************************************************
  *@brief       得到轮廓
  *@parameter
  *
  *             src      原图
  *
  *@version     v1.0.1
  *@author      ZJH
  *@date        2019/08/16
  *----------------------------------------------------------------------
  *@修改时间:
  *@修改人+联系方式:
  *@说明(你为什么修改):
  ************************************************************************
  */
vector<vector<cv::Point>> MachineVision::getContours(Mat src)
{
	vector<vector<cv::Point>>::iterator it;
	vector<vector<cv::Point>> contours;
	vector<vector<cv::Point>> contoursBack;
	vector<cv::Point> point;
	vector<Vec4i> hireachy;
	findContours(src, contours, hireachy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	//    findContours(src, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	for (int i = 0; i < contours.size(); i++)
	{
		int epsilon = 0.01*arcLength(contours[i], true);
		approxPolyDP(contours[i], point, epsilon, true);
		if (contourArea(point) > 10)
		{
			contoursBack.push_back(point);
		} 
	}
	return contoursBack;
}


 /**
  ************************************************************************
  *@brief       得到轮廓中心点
  *@parameter
  *
  *             point   轮廓
  *
  *@version     v1.0.1
  *@author      ZJH
  *@date        2019/08/16
  *----------------------------------------------------------------------
  *@修改时间:
  *@修改人+联系方式:
  *@说明(你为什么修改):
  ************************************************************************
  */
Point2f MachineVision::getCenter(vector<cv::Point> point)
{
	Moments contours_center;
	contours_center = moments(point);
	Point2f myPoint;
	myPoint.x = static_cast<float>(contours_center.m10 / contours_center.m00);
	myPoint.y = static_cast<float>(contours_center.m01 / contours_center.m00);
	return myPoint;
}



 /**
  ************************************************************************
  *@brief       得到所有图形的切割矩形
  *@parameter
  *
  *             originalMat  切割原图
  *             point        待切割轮廓
  *
  *@version     v1.0.1
  *@author      ZJH
  *@date        2019/08/16
  *----------------------------------------------------------------------
  *@修改时间:
  *@修改人+联系方式:
  *@说明(你为什么修改):
  ************************************************************************
  */
Mat MachineVision::getMatCutRect(Mat originalMat, vector<cv::Point> point)
{
	//临时存放
	Mat tempMat;
	cv::Rect rect_ = boundingRect(point);
	originalMat(rect_).copyTo(tempMat);
	return tempMat;
}



/**
 ************************************************************************
 *@brief       得到边框面积
 *@parameter
 *
 *             rect  要计算的边框
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/10/16
 *----------------------------------------------------------------------
 *@修改时间:
 *@修改人+联系方式:
 *@说明(你为什么修改):
 ************************************************************************
 */
int MachineVision::getRectArea(cv::Rect rect)
{
	return rect.width*rect.height;
}
