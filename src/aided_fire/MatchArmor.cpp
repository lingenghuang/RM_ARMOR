#include"MatchArmor.h"
using namespace cv;
using namespace std;

MatchArmor::MatchArmor(GetLightblob &light_blobs)
{
    is_repeat=new bool[light_blobs.fit_blob.size()];   //用于判断是否重复
    
    for(int i=0;i<light_blobs.fit_blob.size();i++)     //is_repeat初始化赋值
    {
        is_repeat[i]=0;
    }
    
    for(int i=0;i<light_blobs.fit_blob.size();i++)
    {
        if(is_repeat[i]==0)                               //已匹配的装甲片对应的is_repeat赋值为1,不再进行匹配
        {
            for(int j=i+1;j<light_blobs.fit_blob.size();j++)
            {
                if()     //TODO
            }
        }
    }
    
    delete[] is_repeat;
}