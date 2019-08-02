#include<iostream>
#include<dirent.h>
#include<vector>
#include<opencv2/opencv.hpp>
#include<get_keyboard.hpp>
#include<utils.hpp>
#include<detect_key.hpp>
#include<string>
using namespace std;
using namespace cv;

string video_path = "/home/data/cy/projects/piano/video/video1_crop.mp4";
string videoSavepath="/home/data/cy/projects/piano/frame/video1_whole_frame/";
string cropSavepath="/home/data/cy/projects/piano/frame/video1_crop_frame/"; 

string white_path = "/home/lj/cy/openpose/piano/test_piano/new_res/w_key/";

//这个是用来测试的,背景图片假设选一张最好的,因此视频前面截取的只剩下钢琴的不多,这不太好
int main(){
    //将视频转换为帧
    int frameTostop = 600;
    bool flags = true;  //C++中的是小写的,python中大写
    video_to_frame(video_path,videoSavepath,frameTostop,flags);

    Mat src,src_rgb, src_rgb1,base;
    struct dirent *ptr;
    DIR *dir;
    string img_extern = "/home/data/cy/projects/piano/frame/video1_whole_frame";  //以jpg结尾的图片
    dir = opendir(img_extern.c_str());
    vector<string> fn;

    while((ptr=readdir(dir))!=NULL)
    {
        //跳过'.'和'..'两个目录
        if(ptr->d_name[0] == '.')
            continue;
        //cout << ptr->d_name << endl;
        fn.push_back(ptr->d_name);
    }
    //glob(img_extern, fn, false);  //fn中存着图片的路径
    for (int i = 0; i < fn.size();i++){
        cout << fn[i] << endl;
    }

        return 0;
}
