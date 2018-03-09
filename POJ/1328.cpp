#include <iostream>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
using namespace std;  
struct island  
{  
	int x, y;  
	double l, r;  
};  
int n;  
int d;  
island a[1000];  
  
bool cmp(island a, island b)  
{  
	if (a.r == b.r)  
		return a.l < b.l; //加上这句之后莫名地快了16ms.. 不知道为什么  
	return a.r < b.r;  
}  
  
int main()  
{  
	int c = 1;  
	while (~scanf("%d %d", &n, &d) && !(n == 0 && d == 0))  
	{  
		int num = 1,flag=0;  
		for (int i = 0; i < n; i++)  
		{  
			scanf("%d %d", &(a[i].x), &(a[i].y));  
			if (a[i].y < 0)  
				flag = 1;  
			else if (a[i].y>d)  
				flag = 1;  
		}  
		if (flag)  
		{  
			printf("Case %d: -1\n", c++);  
			continue;  
		}  
		if(d<0)  
		{  
			printf("Case %d: -1\n", c++);  
			continue;  
		}  
		if (d == 0)  
		{  
			for (int i = 0; i < n; i++)  
			{  
				if (a[i].y != 0)  
				{  
					printf("Case %d: -1\n", c++);  
					break;  
				}  
				if (i == n - 1)  
					printf("Case %d: %d",c++,n);  
			}  
			continue;  
		}  
  
		for (int i = 0; i < n; i++)  
		{  
			a[i].l = double(a[i].x) - sqrt(double(d*d - a[i].y*a[i].y));  
			a[i].r = double(a[i].x) + sqrt(double(d*d - a[i].y*a[i].y));  
		}  
  
		sort(a, a + n, cmp);  
		double key=a[0].r;  
		for (int i = 1; i < n; i++)  
		{  
			if (a[i].r == key)  
				continue;  
			else  
			{  
				if (a[i].l > key)  
				{  
					num++;  
					key = a[i].r;  
				}  
			}  
		}  
		printf("Case %d: %d\n",c++,num);  
	}  
	return 0;  
}  