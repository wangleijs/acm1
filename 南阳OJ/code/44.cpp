/*
描述 
给定一整型数列{a1,a2...,an}，找出连续非空子串{ax,ax+1,...,ay}，使得该子序列的和最大，其中，1<=x<=y<=n。 
输入 
第一行是一个整数N(N<=10)表示测试数据的组数）
每组测试数据的第一行是一个整数n表示序列中共有n个整数，随后的一行里有n个整数I(-100=<I<=100)，表示数列中的所有元素。(0<n<=1000000) 
输出 
对于每组测试数据输出和最大的连续子串的和。 
样例输入 
1
5
1 2 -1 3 -2
样例输出 
5
*/
/*
不需要求出具体子串的最大子串问题,经典的结合数论的贪心算法
*/
#include<stdio.h>
int main()
{
	int T,n,i,t,s,a;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		t=0;s=-1000000000;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			t+=a;
			if(t>s)s=t;
			if(t<0)t=0;
		}
		printf("%d\n",s);
	}
	return 0;
}
