//贪心策略不对必然是ＷＡ
#include<stdio.h>
#define inf 100000000
int main()
{
	int line,n,i,j,p,t,flage,l,w;
	int ss[5000][3];
	scanf("%d",&line);
	while(line--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&ss[i][0],&ss[i][1]);
			ss[i][2]=ss[i][0]+ss[i][1];
		}
		for(i=0;i<n-1;i++)//原先我是根据w+l的值来由小到大排序的，但这是错误的
		{
			p=i;
			for(j=i+1;j<n;j++)
			{
				if(ss[j][0]!=ss[p][0])
				{
					if(ss[j][0]<ss[p][0])p=j;//至少这也是一个必要条件
				}
				else
				{
					if(ss[j][1]<ss[p][1])p=j;
				}
			}
			for(j=0;j<3;j++)
			{
				t=ss[i][j];
				ss[i][j]=ss[p][j];
				ss[p][j]=t;
			}
		}
		flage=1;t=0;
		while(flage)
		{
			l=w=0;
			for(i=0;i<n;i++)
			{
				if(ss[i][2]==inf)continue;
				if(ss[i][0]>=l&&ss[i][1]>=w)
				{
					ss[i][2]=inf;
					l=ss[i][0];
					w=ss[i][1];
				}
			}
			t++;
			flage=0;
			for(i=0;i<n;i++)if(ss[i][2]!=inf)flage=1;
		}
		printf("%d\n",t);
	}
	return 0;
}