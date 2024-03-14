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
	cout << "������n\n";
	cin >> n;
	if (n <= 1)
	{
		cout << "���������";
		return -1;
	}
	double* x = new double [n];//����������
	
	cout << "������������ȷ����\n";
	double instrument;//������ȷ����
	cin >> instrument;
	cout << "������x\n";
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		sum += x[i];
	}
	double x_ave = sum / n;//ƽ��ֵ
	cout << "ƽ��ֵΪ��" << x_ave << '\n';
	double d_sum = 0;
	for (int i = 0; i < n; i++)
	{
		d_sum += (x[i] - x_ave) * (x[i] - x_ave);//ÿһֵ��ƽ��ֵ��ֵ��ƽ����
	}
	double s = pow(d_sum / (n - 1), 0.5);//��������ʽ����ı�׼��
	cout << "�ɱ�������ʽ����ı�׼ƫ��Ϊ:" << s << "\n";
	double t = t_confidence(n);//t�ֲ�����
	double s_corrected = s * t;//��t���ι���ı�׼��
	cout << "����t�ֲ�����������ı�׼��Ϊ��" << s_corrected << '\n';
	for (int i = 0; i < n; i++)//����Ƿ��л�ֵ
	{
		if (!bad_judge(x[i], s_corrected, x_ave))
		{
			cout << x[i] << "�ǻ�ֵ��Ӧȥ��\n";
		}
	}
	double sigma_a = t * s / pow(n, 0.5);//��ȷ���ȵ�A�����
	cout << "��ȷ���ȵ�A�����Ϊ��" << sigma_a << '\n';
	double sigma_b = instrument / pow(3, 0.5);
	cout << "��ȷ���ȵ�B�����Ϊ��" << sigma_b << '\n';//��ȷ���ȵ�B�����
	double uncertainty = pow((sigma_a * sigma_a + sigma_b * sigma_b), 0.5);//��ȷ����
	cout << "��ȷ����Ϊ��" << uncertainty << '\n';
	
	delete[]x;
	system("pause");
	return 0;
}