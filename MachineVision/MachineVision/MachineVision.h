/*****************************************************************************
*                                                                            *
*  @file     MachineVision.h                                                 *
*  @brief    ����Ϊ�����Ӿ�����                                              *
*                                                                            *
*  @author   ZJH                                                             *
*  @email    877049745@qq.com                                                *
*  @version  1.0.0.1(�汾��)                                                 *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Ŀǰ�˿⹦�ܾ�����һЩԤ��������������˹����ܲ���       *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2019/11/14 | 1.0.0.1   | ZJH            | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;


// ���� ==> ������Ϣ
struct MyPicture
{
	cv::Rect			 Rect;                    //  ��Ӿ���
	Mat					 HSV_Rect;                //  HSV�и����
	Mat					 RGB_Rect;                //  ��ɫ�и�
	Mat					 Canny_Rect;              //  �ݶ��и�ͼ
	Mat					 Clahe_Rect;              //  ����ֱ��ͼ�и�
	Mat					 Thresold_Rect;           //  ��ֵͼ�и�
	vector<cv::Point>	 point;                   //  �����㼯
	Point2f				 center;                  //  ���ĵ�
	double				 area;                    //  �������
	double				 RectArea;                //  �������
	string				 color;                   //  ͼƬ��ɫ
	cv::RotatedRect		 MinRect;                 //  ��С����
};

class MachineVision
{
	/**
	 ************************************************************************
	 *@brief       ��ʼ��ͼƬ��Ϣ
	 *@parameter
	 *
	 *             Binary      ��ֵͼ
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
	vector<MyPicture> initPictureInformation(Mat Binary);


	/**
 	 ************************************************************************
	 *@brief       �õ�����
	 *@parameter
	 *
	 *             src      ԭͼ
	 *
	 *@version     v1.0.1
	 *@author      ZJH
	 *@date        2019/08/16
	 *----------------------------------------------------------------------
	 *@�޸�ʱ��:
	 *@�޸���+��ϵ��ʽ:
	 *@˵��(��Ϊʲô�޸�):
	 ************************************************************************
	 */
	vector<vector<cv::Point>> getContours(Mat src);


	/**
	 ************************************************************************
	 *@brief       �õ��������ĵ�
	 *@parameter
	 *
	 *             point   ����
	 *
	 *@version     v1.0.1
	 *@author      ZJH
	 *@date        2019/08/16
	 *----------------------------------------------------------------------
	 *@�޸�ʱ��:
	 *@�޸���+��ϵ��ʽ:
	 *@˵��(��Ϊʲô�޸�):
	 ************************************************************************
	 */
	Point2f getCenter(vector<cv::Point> point);


	/**
	 ************************************************************************
	 *@brief       �õ�����ͼ�ε��и����
	 *@parameter
	 *
	 *             originalMat  �и�ԭͼ
	 *             point        ���и�����
	 *
	 *@version     v1.0.1
	 *@author      ZJH
	 *@date        2019/08/16
	 *----------------------------------------------------------------------
	 *@�޸�ʱ��:
	 *@�޸���+��ϵ��ʽ:
	 *@˵��(��Ϊʲô�޸�):
	 ************************************************************************
	 */
	Mat getMatCutRect(Mat originalMat, vector<cv::Point> point);


	/**
	 ************************************************************************
	 *@brief       �õ��߿����
	 *@parameter
	 *
	 *             rect  Ҫ����ı߿�
	 *
	 *@version     v1.0.0
	 *@author      ZJH
	 *@date        2019/10/16
	 *----------------------------------------------------------------------
	 *@�޸�ʱ��:
	 *@�޸���+��ϵ��ʽ:
	 *@˵��(��Ϊʲô�޸�):
	 ************************************************************************
	 */
	int getRectArea(cv::Rect rect);


};