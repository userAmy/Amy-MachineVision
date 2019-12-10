#include "pch.h"
#include "CV_Draw.h"

/**
 ************************************************************************
 *@brief       ��ָ����ͼƬ�ϻ�Բ
 *@parameter
 *
 *             src      ԭͼ
 *             x        X��
 *             y        Y��
 *             size     Բ�Ĵ�С
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/20
 *----------------------------------------------------------------------
 *@�޸�ʱ��:
 *@�޸���+��ϵ��ʽ:
 *@˵��(��Ϊʲô�޸�):
 ************************************************************************
 */
void CV_Draw::drawCircle(Mat src, int x, int y, int size)
{
	RNG rng(12345);
	Point2f center;//Բ��
	center.x = x;
	center.y = y;
	Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	circle(src, center, size, color, 5);
}




/**
 ************************************************************************
 *@brief       ���ƾ���
 *@parameter
 *
 *             drawRect   ���Ƶľ���
 *             Canvas     ����
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/24
 *----------------------------------------------------------------------
 *@�޸�ʱ��:
 *@�޸���+��ϵ��ʽ:
 *@˵��(��Ϊʲô�޸�):
 ************************************************************************
 */
void CV_Draw::drawRect(Mat Canvas, cv::Rect drawRect)
{
	rectangle(Canvas, drawRect, cv::Scalar(0, 255, 0), 2);
}




/**
 ************************************************************************
 *@brief       ��������
 *@parameter
 *
 *             Contours   ���Ƶ�����
 *             Canvas     ����
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/10
 *----------------------------------------------------------------------
 *@�޸�ʱ��:             2019/09/17   9:53
 *@�޸���+��ϵ��ʽ:      �ż�� 13821857896
 *@˵��(��Ϊʲô�޸�):   ���ν����������͸�Ϊvector<cv::Point>����
 *						 ��һ�汾�Ĳ��������뵱ǰ�汾�Ĳ������Ͳ������
 *						 ����⴦���ʼ���õ����� �ܲ����� �����˸���
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
 *@brief       ������������
 *@parameter
 *
 *             Contours   ���Ƶ�����
 *             Canvas     ����
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/09/24
 *----------------------------------------------------------------------
 *@�޸�ʱ��:
 *@�޸���+��ϵ��ʽ:
 *@˵��(��Ϊʲô�޸�):
 ************************************************************************
 */
void CV_Draw::drawAllContours(Mat Canvas, vector<vector<cv::Point>> Contour)
{
	cv::drawContours(Canvas, Contour, 0, cv::Scalar(255, 255, 255), FILLED);
}





/**
 ************************************************************************
 *@brief       ������С����
 *@parameter
 *
 *             Canvas  ����
 *             rect    Ҫ���Ƶ���С����
 *
 *@version     v1.0.0
 *@author      ZJH
 *@date        2019/10/23
 *----------------------------------------------------------------------
 *@�޸�ʱ��:
 *@�޸���+��ϵ��ʽ:
 *@˵��(��Ϊʲô�޸�):
 ************************************************************************
 */
void CV_Draw::drawMinRect(Mat Canvas, RotatedRect rect)
{
	Point2f points[4];
	rect.points(points);
	for (int j = 0; j < 4; j++)
	{
		line(Canvas, points[j], points[(j + 1) % 4], Scalar(0, 0, 255), 2, 8);  //������С��Ӿ���ÿ����
	}
}
