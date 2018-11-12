#ifndef _GETLIGHTBLOB_H
#define _GETLIGHTBLOB_H
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

#define C_AREA 10
#define MIN_LENGTH 5
#define MIN_RATIO 1.5
#define PI 3.14159
#define MIN_ANGLE 45
#define MAX_ANGLE 135

float distances(Point2f pt_1, Point2f pt_2);
float get_angle(float rect_k);
struct TrueBlob            //一个用于储存装甲条及其长宽信息的结构体
{
    float blob_length;
    float blob_width;
    RotatedRect light_blob;
};
class GetLightblob
{
  public:
    GetLightblob();
    GetLightblob(vector<vector<Point> > find_contours, Mat hsv_img);
    float rectang_k();
    void draw(Mat &show_img);
    vector<TrueBlob> fit_blob;
  private:
    RotatedRect tmp_rectangle;
};


#endif
