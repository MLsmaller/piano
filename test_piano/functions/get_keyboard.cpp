#include<opencv2/opencv.hpp>
#include<get_keyboard.hpp>
#include "bwlabel.hpp"
#include<string>
#include<vector>
#include<iostream>
//#include<numeric>   //调用accumulate()函数对vcctor进行求和
using namespace std;
using namespace cv;

//------去除钢琴中一部分上面和下面的部分,以便于检测黑键的位置(灰度图片)
Mat remove_region(Mat &result)
{
	//如果是RGB图片,还要考虑通道channel,遍历图片的方式则不同
	int width = result.cols;
	int height = result.rows;

	for (int i = 0; i < 0.05*height; i++) {
		uchar *data = result.ptr<uchar>(i);
		for (int j = 0; j < width; j++) {
			data[j] = 255;        //变为白色像素
		}
	}
	for (int i = 0; i < height; i++) {
		uchar *data = result.ptr<uchar>(i);
		for (int j = 0; j < width; j++) {
/* 			if(i > 0.95*height){
				data[j] = 255;
			} */
			if ((i > (2.0/3)*height) || (j < 0.004*width) || (j > 0.996*width))
			{
				data[j] = 255;
			}
		}
	}
	return result;
}

//-----计算图片经过canny边缘检测后白色像素(255)的总数量
int count_pixel(Mat &img)
{
	int width = img.cols;
	int height = img.rows;
	int pixel_num = 0;
	for (int i = 0; i < height; i++) {
		uchar *data = img.ptr<uchar>(i);
		for (int j = 0; j < width; j++) {
			if(int(data[j])==255){
				pixel_num++;
			}
		}
	}
	return pixel_num;
}

//有时候编译错误提醒少了括号时{,有可能是其他地方的括号没有标全
//------得到钢琴的位置和图片
Mat keyboard(Mat &src,vector<Rect> &box_keyboard,float &ratio){
	Mat midImage, dstImage, final_img, roi_img;
	string pro_path="/home/lj/cy/openpose/piano/test_piano/";	 
	final_img = src.clone();
	int width, height;
	width = src.cols;
	height = src.rows;
    cvtColor(src,src,COLOR_BGR2GRAY);
    blur(src,src,Size(5,5));
	Canny(src, midImage, 50, 200, 3);    //进行一此canny边缘检测
	//canny边缘检测后如果白色像素占图片总像素值大于某一阈值,认为该图片中包含钢琴(有些视频开头不是马上弹钢琴)
	int pixel_num = count_pixel(midImage);
	ratio = (pixel_num / float(width * height));
	//imwrite("../canny.jpg", midImage);	
	cvtColor(midImage, dstImage, COLOR_GRAY2BGR);

#if 0
	vector<Vec2f>lines;
	HoughLines(midImage, lines, 0.5, CV_PI / 180, 200, 0, 0); //150表示阈值，越大检测出的直线越少，但越精确
	cout << lines.size();
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0];  //圆的半径r      因为是在极坐标系
		float theta = lines[i][1];  //直线的角度
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));  //返回和参数最接近的整数值
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000.0* (a));
		line(dstImage, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
		imshow("final_img", dstImage);
	}
#else
	vector<Vec4i>lines;
	HoughLinesP(midImage, lines, 1, CV_PI / 180, 320, (0.9)*width, width);  //想要结果为小数记得加.0,eg:(2.0/3)
	//260:阈值,大于阈值的线段才可以被检测出来; (2.0/3)*width:最低线段的长度,大于才能显示出来; width:允许同一行点与点之间连接起来的最大的距离
	cout << "检测到的直线数量为: "<<lines.size() << endl;
	if(lines.size()>1){
		vector<double> aver_height;   //存放的是直线的纵坐标平均值(可用以区分钢琴上面和下面的直线)
		for (size_t i = 0; i < lines.size(); i++)
		{
			Vec4i l = lines[i];
			aver_height.push_back(l[1]);
			//如何判断一下是否含有钢琴
			//cout << l[0] << endl;
			line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);		
		}
		double sum = accumulate(aver_height.begin(), aver_height.end(), 0);
		double average_h = sum / aver_height.size();
		vector<Vec4i> top_lines;
		vector<Vec4i> bottom_lines;      //将钢琴上方和下方的直线分别存放
		for (size_t i = 0; i < lines.size(); i++){
			Vec4i temp = lines[i];
			if(temp[1]>average_h){
				bottom_lines.push_back(temp);
			}
			else{
				top_lines.push_back(temp);
			}
		}

		//得到包含钢琴的两条直线(直线的横坐标相差很小或相等),有可能同一侧有几条直线与另一侧直线坐标离得很近
		vector<Point> obj_index;
		for (size_t i = 0; i < top_lines.size(); i++){
			Vec4i line_num1 = top_lines[i];
			for (size_t j = 0; j < bottom_lines.size();j++){
				Vec4i line_num2= bottom_lines[j];
				//cout << "line_num :" << line_num1[0] << "   " << line_num2[0] << endl;
				if (abs(line_num1[0] - line_num2[0]) < 0.005 * width)
				{	
					obj_index.push_back(Point(i,j));        
	/* 				if(line_num1[1]>line_num2[1]){   //将纵坐标小的(上方的)直线下标先存入
						obj_index.push_back(j);        
						obj_index.push_back(i);
					}
					else{
						obj_index.push_back(i);
						obj_index.push_back(j);
					}	 */			
				}
			}
		}
		//如果有多组直线差值相近,选择x最接近的那组
		Point first_point;
		if (obj_index.size()>0){
			first_point = obj_index[0];
			//cout << first_point.x << endl;   //Point类取其元素是.x和.y来操作
			for (size_t i = 1; i < obj_index.size();i++){
				Point next_point = obj_index[i];
				int top_dif = abs(top_lines[first_point.x][0]) - bottom_lines[first_point.y][0];
				int bottom_dif = abs(top_lines[next_point.x][0]) - bottom_lines[next_point.y][0];
				if(top_dif>bottom_dif){
					first_point = next_point;
				}
			}		
		}
		Vec4i t_line = top_lines[first_point.x];
		Vec4i b_line = bottom_lines[first_point.y];
		char buf[100];
		sprintf(buf,"%stest_Hough.jpg",pro_path.c_str());
		//line(dstImage, Point(0.005 * width, 0), Point(0.005 * width, height), Scalar(0, 0, 255),1,CV_AA);
		//imwrite(buf,dstImage);
	#endif
	//------------存放最上面和最下面直线的下标索引----------
	/* 	vector<size_t>index;  
		//求最上面的直线及索引(纵坐标lines[i][1]最小)
		int top = lines[0][1];
		for (size_t i = 1; i < lines.size(); i++)
		{
			if (lines[i][1] < top)
			{
				top = lines[i][1];
			}
		}

		for (size_t i = 0; i < lines.size(); i++)
		{
			if (top == lines[i][1])
			{
				index.push_back(i);
			}
		}
		//求最下面的直线及索引(纵坐标最大)
		int bottom = lines[0][1];
		for (size_t i = 1; i < lines.size(); i++)
		{
			if (lines[i][1] > bottom)
			{
				bottom = lines[i][1];
			}
		}
		for (size_t i = 0; i < lines.size(); i++)
		{
			if (bottom == lines[i][1])
			{
				index.push_back(i);
			}
		} */
		
		vector<Vec4i>new_lines;
		//new_lines.push_back(lines[index[0]]);
		//new_lines.push_back(lines[index[1]]);
		new_lines.push_back(t_line);
		new_lines.push_back(b_line);
		vector<Rect>obj_rct;
		Rect a1, a1_hand;
		Vec4i l1 = new_lines[0];
		Vec4i l2 = new_lines[1];
		a1 = Rect(max(l1[0],l2[0]),l1[1],min(l2[2],l1[2])-max(l1[0],l2[0]),l2[3]-l1[1]);   //img with keyboard
		box_keyboard.push_back(a1);
		roi_img = Mat(final_img, a1);

		a1_hand = Rect(max(l1[0],l2[0]),l1[1],min(l2[2],l1[2])-max(l1[0],l2[0]), height - l1[1]);  //img with keyboard and hand
		Mat img_hand = Mat(src, a1_hand);
	}
    return roi_img;
}

//-------计算钢琴下方1/3处的平均亮度(rgb图片)
float count_brightness(Mat &img)
{
	//钢琴键盘是白色的(接近255),因此有手在上面的话亮度就没这么高
	int width = img.cols;
	int height = img.rows;
	int pixel_num = 0;
	vector<int> pixel;
	//这里需要遍历的是彩色图片,rgb图像可以看做是r,g,b三个分量平铺着连起来,相当于width变为原来的3倍
	//如果没有乘以img.channels(),对其做改变只会在左边的1/3处进行变动
	for (int i = 0; i < height; i++) {
		uchar *data = img.ptr<uchar>(i);
		for (int j = 0; j < width*img.channels(); j++) {
			if (i > (2.0/3)*height)
			{
				pixel.push_back(int(data[j]));
			}
		}
	}
	float total_pixel = accumulate(pixel.begin(), pixel.end(), 0);
	float aver_pixel = total_pixel / float(pixel.size());
	//cout << pixel.size() / float(height * width * img.channels()) << endl;
	return aver_pixel;
}

//-------找到最适合当背景的图片,黑键数量最多(36)且图片下方1/3处的平均亮度最亮---
int find_base(Mat &img,const int &index,const vector<string> &fn,int &best_index){
	Mat base = img.clone();
	int width = base.cols;
	int height = base.rows;
	float brightness,brightness1;
	//计算亮度的时候用的是RGB图像,但是后面用连通算法检测黑键数量用的是灰度图
	brightness = count_brightness(base);
	//cout << "第一张背景图钢琴下方区域的平均亮度为: "<<brightness << endl;
	cvtColor(base, base, CV_BGR2GRAY);
	base=remove_region(base);
	threshold(base, base,120, 255, THRESH_BINARY);
	GaussianBlur(base, base, Size(5, 5), 2);
	Mat dst,dst1;
	vector<Feather>featherlist;
	int num,num1;
	num = bwlabel(base, dst, featherlist);
	cout << "第一张背景图检测到的黑键数量为: "<<num << endl;
	for (int i = index+1; i < fn.size();i++){
		//-----为了加快运行速度,后面改回来
		if (i>330){
			break;
		}
		Mat frame = imread(fn[i]);
		brightness1=count_brightness(frame);
		cvtColor(frame, frame, CV_BGR2GRAY);
		frame=remove_region(frame);
		threshold(frame, frame,120, 255, THRESH_BINARY);
		GaussianBlur(frame, frame, Size(5, 5), 2);
		num1 = bwlabel(frame, dst1, featherlist);
		//cout << "当前帧亮度为 " <<brightness1<<"  检测到黑键数量为:	"<<num1<<endl;
		if (num==36){
			if((brightness1>brightness)&&(num1==36)){
				brightness = brightness1;
				best_index = i;
			}
		}
		else{
			if((brightness1>brightness)&&(num1>num)){
			brightness = brightness1;
			num = num1;
			best_index = i;
			}
		}
	}
	return best_index;
}

//------得到黑键和白键的坐标位置
void key_loc(const Mat &img,vector<Rect> &black_box,vector<double> &white_loc,vector<int> &area){
	Mat base=img.clone();
	int width=img.cols;
	int height=img.rows;
	Mat img_ori=img.clone();
	base=remove_region(base);
	//imwrite("../region.jpg", base);
	threshold(base, base,120, 255, THRESH_BINARY);  //可以使用Osty thresholding method?
	//不同的钢琴视频可能光照强度不一样,因此阈值会有不同
	//-----用region label来定位出钢琴可以试一下-----
	GaussianBlur(base, base, Size(5, 5), 2);
	//imwrite("../bwlabel.jpg", base);
	Mat dst;
	vector<Feather>featherlist;
	int num = bwlabel(base, dst, featherlist);
	//cout << num << endl;
	vector<Point>black_loc;
	for (vector<Feather>::iterator iter = featherlist.begin(); iter < featherlist.end(); iter++)
	{
		area.push_back(iter->area);  
		black_box.push_back(iter->boundinbox);
		black_loc.push_back(iter->boundinbox.tl());  //.tl()是Rect类的成员函数
		//存储着每个黑键的左上角坐标
	}

/* 	for (int i = 0; i < area.size(); i++)
	{	
		cout << "第 " << i << " 个矩形框的面积为: ";
		cout << area[i] << endl;;
	} */
	//钢琴除掉前面的两个白键和一个黑键以及最后一个黑键,其它可以有规律的分为7个区域
	//由于角度等原因对每个区域计算白键间隔都不同
	//这些23、41等数值是参考网页中the size of the piano keyboard得出的
	int black_gap1=black_loc[3].x-black_loc[2].x; 
	double WhiteKey_width1=(23.0/41)*(black_gap1);  //根据白键所占的比例计算出白键间隔
	//由于第四个黑键是被均分两半的，因此从这里开始计算每个区域的起始位置
	int half_width1=black_box[4].width;
	//第一个区域的起始位置坐标
	double keybegin=black_loc[4].x+double(half_width1/2.0)-7.0*WhiteKey_width1;  //第一次减多两个
	//double whitebegin=keybegin+WhiteKey_width1*2;
	int whitekey_num=52;
	int blackkey_num=36;
	for(int i=0;i<10;i++){    //第一次黑键循环(要包括第一个黑键)
		line(img_ori,Point2f(keybegin+i*WhiteKey_width1,0),Point2f(keybegin+i*WhiteKey_width1,height),Scalar(0,0,255),1,CV_AA);
		white_loc.push_back(keybegin+i*WhiteKey_width1);
	}
	for(int i=0;i<6;i++){     //剩下黑键还有6次循环
		int axis=8+i*5;
		int black_gap2=black_loc[axis].x-black_loc[axis-1].x;
		double WhiteKey_width2=(23.0/41)*(black_gap2);
		int half_width2=black_box[axis+1].width;
		double keybegin1=black_loc[axis+1].x+double(half_width2/2.0)-5.0*WhiteKey_width2;
		for(int i=1;i<8;i++){
			line(img_ori,Point2f(keybegin1+i*WhiteKey_width2,0),Point2f(keybegin1+i*WhiteKey_width2,height),Scalar(0,0,255),1,CV_AA);
			white_loc.push_back(keybegin1+i*WhiteKey_width2);
		}
		if(i==5){   //最后一次循环时把钢琴最后一个白建加进去
			//判断是否超过图片右边界
			if(width<int(keybegin1+8*WhiteKey_width2)){
				white_loc.push_back(width-1);
			}
			else{
				white_loc.push_back(keybegin1+8*WhiteKey_width2);
			}
			//.back()函数取vector<>中的最后一个元素
			line(img_ori,Point2f(white_loc.back(),0),Point2f(white_loc.back(),height),Scalar(0,0,255),1,CV_AA);
		}
	}
	cout<<"the number of whitekey_num is "<<white_loc.size()<<endl;
	//imwrite("../key_ling.jpg",img_ori);
}

