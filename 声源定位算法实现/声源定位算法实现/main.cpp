#include<iostream>
#include<vector>
#include <stdio.h>
#include<fstream>
#include"f1.h"
using namespace std;

int main()
{
	int i;
	
	//fsΪ�����ʣ�micΪ������λ�ã�nΪ������Դ������rΪ����ϵ����rmΪ�����С��srcΪ��Դλ��
	int fs = 44100;
	vector<double>mic = { 1,1.5,1 };
	int n = 5;
	double r = 0.4;
	vector<double>rm = { 6,3,3 };
	vector<double>src = { 4,1,1.5 };

	//�������ػ���ģ�͵�ģ�⴫�����������ź�
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
