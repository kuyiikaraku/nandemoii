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
int main()
{
	int n;
	cout << "������n\n";
	cin >> n;
	if (n <= 1)
	{
		cout << "���������";
		return -1;
	}
	double* x = new double [n];
	cout << "������x\n";
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		sum += x[i];
	}
	double x_ave = sum / n;
	cout << "ƽ��ֵΪ��" << x_ave << '\n';
	double d_sum = 0;
	for (int i = 0; i < n; i++)
	{
		d_sum += (x[i] - x_ave) * (x[i] - x_ave);
	}
	double s = pow(d_sum / (n - 1), 0.5);
	cout << "�ɱ�������ʽ����ı�׼ƫ��Ϊ:" << s << "\n";
	double t = t_confidence(n);
	double s_corrected = s * t;
	cout << "����t�ֲ�����������ı�׼��Ϊ��" << s_corrected << '\n';
	delete[]x;
	system("pause");
	return 0;
}