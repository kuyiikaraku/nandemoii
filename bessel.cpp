#include<iostream>
using namespace std;
double t_confidence(int n)
{
	double t;
	if (n == 2)
	{
		t = 1.84;
	}
	else if (n == 3)
	{
		t = 1.32;
	}
	else if (n == 4)
	{
		t = 1.20;
	}
	else if (n==5)
	{
		t = 1.14;
	}
	else if (n==6)
	{
		t = 1.11;
	}
	else if (n==7)
	{
		t = 1.09;
	}
	else if (n==8)
	{
		t = 1.08;
	}
	else if (n==9)
	{
		t = 1.07;
	}
	else if (n==10)
	{
		t = 1.06;
	}
	else if (n==11)
	{
		t = 1.05;
	}
	else if (n==12)
	{
		t = 1.03;
	}
	return t;
}
bool bad_judge(double x , double s_corrcted,double x_ave)
{
	if (x <= x_ave + 3 * s_corrcted || x >= x_ave + 3 * s_corrcted)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n;
	cout << "请输入n\n";
	cin >> n;
	if (n <= 1)
	{
		cout << "错误的输入";
		return -1;
	}
	double* x = new double [n];//需计算的数据
	
	cout << "请输入仪器不确定度\n";
	double instrument;//仪器不确定度
	cin >> instrument;
	cout << "请输入x\n";
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		sum += x[i];
	}
	double x_ave = sum / n;//平均值
	cout << "平均值为：" << x_ave << '\n';
	double d_sum = 0;
	for (int i = 0; i < n; i++)
	{
		d_sum += (x[i] - x_ave) * (x[i] - x_ave);//每一值与平均值差值的平方和
	}
	double s = pow(d_sum / (n - 1), 0.5);//贝塞尔公式求出的标准差
	cout << "由贝塞尔公式求出的标准偏差为:" << s << "\n";
	double t = t_confidence(n);//t分布因子
	double s_corrected = s * t;//经t修饰过后的标准差
	cout << "经过t分布因子修正后的标准差为：" << s_corrected << '\n';
	for (int i = 0; i < n; i++)//检测是否有坏值
	{
		if (!bad_judge(x[i], s_corrected, x_ave))
		{
			cout << x[i] << "是坏值，应去除\n";
		}
	}
	double sigma_a = t * s / pow(n, 0.5);//不确定度的A类分量
	cout << "不确定度的A类分量为：" << sigma_a << '\n';
	double sigma_b = instrument / pow(3, 0.5);
	cout << "不确定度的B类分量为：" << sigma_b << '\n';//不确定度的B类分量
	double uncertainty = pow((sigma_a * sigma_a + sigma_b * sigma_b), 0.5);//不确定度
	cout << "不确定度为：" << uncertainty << '\n';
	
	delete[]x;
	system("pause");
	return 0;
}