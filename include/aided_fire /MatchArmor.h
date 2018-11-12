#ifndef _MATCHARMOR_H
#define _MATCHARMOR_H
#include "GetLightblob.h"
using namespace cv;
using namespace std;

struct MatchGroup
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
    vector<MatchGroup>matched_armor;
    bool *is_repeat;
};

#endif