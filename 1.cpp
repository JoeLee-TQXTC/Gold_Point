//如果a[]是黄金点的历史值数组，a[k]为最新的黄金点
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<iomanip>
#include<math.h>

long double HuiGuiJiSuan(double a[], int k, int n)//使用n个数据组筛除异常数据后线性回归预测下一个值中点。
{
	double w = 0, b = 0,  nx = 0;//设线性回归方程为y=wx+b,nx为有效数据组数
	double sum = 0, SUMx_y = 0, SUMx2 = 0, SUMx = 0, SUMy = 0, aver = 0, m = 0, x = 0;/*sum为所有黄金点之和，aver为所有黄金点平均值，SUMx_y为xi*yi累积, SUMx2为xi^2累积, SUMx为xi累积, SUMy为yi累积,m计算标准差。*/
	for (int i = k+1-n; i <= k; ++i)//计算黄金点数据的总和
	{
		sum += a[i];
	}
	aver = sum / n;//计算黄金点平均值
	for (int i = k - 9; i <= k; ++i)
	{
		x = a[i] - aver;
		x *= x;
		m += x;
	}
	m = sqrt(m / n);//得到黄金点数据的标准差
	for (int i = k - 9; i <= k; ++i)
	{
		if ((aver - m) <= a[i] && a[i] <= (aver + m))//筛选有效数据
		{
			SUMx_y += (a[i] * i);
			SUMx2 += (i*i);
			SUMx += i;
			SUMy += a[i];
			++nx;
		}
	}
	w = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
	b = SUMy / nx - w * SUMx / nx;//得出n个数据的线性回归方程
	return (k+1)*w + b;
}


 long double PointCentre(double a[], int k)
{
	double t1 =0,t2=0, c =0, d = 0,sum=0,SUMx_y=0,SUMx2=0,SUMx=0,SUMy=0,aver=0,m=0,x=0, n=0;//t记录差值,b,c,d记录比例,n为数据组数
	double w = 0, b = 0,w1=0,w2=0,w3=0,b1=0,b2=0,b3=0,nx=0;//设线性回归方程为y=wx+b,nx为有效数据组数
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
		for (int i = 4; i <= k; ++i)//计算黄金点数据的总和
		{
			sum += a[i];
			++n;
		}
		aver = sum / n;//计算黄金点平均值
		for (int i = 4; i <= k; ++i)
		{
			x = a[i] - aver;
			x *= x;
			m += x;
		}
		m = sqrt(m/n);//得到黄金点数据的标准差
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
		b = SUMy / nx - w * SUMx / nx;//得出线性回归方程
		return (w * (k + 1) + b);
	}
	else
	{
		double KPlusOne[6];
		KPlusOne[0]=HuiGuiJiSuan(a, k, 30);
		//for (int i = k - 29; i <= k; ++i)//计算黄金点数据的总和
		//{
		//	sum += a[i];
		//	n = 30;
		//}
		//aver = sum / n;//计算黄金点平均值
		//for (int i = k - 29; i <= k; ++i)
		//{
		//	x = a[i] - aver;
		//	x *= x;
		//	m += x;
		//}
		//m = sqrt(m / n);//得到黄金点数据的标准差
		//for (int i = k - 29; i <= k; ++i)
		//{
		//	if ((aver - m) <= a[i] && a[i] <= (aver + m))//筛选有效数据
		//	{
		//		SUMx_y += (a[i] * i);
		//		SUMx2 += (i*i);
		//		SUMx += i;
		//		SUMy += a[i];
		//		++nx;
		//	}
		//}
		//w3 = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
		//b3 = SUMy / nx - w * SUMx / nx;//得出30数据线性回归方程
		KPlusOne[1] = HuiGuiJiSuan(a, k, 25);
		KPlusOne[2] = HuiGuiJiSuan(a, k, 20);
		//for (int i = k-19; i <= k; ++i)//计算黄金点数据的总和
		//{
		//	sum += a[i];
		//	n = 20;
		//}
		//aver = sum / n;//计算黄金点平均值
		//for (int i = k - 19; i <= k; ++i)
		//{
		//	x = a[i] - aver;
		//	x *= x;
		//	m += x;
		//}
		//m = sqrt(m / n);//得到黄金点数据的标准差
		//for (int i = k - 19; i <= k; ++i)
		//{
		//	if ((aver - m) <= a[i] && a[i] <= (aver + m))//筛选有效数据
		//	{
		//		SUMx_y += (a[i] * i);
		//		SUMx2 += (i*i);
		//		SUMx += i;
		//		SUMy += a[i];
		//		++nx;
		//	}
		//}
		//w2 = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
		//b2 = SUMy / nx - w * SUMx / nx;//得出20数据线性回归方程
		KPlusOne[3] = HuiGuiJiSuan(a, k, 15);
		KPlusOne[4] = HuiGuiJiSuan(a, k, 10);
		//for (int i = k - 9; i <= k; ++i)//计算黄金点数据的总和
		//{
		//	sum += a[i];
		//	n = 10;
		//}
		//aver = sum / n;//计算黄金点平均值
		//for (int i = k - 9; i <= k; ++i)
		//{
		//	x = a[i] - aver;
		//	x *= x;
		//	m += x;
		//}
		//m = sqrt(m / n);//得到黄金点数据的标准差
		//for (int i = k - 9; i <= k; ++i)
		//{
		//	if ((aver - m) <= a[i] && a[i] <= (aver + m))//筛选有效数据
		//	{
		//		SUMx_y += (a[i] * i);
		//		SUMx2 += (i*i);
		//		SUMx += i;
		//		SUMy += a[i];
		//		++nx;
		//	}
		//}
		//w1 = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx);
		//b1 = SUMy / nx - w * SUMx / nx;//得出10数据线性回归方程
		return HuiGuiJiSuan(KPlusOne, 4, 5);
	}
}






