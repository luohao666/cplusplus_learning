#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
//像素点的位置数组
int dx[] = { -1,0,1,-1,0,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,0,1,1,1 };
//冒泡排序，返回中间值
int bubbleSort(int data[], int size)
{
    for(int i=0;i<size;i++)
        for(int j=0;j<size-i;j++)
        {
            if(data[j]>data[j+1])
            {
                int temp;
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
	return data[4];
}

Mat median_filter(const Mat& srcImage)
{
    Mat dst;
	dst.create(srcImage.size(),srcImage.type());
    for (int i = 0; i < srcImage.rows; i++) {
		for (int j = 0; j < srcImage.cols; j++) {
			if ((i - 1) >= 0 && (i + 1) < srcImage.rows && (j - 1) >= 0 && (j + 1) < srcImage.cols) //边界处理
            {
				int d[9];
				for (int k = 0; k < 9; ++k) {
					int gray = srcImage.at<uchar>(i + dx[k], j + dy[k]);
					d[k] = gray;
				}
				dst.at<uchar>(i, j) = bubbleSort(d, 9);
			}
			else {
				int gray = srcImage.at<uchar>(i, j);
				dst.at<uchar>(i, j) = gray;
			}	
		}
	}
}

//主函数
int main()
{
	Mat srcImage;
	srcImage = imread("1.jpg",0);
	Mat dst;
	dst=median_filter(srcImage)
	imshow("中值滤波", dst);
	imshow("显示图像", srcImage);
	waitKey(0);
	return 0;
}

