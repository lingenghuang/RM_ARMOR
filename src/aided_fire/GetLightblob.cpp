#include "GetLightblob.h"
using namespace cv;
using namespace std;
float distances(Point2f pt_1, Point2f pt_2)    //计算两点距离
{
  return sqrt(pow(pt_1.x-pt_2.x, 2)+pow(pt_1.y-pt_2.y, 2));
}

float get_angle(Point2f pt_1, Point2f pt_2)    //转换为角度值（与水平线夹角，逆时针增加，90度即为垂直）
{
    if(pt_1.x==pt_2.x) 
        return 90;
    else 
    {
        double tmp_k=(pt_1.y-pt_2.y)/(pt_1.x-pt_2.x);
        return tmp_k>0?(PI-atan(tmp_k))*180./PI:-atan(tmp_k)*180./PI;
    }    
        
}

float GetLightblob::rectang_k()     //返回拟合矩形的角度
{
    Point2f tmp_points[4];
    tmp_rectangle.points(tmp_points);
    if (distances(tmp_points[0], tmp_points[1]) > distances(tmp_points[1], tmp_points[2]))
        
        return get_angle(tmp_points[0], tmp_points[1]);
    else
        return get_angle(tmp_points[1], tmp_points[2]);
}


GetLightblob::GetLightblob(vector<vector<Point> > find_contours, Mat hsv_img)
{
    fit_blob.clear();         //初始化清空
    for (int i = 0; i < find_contours.size(); i++)
    {
        double contours_area = contourArea(find_contours[i]);
        if (contours_area >= C_AREA) //排除面积过小的误识别
        {
            tmp_rectangle = minAreaRect(find_contours[i]); //拟合矩形

            float rect_length = ((tmp_rectangle.size.height > tmp_rectangle.size.width) ? tmp_rectangle.size.height : tmp_rectangle.size.width);
            float rect_width = ((tmp_rectangle.size.height < tmp_rectangle.size.width) ? tmp_rectangle.size.height : tmp_rectangle.size.width);
            //提取矩形的长宽
            if (rect_length > MIN_LENGTH && rect_length > MIN_RATIO * rect_width) //排除长度过小和长宽比过低的误识别
            {
                float rect_angle=rectang_k();
                if (rect_angle>MIN_ANGLE&&rect_angle<MAX_ANGLE)        //根据斜率排除误识别
                {
                    TrueBlob tmp_blob;
                    tmp_blob.blob_length=rect_length;
                    tmp_blob.blob_width=rect_width;
                    tmp_blob.light_blob=tmp_rectangle;
                    fit_blob.push_back(tmp_blob);
                }
            }
        }
    }
}

void GetLightblob::draw(Mat &show_img)
{
    for (int i = 0; i < fit_blob.size(); i++)
    {
        ellipse(show_img, fit_blob[i].light_blob, Scalar(0, 255, 255), 3);      //TODO
                                                                     //方便起见，暂时用椭圆
    }
}