#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

vector<double>rir(int fs, vector<double>mic, int n, double r, vector<double>rm, vector<double>src)
{
	vector<int>nn;
	int i;
	for (i = -n; i <= n; i++)
	{
		nn.push_back(i);
	}
	vector<double>rms, srcs, xi, yj, zk;
	for (i = 0; i < nn.size(); i++)
	{
		rms.push_back(nn[i] + 0.5 - 0.5 * pow(-1, nn[i]));
		srcs.push_back(pow(-1, nn[i]));
	}
	for (i = 0; i < nn.size(); i++)
	{
		xi.push_back(srcs[i] * src[0] + rms[i] * rm[0] - mic[0]);
		yj.push_back(srcs[i] * src[1] + rms[i] * rm[1] - mic[1]);
		zk.push_back(srcs[i] * src[2] + rms[i] * rm[2] - mic[2]);
	}
	typedef vector<vector<vector<double>>> vector3;
	vector3 d(nn.size(), vector<vector<double>>(nn.size(), vector<double>(nn.size(), 0)));
	vector3 li(nn.size(), vector<vector<double>>(nn.size(), vector<double>(nn.size(), 0)));
	vector3 lj(nn.size(), vector<vector<double>>(nn.size(), vector<double>(nn.size(), 0)));
	vector3 lk(nn.size(), vector<vector<double>>(nn.size(), vector<double>(nn.size(), 0)));
	vector3 time(nn.size(), vector<vector<double>>(nn.size(), vector<double>(nn.size(), 0)));
	vector3 c(nn.size(), vector<vector<double>>(nn.size(), vector<double>(nn.size(), 0)));
	vector3 e(nn.size(), vector<vector<double>>(nn.size(), vector<double>(nn.size(), 0)));
	int j, k;
	for(i=0;i<nn.size();i++)
		for (j = 0; j < nn.size(); j++)
			for (k = 0; k < nn.size(); k++)
			{
				li[i][j][k] = xi[i];
				lj[i][j][k] = yj[j];
				lk[i][j][k] = zk[k];
			}
	for (i = 0; i < nn.size(); i++)
		for (j = 0; j < nn.size(); j++)
			for (k = 0; k < nn.size(); k++)
			{
				d[i][j][k] = sqrt(li[i][j][k]* li[i][j][k]+ lj[i][j][k]* lj[i][j][k]+ lk[i][j][k]* lk[i][j][k]);
				double tem = fs * d[i][j][k] / 343;
				int temi;
				if (tem - int(tem) >= 0.5)temi = int(tem) + 1;
				else temi = int(tem);
				time[i][j][k] = temi + 1;
				c[i][j][k] = pow(r, abs(i) + abs(j) + abs(k));
				e[i][j][k] = c[i][j][k] / d[i][j][k];
			}

	vector<int> tempT;
	for (i = 0; i < nn.size(); i++)
		for (j = 0; j < nn.size(); j++)
			for (k = 0; k < nn.size(); k++)
			{
				tempT.push_back(time[i][j][k]);
			}
	int maxLength = *max_element(tempT.begin(), tempT.end());

	vector<double>h(maxLength, 0);
	for (i = 0; i < nn.size(); i++)
		for (j = 0; j < nn.size(); j++)
			for (k = 0; k < nn.size(); k++)
			{
				h[time[i][j][k] - 1] += e[i][j][k];
			}
	return h;
}