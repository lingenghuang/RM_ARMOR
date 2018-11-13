#ifndef _MATCHARMOR_H
#define _MATCHARMOR_H
#include "GetLightblob.h"
using namespace cv;
using namespace std;

struct MatchGroup                    //储存两个匹配装甲条的结构体
{
    RotatedRect lightblob_1;
    RotatedRect lightblob_2;
};

class MatchArmor
{
  public:
    MatchArmor();
    MatchArmor(GetLightblob &light_blobs);
    
  private:
    vector<MatchGroup>matched_armor;   //储存的装甲片
    bool *is_repeat;
};

#endif