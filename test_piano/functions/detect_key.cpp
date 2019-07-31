#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;




//-----找到离白键最近的那个黑键------
int draw_box(double &white_loc,vector<Rect> &black_box){
    vector<double> diffs;
    for (int i = 0; i < black_box.size();i++){
        double diff = abs(black_box[i].tl().x - white_loc);
        diffs.push_back(diff);
    }
    //求vector中元素的最小值
    vector<double>::iterator smallest = min_element(begin(diffs), end(diffs));
    int index = distance(begin(diffs), smallest);
    return index;
}

vector<int> detect_w(Mat &src_rgb,Mat &img,vector<Point>&hand_point,
                        const vector<double>&white_loc,vector<Rect>&black_box,
                        const Rect &box,const float &ratio,vector<int> &pre_w
                        const vector<Rect> &total_top,const vector<Rect> &total_bottom){
	vector<Point>hand_tip;   //存放手指指尖的位置
    int b_height=img.rows;   //如果只想要指尖的位置是不是可以用跑指尖的模型来跑keypoint
    int b_width=img.cols;
    if(hand_point.size()>1){
        for(int i=0;i<hand_point.size();i++){
            if(i==4||i==8||i==11||i==15||i==20){
                hand_tip.push_back(hand_point[i]);  //从大拇指到小指
            }
        }
        for(int i=0;i<hand_tip.size();i++){  //循环每个手指
            if(hand_tip[i]==Point(0,0)){  //如果该关键点没检测到
                continue;
            }
            else{
    //将关键点坐标转换为在只包含钢琴图片的坐标中
                Point center=Point(hand_tip[i].x-box.tl().x,hand_tip[i].y-box.tl().y);
                circle(src_rgb,center,5,Scalar(0,0,255),-1);
                Point hand_loc=hand_tip[i];
                //判断手的坐标是否在钢琴上
                double new_x=hand_loc.x-box.tl().x;
                double new_y=hand_loc.y-box.tl().y;
                int offset=15;
    //减10是为了让有些帧中手指的关键点能够显示在钢琴上,有些刚好在钢琴下面差一点点
                if(new_x>0&&new_y>0&&new_x<b_width&&((new_y-10)<b_height)){  
                    //判断手的位置在哪个白键上
                    for(int p=0;p<white_loc.size()-1;p++){   //循环每个白键
                        Rect current_top=total_top[p];
                        Rect current_bottom = total_bottom[p];
                        double white_x=white_loc[p];
                        double white_width=white_loc[p+1]-white_x;
                        int w_count=0;
                        int area_w=0;
                        if((new_x>white_x)&&(new_x<white_x+white_width)){
                        //手在第p+1个白键上
                            //cout<<"第 "<<i<<" 个手指在第 "<<p+1<<"个白键上"<<endl;
                            for(int m=0;m<b_height;m++){
                                uchar *data_w=img.ptr<uchar>(m);
                                for(int n=0;n<b_width;n++){
                        //该关键点上方的白色像素占关键点上方区域比例的多少
                        //offset是因为有时候关键点附近那块连带着的白色像素过多,因此向上移动一点(如果关键点准确的话较好)
                                    if((n>white_x)&&(n<white_x+white_width)&&(m<(new_y-offset))){
                                        if(int(data_w[n])==255){
                                            w_count++;
                                        }
                                    }
                                    if((n>white_x)&&(n<white_x+white_width)&&(m<(new_y-offset))){
                                        area_w++;
                                    }
                                }
                            }
                            if(w_count>int(ratio*area_w)){
                                Rect white_box=Rect(white_x,0,0.5*white_width,0.5*b_height);
                                rectangle(src_rgb,white_box,Scalar(255,0,0),-1);
                                //cout<<"白键 "<<p+1<<"被按下"<<endl;
                                pre_w.push_back(p+1);
                            }
                            //cout<<"白色像素为: "<<w_count<<endl;
                            //cout<<"区域面积为: "<<area_w<<endl;
                        }
                    }
                }
            }
        }
    }
    return pre_w;
}

//-----找到每个白键所在区域的那个框框---------------
void find_box(const Mat &base_img_rgb, vector<double> &white_loc, vector<Rect> &black_box, vector<Rect> &total_top, vector<Rect> &total_bottom){
    
    int b_height = base_img_rgb.rows;  //base_img.rows
    int b_width=base_img_rgb.cols;   
    for (int p = 1; p < white_loc.size() ;p++){
        double white_x = white_loc[p-1];
        double white_width=white_loc[p]-white_x;

        //-----前面两个键不在周期规律内-----
        if(p==1){
            Rect top_box=Rect(white_x, 0, black_box[p-1].tl().x-white_x, 1.1*black_box[p-1].height);
            Rect bottom_box=Rect(white_x, 1.1*black_box[p-1].height, white_width, b_height-1.1*black_box[p-1].height);
            total_top.push_back(top_box);
            total_bottom.push_back(bottom_box);
        }
        else if(p==2){
            Rect top_box=Rect(black_box[p-2].br().x, 0, white_loc[p]-black_box[p-2].br().x, 1.1*black_box[p-2].height);
            Rect bottom_box=Rect(white_x, 1.1*black_box[p-2].height, white_width+2, b_height-1.1*black_box[p-2].height);
            total_top.push_back(top_box);
            total_bottom.push_back(bottom_box);
        }
        else if((p==3||((p-3)%7==0)&&p<52)||(((p==6||((p-6)%7==0)&&p<52)))){
            int index = draw_box(white_x, black_box);
            Rect top_box=Rect(white_x+1, 0, black_box[index].tl().x-white_x-1, 1.1*black_box[index].height);
            Rect bottom_box=Rect(white_x, 1.1*black_box[index].height, white_width+2, b_height-1.1*black_box[index].height);
            total_top.push_back(top_box);
            total_bottom.push_back(bottom_box);         
        }
        else if((p==4||((p-4)%7==0)&&p<52)||(((p==7||((p-7)%7==0)&&p<52)))||(((p==8||((p-8)%7==0)&&p<52)))){
            int index = draw_box(white_x, black_box);
            Rect top_box=Rect(black_box[index].br().x+1, 0, black_box[index+1].tl().x-black_box[index].br().x-1, 1.1*black_box[index].height);
            Rect bottom_box=Rect(white_x, 1.1*black_box[index].height, white_width+2, b_height-1.1*black_box[index].height);
            total_top.push_back(top_box);
            total_bottom.push_back(bottom_box);
        }
        else if((p==5||((p-5)%7==0)&&p<52)||(((p==9||((p-9)%7==0)&&p<52)))||(((p==8||((p-8)%7==0)&&p<52)))){
            int index = draw_box(white_x, black_box);
            Rect top_box=Rect(black_box[index].br().x+1, 0, white_loc[p]-black_box[index].br().x-1, 1.1*black_box[index].height);
            Rect bottom_box=Rect(white_x, 1.1*black_box[index].height, white_width+2, b_height-1.1*black_box[index].height);
            total_top.push_back(top_box);
            total_bottom.push_back(bottom_box);
        }
        //----最后一个框
        else{
            Rect top_box=Rect(white_x+1, 0, white_loc[p]-white_x-1, 1.1*black_box[35].height);
            Rect bottom_box=Rect(white_x+1, 1.1*black_box[35].height, white_loc[p]-white_x-1, b_height-1.1*black_box[35].height);
            total_top.push_back(top_box);
            total_bottom.push_back(bottom_box); 
        }

    }
    //cout << total_top.size() << endl;
/*     for (vector<Rect>::iterator iter = total_top.begin(); iter < total_top.end();iter++){
        rectangle(base_img_rgb, *iter, Scalar(0, 0, 255), 1);
    }
    for (int i = 0; i < total_bottom.size();i++){
        rectangle(base_img_rgb, total_bottom[i], Scalar(0, 0, 255), 1);
        string text = to_string(i);
        //putText(base_img_rgb, text, Point(total_bottom[i].tl().x + 5, b_height), FONT_HERSHEY_COMPLEX, 0.5, Scalar(255, 0, 0), 2);
    }
              
    imwrite("../test_rec.jpg", base_img_rgb); */
}