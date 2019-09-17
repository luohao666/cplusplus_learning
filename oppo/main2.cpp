#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;


vector<int> cal_hist(Mat& input)
{
    vector<int> gray(256,0);//记录每个灰度级别下的像素个数
    //统计每个灰度下的像素个数
    for (int i = 0; i < input.rows; i++)
    {
        uchar* p = input.ptr<uchar>(i);
        for (int j = 0; j < input.cols; j++)
        {
            int vaule = p[j];
            gray[vaule]++;
        }
    }
    return gray;
}

double smi_rate(Mat& input1,Mat& input2)
{
    vector<int> gray1= cal_hist(input1);
    vector<int> gray2= cal_hist(input2);
    double same=0.0;
    double all=0.0;
    for(int i=0;i<256;i++)
    {
      same+=min(gray1[i],gray2[i]);
      all+=gray1[i];  
    }
    return (same/all);
}

//主函数
int main()
{
	Mat srcImage1;
	srcImage1 = imread("1.jpg",0);
    Mat srcImage2;
	srcImage2 = imread("2.jpg",0);

    if(srcImage1.size()!=srcImage2.size())
        cout<<"pic1 and pic2 should have the same size"<<endl;

	cout<<smi_rate(Mat& srcImage1,Mat& srcImage2)<<endl;

	return 0;
}

