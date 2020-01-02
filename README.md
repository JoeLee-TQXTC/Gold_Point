# Gold_Point
emmmmmm，黄金点比赛代码片段
1.cpp 中包括
HuiGuiJiSuan(double a[], int k, int n);
//a[]为历史记录数组，a[k]为最新数据，n为采样数据量，根据n的多少，采样a[k+1-n]到a[k]的数据，来做出对a[k+1]的回归预测，其中使用一倍标准差进行异常数据的剔除计算。
 PointCentre(double a[], int k)；
 //a[]为黄金点历史数据，a[k]为最新数据，通过不同阶段的预测或者是多元线性回归，来预测下轮保守值大小
