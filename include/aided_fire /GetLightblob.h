#ifndef _GETLIGHTBLOB_H
#define _GETLIGHTBLOB_H
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

#define C_AREA 10
#define MIN_LENGTH 5
#define MIN_RATIO 1.5
#define PI 3.14159
#define MIN_ANGLE 45
#define MAX_ANGLE 135

class GetLightblob
{
  public:
    GetLightblob();
    GetLightblob(vector<vector<Point> > find_contours, Mat hsv_img);
    float rectang_k(RotatedRect tmp_rectangle);
    float distances(Point2f pt_1, Point2f pt_2);
    float get_angle(float rect_k);
    void draw(Mat &show_img);
  private:
    vector<RotatedRect> fit_rectangle;
};

#endif
