#include<iostream>
#include<vector>
using namespace std;

//函数返回回响模型的模拟传感器的脉冲信号
//fs为采样率；mic为传感器位置；n为虚拟声源个数；r为反射系数；rm为房间大小；src为声源位置
vector<double>rir(int fs, vector<double>mic, int n, double r,
	vector<double>rm, vector<double>src);

