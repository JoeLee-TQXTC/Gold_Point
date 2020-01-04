//如果a[]是黄金点的历史值数组，a[k]为最新的黄金点
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<math.h>
double m = 0;//m计算标准差；
int i = 0;
long double t;
long double T1 = 0.8, T2 = 1.5;//T1和T2最好做成能我到时候能紧急手动输入的。。。。hhhh怕情况有变23333
inline long double HuiGuiJiSuan(double a[], int k, int n)//使用n个数据组筛除异常数据后线性回归预测下一个值中点。
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
	static double m = 0;//m为标准差
	double t1 =0,t2=0, c =0, d = 0,sum=0,SUMx_y=0,SUMx2=0,SUMx=0,SUMy=0,aver=0,x=0, n=0;//t记录差值,b,c,d记录比例,n为数据组数
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
		double KPlusOne[8];
		double KPlusOne[0]=HuiGuiJiSuan(a[k], k, 30);
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
		double KPlusOne[1] = HuiGuiJiSuan(a[k], k, 25);
		double KPlusOne[2] = HuiGuiJiSuan(a[k], k, 20);
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
		double KPlusOne[3] = HuiGuiJiSuan(a[k], k, 15);
		double[4] = HuiGuiJiSuan(a, k, 10);
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
//我个人认为，我们可能需要两手准备，时刻准备好万一干扰过多导致我们计算的保守值区间被过多的干扰数据影响导致大盘上移，此时时刻准备好上线备用PointCentre函数改用手动输出中值进行判断。

//随机数函数到时候由最终的语言选择来进行决定
//def SuiJiShuHanShu ()
//import random
//return random

double GanRaoJiLv(double a[], int k, long double PointCentreKPlusOne, double m)
{
	if (a[k] <= (PointCentreKPlusOne - m * 0.6667))
	{
		return 0.9;
	}//低于一个最低阈值一定要尝试进行干扰；
	else if (a[k] <= (PointCentreKPlusOne + m * 0.3333))
	{
		return (PointCentreKPlusOne + m * 0.3333 - a[k])*0.9 / m;
	}//在保守值区间，可根据实时值的大小来进行干扰，实时值越小，决定下一轮进行干扰的几率越大。
	else if (a[k] < (PointCentreKPlusOne + 1.8 * m))
	{
		return 0;
	}
	else if (a[k] > PointCentreKPlusOne +T1 * m)//识别被干扰后黄金点
	{
		if (a[k - 1] > PointCentreKPlusOne + T1 * m)//如果已经被干扰两次（采取谨慎策略，由于不可超过三个干扰点）
		{
			if (a[k] < PointCentreKPlusOne + T2 * m)//如果干扰程度不严重，黄金点离HighestLine有一定距离，可以考虑接一段干扰
			{
				return 0.5;
			}
			else//干扰点过高则放弃干扰
			{
				return 0;
			}
		}
		else//一次干扰考虑进行追加二次干扰
		{
			return 0.73;
		}
	}
	else
	{
		return 0;
	}
}


double W[2000];//记录干扰点与上一点的比例
void Setting_w(double a[], int k)
{
	double doubleSUM = 0;
	int num = 1;
	double w = 0, b = 0, nx = 0;//设线性回归方程为y=wx+b,nx为有效数据组数
	double sum = 0, SUMx_y = 0, SUMx2 = 0, SUMx = 0, SUMy = 0, aver = 0, x = 0, m0 = 0;/*sum为所有黄金点之和，aver为所有黄金点平均值，SUMx_y为xi*yi累积, SUMx2为xi^2累积, SUMx为xi累积, SUMy为yi累积,m计算标准差。*/
	int n;
	if (k <= 49)
	{
		n = 0.8*k;
	}
	else
	{
		n = 40;
	}
	for (int i = k + 1 - n; i <= k; ++i)//计算黄金点数据的总和
	{
		sum += a[i];
	}
	aver = sum / n;//计算黄金点平均值
	for (int i = k + 1 - n; i <= k; ++i)
	{
		x = a[i] - aver;
		x *= x;
		m0 += x;
	}
	m0 = sqrt(m0 / n);//得到黄金点数据的判断标准差
	for(int i = 0; i < n; ++i)
	{
		if (a[k - i] >= sum + 0.8*m0)
		{
			W[num] = double(a[k - i] / a[k - i - 1]);
			doubleSum += W[num]*W[num];
			++num;
			w += W[num] * W[num] * W[num];
			w /= doubleSUM;
		}
	}
}



double X1, X2;//X1,X2为我们最终提交的数据，其中X1只做预测，不做干扰，X2偶尔预测，作用是进行干扰；
int main()
{
	srand((unsigned)time(NULL));
	long double n = PointCentre(a, k);
	double k0 = GanRaoJiLv(a, k, n, m);
	bool GanRao = 0;
	long double Tt = rand() / double(RAND_MAX);//生成1~0之间的随机数，具体语句取决于最终选用的语言；
	Setting_w();
	if (Tt <= k0)
	{
		GanRao = 1;
		X2 = 99;
		if ((n*0.7*w <= a[k]) && (n*1.5*w >= a[k]))
		{
			X1 = a[k] * sqrt(w);
		}
		else
		{
			X1 = a[k]*w;
		}
	}
	else
	{
		GanRao = 0;
		X1 = n * 0.9;
		X2 = n * 1.1;
	}
	return 0;
}
