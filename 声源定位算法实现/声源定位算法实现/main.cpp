#include<iostream>
#include<vector>
#include <stdio.h>
#include<fstream>
#include"f1.h"
using namespace std;

int main()
{
	int i;
	
	//fs为采样率；mic为传感器位置；n为虚拟声源个数；r为反射系数；rm为房间大小；src为声源位置
	int fs = 44100;
	vector<double>mic = { 1,1.5,1 };
	int n = 5;
	double r = 0.4;
	vector<double>rm = { 6,3,3 };
	vector<double>src = { 4,1,1.5 };

	//函数返回回响模型的模拟传感器的脉冲信号
	vector<double>h;
	h = rir(fs, mic, n, r, rm, src);
	ofstream file;
	file.open("demo.csv");
	for (i = 0; i < h.size(); i++)
	{
		file << h[i] << endl;
	}
	file.close();
	return 0;
}
