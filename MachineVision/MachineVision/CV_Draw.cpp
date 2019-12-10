#include "pch.h"
#include "CV_Draw.h"

/**
 ************************************************************************
 *@brief       在指定的图片上画圆
 *@parameter
 *
 *             src      原图
 *             x        X点
 *             y        Y点
 *             size     圆的大小
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/20
 *----------------------------------------------------------------------
 *@修改时间:
 *@修改人+联系方式:
 *@说明(你为什么修改):
 ************************************************************************
 */
void CV_Draw::drawCircle(Mat src, int x, int y, int size)
{
	RNG rng(12345);
	Point2f center;//圆心
	center.x = x;
	center.y = y;
	Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	circle(src, center, size, color, 5);
}




/**
 ************************************************************************
 *@brief       绘制矩形
 *@parameter
 *
 *             drawRect   绘制的矩形
 *             Canvas     画板
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/24
 *----------------------------------------------------------------------
 *@修改时间:
 *@修改人+联系方式:
 *@说明(你为什么修改):
 ************************************************************************
 */
void CV_Draw::drawRect(Mat Canvas, cv::Rect drawRect)
{
	rectangle(Canvas, drawRect, cv::Scalar(0, 255, 0), 2);
}




/**
 ************************************************************************
 *@brief       绘制轮廓
 *@parameter
 *
 *             Contours   绘制的轮廓
 *             Canvas     画板
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/10
 *----------------------------------------------------------------------
 *@修改时间:             2019/09/17   9:53
 *@修改人+联系方式:      张嘉皓 13821857896
 *@说明(你为什么修改):   本次将参数的类型改为vector<cv::Point>类型
 *						 上一版本的参数类型与当前版本的参数类型不大兼容
 *						 需额外处理初始化好的数据 很不方便 故作此更改
 ************************************************************************
 */
void CV_Draw::drawContours(Mat Canvas, vector<cv::Point> Contour)
{
	vector<vector<cv::Point>> Contours;
	Contours.push_back(Contour);
	cv::drawContours(Canvas, Contours, -1, cv::Scalar(0, 255, 255), FILLED);
}




/**
 ************************************************************************
 *@brief       绘制所有轮廓
 *@parameter
 *
 *             Contours   绘制的轮廓
 *             Canvas     画板
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/24
 *----------------------------------------------------------------------
 *@修改时间:
 *@修改人+联系方式:
 *@说明(你为什么修改):
 ************************************************************************
 */
void CV_Draw::drawAllContours(Mat Canvas, vector<vector<cv::Point>> Contour)
{
	cv::drawContours(Canvas, Contour, 0, cv::Scalar(255, 255, 255), FILLED);
}





/**
 ************************************************************************
 *@brief       绘制最小矩形
 *@parameter
 *
 *             Canvas  画板
 *             rect    要绘制的最小矩阵
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/10/23
 *----------------------------------------------------------------------
 *@修改时间:
 *@修改人+联系方式:
 *@说明(你为什么修改):
 ************************************************************************
 */
void CV_Draw::drawMinRect(Mat Canvas, RotatedRect rect)
{
	Point2f points[4];
	rect.points(points);
	for (int j = 0; j < 4; j++)
	{
		line(Canvas, points[j], points[(j + 1) % 4], Scalar(0, 0, 255), 2, 8);  //绘制最小外接矩形每条边
	}
}
