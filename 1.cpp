//���a[]�ǻƽ�����ʷֵ���飬a[k]Ϊ���µĻƽ��
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<iomanip>
#include<math.h>
double m = 0;//m�����׼�
long double HuiGuiJiSuan(double a[], int k, int n)//ʹ��n��������ɸ���쳣���ݺ����Իع�Ԥ����һ��ֵ�е㡣
{
	double w = 0, b = 0,  nx = 0;//�����Իع鷽��Ϊy=wx+b,nxΪ��Ч��������
	double sum = 0, SUMx_y = 0, SUMx2 = 0, SUMx = 0, SUMy = 0, aver = 0, x = 0;/*sumΪ���лƽ��֮�ͣ�averΪ���лƽ��ƽ��ֵ��SUMx_yΪxi*yi�ۻ�, SUMx2Ϊxi^2�ۻ�, SUMxΪxi�ۻ�, SUMyΪyi�ۻ�,m�����׼�*/
	for (int i = k+1-n; i <= k; ++i)//����ƽ�����ݵ��ܺ�
	{
		sum += a[i];
	}
	aver = sum / n;//����ƽ��ƽ��ֵ
	for (int i = k+1-n; i <= k; ++i)
	{
		x = a[i] - aver;
		x *= x;
		m += x;
	}
	m = sqrt(m / n);//�õ��ƽ�����ݵı�׼��
	for (int i = k+1-n; i <= k; ++i)
	{
		if ((aver - m) <= a[i] && a[i] <= (aver + m))//ɸѡ��Ч����
		{
			SUMx_y += (a[i] * i);
			SUMx2 += (i*i);
			SUMx += i;
			SUMy += a[i];
			++nx;
		}
	}
	w = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
	b = SUMy / nx - w * SUMx / nx;//�ó�n�����ݵ����Իع鷽��
	return (k+1)*w + b;
}


 long double PointCentre(double a[], int k)
{
	double t1 =0,t2=0, c =0, d = 0,sum=0,SUMx_y=0,SUMx2=0,SUMx=0,SUMy=0,aver=0,m=0,x=0, n=0;//t��¼��ֵ,b,c,d��¼����,nΪ��������
	double w = 0, b = 0,w1=0,w2=0,w3=0,b1=0,b2=0,b3=0,nx=0;//�����Իع鷽��Ϊy=wx+b,nxΪ��Ч��������
	if (k =0)
	{
		return a[0] * 0.6;
	}
	else if (k = 1)
	{
		t1 = a[0] - a[1];
		t1 *= 0.5;
		return a[1] - t1;
	}
	else if (k <= 3)
	{
		t1 = a[k-2] - a[k-1];
		t1 *= 0.5;
		t2 = a[k - 1] - a[k];
		b = t2 / t1;
		c = b * b;
		return a[k] * c*t2;
	}
	else if ()
	{

	}
	else if (k <= 30)
	{
		for (int i = 4; i <= k; ++i)//����ƽ�����ݵ��ܺ�
		{
			sum += a[i];
			++n;
		}
		aver = sum / n;//����ƽ��ƽ��ֵ
		for (int i = 4; i <= k; ++i)
		{
			x = a[i] - aver;
			x *= x;
			m += x;
		}
		m = sqrt(m/n);//�õ��ƽ�����ݵı�׼��
		for (int i = 4; i <= k; ++i)
		{
			if ((aver - m) <= a[i] && a[i] <= (aver + m))
			{
				SUMx_y += (a[i] * i);
				SUMx2 += (i*i);
				SUMx += i;
				SUMy += a[i];
				++nx;
			}
		}
		w = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
		b = SUMy / nx - w * SUMx / nx;//�ó����Իع鷽��
		return (w * (k + 1) + b);
	}
	else
	{
		double KPlusOne[6];
		KPlusOne[0]=HuiGuiJiSuan(a, k, 30);
		//for (int i = k - 29; i <= k; ++i)//����ƽ�����ݵ��ܺ�
		//{
		//	sum += a[i];
		//	n = 30;
		//}
		//aver = sum / n;//����ƽ��ƽ��ֵ
		//for (int i = k - 29; i <= k; ++i)
		//{
		//	x = a[i] - aver;
		//	x *= x;
		//	m += x;
		//}
		//m = sqrt(m / n);//�õ��ƽ�����ݵı�׼��
		//for (int i = k - 29; i <= k; ++i)
		//{
		//	if ((aver - m) <= a[i] && a[i] <= (aver + m))//ɸѡ��Ч����
		//	{
		//		SUMx_y += (a[i] * i);
		//		SUMx2 += (i*i);
		//		SUMx += i;
		//		SUMy += a[i];
		//		++nx;
		//	}
		//}
		//w3 = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
		//b3 = SUMy / nx - w * SUMx / nx;//�ó�30�������Իع鷽��
		KPlusOne[1] = HuiGuiJiSuan(a, k, 25);
		KPlusOne[2] = HuiGuiJiSuan(a, k, 20);
		//for (int i = k-19; i <= k; ++i)//����ƽ�����ݵ��ܺ�
		//{
		//	sum += a[i];
		//	n = 20;
		//}
		//aver = sum / n;//����ƽ��ƽ��ֵ
		//for (int i = k - 19; i <= k; ++i)
		//{
		//	x = a[i] - aver;
		//	x *= x;
		//	m += x;
		//}
		//m = sqrt(m / n);//�õ��ƽ�����ݵı�׼��
		//for (int i = k - 19; i <= k; ++i)
		//{
		//	if ((aver - m) <= a[i] && a[i] <= (aver + m))//ɸѡ��Ч����
		//	{
		//		SUMx_y += (a[i] * i);
		//		SUMx2 += (i*i);
		//		SUMx += i;
		//		SUMy += a[i];
		//		++nx;
		//	}
		//}
		//w2 = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
		//b2 = SUMy / nx - w * SUMx / nx;//�ó�20�������Իع鷽��
		KPlusOne[3] = HuiGuiJiSuan(a, k, 15);
		KPlusOne[4] = HuiGuiJiSuan(a, k, 10);
		//for (int i = k - 9; i <= k; ++i)//����ƽ�����ݵ��ܺ�
		//{
		//	sum += a[i];
		//	n = 10;
		//}
		//aver = sum / n;//����ƽ��ƽ��ֵ
		//for (int i = k - 9; i <= k; ++i)
		//{
		//	x = a[i] - aver;
		//	x *= x;
		//	m += x;
		//}
		//m = sqrt(m / n);//�õ��ƽ�����ݵı�׼��
		//for (int i = k - 9; i <= k; ++i)
		//{
		//	if ((aver - m) <= a[i] && a[i] <= (aver + m))//ɸѡ��Ч����
		//	{
		//		SUMx_y += (a[i] * i);
		//		SUMx2 += (i*i);
		//		SUMx += i;
		//		SUMy += a[i];
		//		++nx;
		//	}
		//}
		//w1 = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
		//b1 = SUMy / nx - w * SUMx / nx;//�ó�10�������Իع鷽��
		return HuiGuiJiSuan(KPlusOne, 4, 5);
	}
}
//�Ҹ�����Ϊ�����ǿ�����Ҫ����׼����ʱ��׼������һ���Ź��ർ�����Ǽ���ı���ֵ���䱻����ĸ�������Ӱ�쵼�´������ƣ���ʱʱ��׼�������߱���PointCentre���������ֶ������ֵ�����жϡ�



//�����������ʱ�������յ�����ѡ�������о���
//def SuiJiShuHanShu ()
//import random
//return random

double GanRaoJiLv(double a[], int k, long double PointCentreKPlusOne, double m)
{
	if (a[k] <= (PointCentreKPlusOne - m * 0.6667))
	{
		return 0.9;
	}//����һ�������ֵһ��Ҫ���Խ��и��ţ�
	else if (a[k] <= (PointCentreKPlusOne + m * 0.3333))
	{
		return (PointCentreKPlusOne + m * 0.3333 - a[k])*0.9 / m;
	}//�ڱ���ֵ���䣬�ɸ���ʵʱֵ�Ĵ�С�����и��ţ�ʵʱֵԽС��������һ�ֽ��и��ŵļ���Խ��
	else if (a[k] < (PointCentreKPlusOne + 1.8 * m))
	{
		return 0;
	}
	else if (a[k] > PointCentreKPlusOne + t * m)//ʶ�𱻸��ź�ƽ��
	{
		if (a[k - 1] > PointCentreKPlusOne + t * m)//����Ѿ����������Σ���ȡ�������ԣ����ڲ��ɳ����������ŵ㣩
		{
			if (a[k] < PointCentreKPlusOne + T * m)//������ų̶Ȳ����أ��ƽ����HighestLine��һ�����룬���Կ��ǽ�һ�θ���
			{
				return 0.5;
			}
			else//���ŵ�������������
			{
				return 0;
			}
		}
		else//һ�θ��ſ��ǽ���׷�Ӷ��θ���
		{
			return 0.73;
		}
	}
	else
	{
		return 0��
	}
}

double X1, X2;//X1,X2Ϊ���������ύ�����ݣ�����X1ֻ��Ԥ�⣬�������ţ�X2ż��Ԥ�⣬�����ǽ��и��ţ�
int main()
{
	long double n = PointCentre(a[k], k);
	double k = GanRaoJiLv(a[k], k, n, m);

	t = random(1��0);//����1~0֮�����������������ȡ��������ѡ�õ����ԣ�

	if (t <= k)
	{
		X2 = 99;
		X1=
	}
}





