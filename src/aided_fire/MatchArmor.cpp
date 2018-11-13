#include"MatchArmor.h"
using namespace cv;
using namespace std;

MatchArmor::MatchArmor(GetLightblob &light_blobs)
{
    is_repeat=new bool[light_blobs.fit_blob.size()];   //用于判断是否重复
    
    for(int i=0;i<light_blobs.fit_blob.size();i++)     //is_repeat初始化赋值
    {
        is_repeat=0;
    }
    
    for(int i=0;i<light_blobs.fit_blob.size();i++)
    {
        if(is_repeat==0)                               //已匹配的装甲片对应的is_repeat赋值为1,不再进行匹配
        {
            for(int j=i+1;j<light_blobs.fit_blob.size();j++)
            {
                if()
            }
        }
    }
    
    delete[] is_repeat;
}