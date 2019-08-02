#ifndef _BWLABEL_H_
#define _BWLABEL_H
#include<opencv2/opencv.hpp>
#include<vector>
using namespace cv;
struct Feather
{
	int label;    
	int area;  
	Rect boundinbox; 
};
void illumination(Mat &src,Mat &overlay,const int &stepsize);  
int bwlabel(Mat &src, Mat &dst, std::vector<Feather> &featherlist);
#endif