// OpenCV3Learning.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Trace.h"
#include <iostream>
#include <malloc.h>
//#include <fstream>
#include <string.h>
#include "MyString.h"
#include "Vehicle.h"
#include "Timer.h"
#include <Windows.h>
#include "Expr_node.h"
#include "Expr.h"
#include "Picture.h"
#include <string>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	const string windowName = "video";
	Mat img = imread("D:\\FGGather.jpg");
	namedWindow(windowName, WindowFlags::WINDOW_AUTOSIZE);
	imshow(windowName, img);
	waitKey(0);
	return 0;
}












const string imageFile = "D:\\FGGather.jpg";
const string cvLogoFile = "C:\\opencv-3.3.0-vc14\\sources\\doc\\opencv-logo.png";

int g_nContrastValue;
int g_nBrightValue;
Mat g_srcImage, g_dstImage;



int main_vc6() 
{
	Mat T = Mat_<double>::zeros(3, 2);
	Mat R = Mat_<uchar>::eye(3,3);
	FileStorage fs;
	fs.open("D:\\1.xml",FileStorage::WRITE);
	fs << "name" << "小明" ;
	//fs << "age" << 16;
	fs << "R" << R;
	fs << "T" << T;
	fs.release();
	return 0;
}




static void on_ContrastAndBright(int, void*)
{
	//namedWindow("原始图像",1);
	for (size_t r = 0; r < g_srcImage.rows; r++)
	{
		for (size_t c = 0; c < g_srcImage.cols; c++)
		{
			for (size_t i = 0; i < g_srcImage.channels(); i++)
			{
				g_dstImage.at<Vec3b>(r, c)[i] = saturate_cast<uchar>((g_nContrastValue*0.01)*g_srcImage.at<Vec3b>(r,c)[i]+g_nBrightValue);
			}
		}
	}

	imshow("原始图像",g_srcImage);
	imshow("效果图", g_dstImage);
}

int main_vc5()
{
	g_srcImage = imread(imageFile);

	g_dstImage = Mat::zeros(g_srcImage.size(),g_srcImage.type());
	g_nBrightValue = 80;
	g_nContrastValue = 80;

	namedWindow("效果图",1);
	createTrackbar("对比度：", "效果图", &g_nContrastValue, 300, on_ContrastAndBright);
	createTrackbar("亮  度：", "效果图", &g_nContrastValue, 200, on_ContrastAndBright);

	on_ContrastAndBright(g_nContrastValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (char(waitKey(1))!='q')
	{

	}
	return 0;
}





int main_cv4()
{
	Mat srcImage,logoImage,imageROI;
	srcImage = imread(imageFile);
	logoImage = imread(cvLogoFile);

	imageROI = srcImage(Rect(0, 0,100,100));

	Mat mask = imread(cvLogoFile,0);

	logoImage.copyTo(imageROI);

	imshow("Result",srcImage);

	namedWindow(" ");
	waitKey(0);
	return 0;
}


#pragma region 像素的3种常用操作方式
void colorReduce(const Mat& inputImage, Mat & outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols*outputImage.channels();
	for (size_t i = 0; i < rowNumber; i++)
	{
		uchar* data = outputImage.ptr<uchar>(i);
		for (size_t j = 0; j < colNumber; j++)
		{
			data[j] = data[j] / div*div + div / 2;
		}
	}
}

void colorReduce2(const Mat& inputImage, Mat & outputImage, int div)
{
	outputImage = inputImage.clone();
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();

	for (; it != itend; ++it)
	{
		for (size_t i = 0; i < 3; i++)
		{
			(*it)[i] = (*it)[i] / div*div + div / 2;
		}
	}
}

void colorReduce3(const Mat& inputImage, Mat & outputImage, int div)
{
	outputImage = inputImage.clone();
	int rowNumber = outputImage.rows;
	int colNumber = outputImage.cols;
	for (size_t i = 0; i < rowNumber; i++)
	{
		for (size_t j = 0; j < colNumber; j++)
		{
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div*div + div / 2;
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div*div + div / 2;
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div*div + div / 2;
		}
	}
}

#pragma endregion
int main_cv3()
{
	Mat srcImage = imread("D:\\FGGather.jpg");
	imshow("Raw",srcImage);

	Mat dstImage;
	dstImage.create(srcImage.size(), srcImage.type());

	double time0 = static_cast<double>(getTickCount());

	//colorReduce(srcImage, dstImage, 32);
	//colorReduce2(srcImage, dstImage, 32);
	colorReduce3(srcImage, dstImage, 32);
	double time1 = static_cast<double>(getTickCount());

	cout << "耗时：" << (time1 - time0) / getTickFrequency() << endl;

	imshow("Result",dstImage);

	namedWindow("");
	waitKey(0);


	return 0;
}




int main_cv2()
{
	Mat m(2,3,CV_8UC3,Scalar(255,255,0));
	cout << "M=" << endl
		<< m << endl;
	cout << "Step=" << m.step << endl;
	cout << "Size=" << m.size << endl;
	
	waitKey(0);
	return 0;
}


int main_cv1() {
	const string windowName = "video";
	const string file = "D:\\FGGather.jpg";
	Mat srcImage, dstImage;
	Mat map_x, map_y;
	srcImage = imread(file, 1);
	if (!srcImage.data)
	{
		cout << "read image error" << endl;
		return 0;
	}
	//namedWindow(windowName);
	imshow(windowName,srcImage);
	//waitKey(0);
	dstImage.create(srcImage.size(), srcImage.type());

	map_x.create(srcImage.size(),CV_32FC1);
	map_y.create(srcImage.size(), CV_32FC1);
	for (size_t i = 0; i < srcImage.rows ; i++)
	{
		for (size_t j = 0; j < srcImage.cols; j++)
		{
			map_x.at<float>(i, j) = static_cast<float>(j);
			map_y.at<float>(i, j) = static_cast<float>(srcImage.rows-i);
		}
	}
	remap(srcImage,dstImage,map_x,map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
	imshow("Result",dstImage);
	namedWindow("");

	waitKey(0);
	//system("pause");
	return 0;

}

int main_cv0()
{
	const string windowName = "video";
	Mat img = imread("D:\\FGGather.jpg");
	namedWindow(windowName,WindowFlags::WINDOW_AUTOSIZE);
	imshow(windowName,img);
	waitKey(0);
	destroyWindow(windowName);
	//waitKey(5000);
	//system("pause");
	return 0;
}

int main8()
{
	char * init[] = {"Paris","int the","Spring"};

	Picture p(init,3);
	cout << p << endl;
	Picture q = p;
	cout << q << endl;
	Picture f = frame(p);
	cout << f << endl;
	cout << frame((p & f)) << endl;
	cout << frame((p | f)) << endl;

	system("pause");
	return 0;
}

int main7()
{
	//Binary_node* t = new Binary_node("*",new Unarry_node("-",new Int_node(5)),new Binary_node("+",new Int_node(3),new Int_node(4)));
	//cout << *t << endl;
	Expr t = Expr("*",Expr("-",5),Expr("+",3,4));
	cout << t << endl;
	cout << t.eval() << endl;
	system("pause");
	return 0;
}


int main6()
{
	CTimer timer;
	timer.start();
	Sleep(5000);
	timer.stop();
	timer.print();
	system("pause");
	return 0;
}

int main5() {

	VehicleSurrogate parking_lot[10];
	AutoVehicle av;

	printf("AutoVehicle %x\n",&av);

	parking_lot[0] = av;


	

	system("pause");
	return 0;
}

int main4() {

	const char * hello = "hello";
	printf("%x\n", &hello);
	MyString s(hello);
	s.Print();

	system("pause");
	return 0;
}

int main2()
{
	
	char *p;

	p = (char *)malloc(100);
	if (p)
		printf("Memory Allocated at: %x\n", p);
	else
		printf("Not Enough Memory!\n");
	free(p);
	

	char a[20];
	memset(a, 0, sizeof(char) * 20);
	strcpy(a, "123");


	size_t length =strlen(a);
	std::cout << a <<std::endl;
	std::cout << length << std::endl;
	std::cout << sizeof(a) << std::endl;
	char hello[] = "hello";
	char world[] = "world";
	//char * helloWorld;
	//helloWorld = strcat(hello,world);
	
	//std::cout << helloWorld << std::endl;
	system("pause");
	return 0;
}


int main0()
{

	//stdio.h
	char *fileName= "D:\\MyWork\\trace.txt";
	FILE* f;
	//f = fopen(fileName, "w+");
	fopen_s(&f, fileName, "a+");

	Trace t(f);
	//Trace t(stdout);

	t.on();

	t.Print("strat main");

	t.Print("end main");

	t.off();

	fclose(f);
	system("pause");
    return 0;
}

