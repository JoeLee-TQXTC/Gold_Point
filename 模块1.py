m = 0
def HuiGuiJiSuan(List_a,k,n):
    w = 0.0
    b = 0.0
    nx = 0.0
    sum = 0.0
    SUMx_y = 0.0
    SUMx2 = 0.0
    SUMx = 0.0
    SUMy = 0.0
    aver = 0.0
    x = 0
    for i in range(k+1-n,k,1):
        sum+=List_a[i]
    aver=sum/n
    for i in range(k+1-n,k,1):
        x=List_a[i]-aver
        x*=x
        m+=x
    m=sqrt(m/n)
    for i in range(k+1-n,k,1):
        if (aver-m)<=List_a[i]&List_a[i]<=(aver+m):
            SUMx_y += (a[i] * i)
	    	SUMx2 += (i*i)
			SUMx += i
			SUMy += a[i]
			++nx
    w = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx)
    b = SUMy / nx - w * SUMx / nx//得出n个数据的线性回归方程
    return (k+1)*w + b


def PointCentre(List_a,k):
    t1 =0.0
    t2=0.0
    c =0.0
    d = 0.0
    sum=0.0
    SUMx_y=0.0
    SUMx2=0.0
    SUMx=0.0
    SUMy=0.0
    aver=0.0
    m=0.0
    x=0.0
    n=0.0
    w = b =w1=w2=w3=b1=b2=b3=nx=0.0
    if k=0:
        return List_a[0]*0.6

