#include<stdio.h>
#include<stdlib.h>
#define max 21
 
int a[max][max]; 
int n,m,r;
int count; //number of the answer
int x[max]; //color of the vertex
 
bool notsame(int i)
{
	for(int j=1;j<=n;j++)
		if(a[i][j]==1 && x[i]==x[j])
		{
			return false;
		}
	return true;
}
 
void dfs(int i)
{
	if(i>n)
	{
		count++;
	}
	else
	{
		for(int j=1;j<=m;j++)
		{
			x[i]=j;
			if(notsame(i))
			{
				dfs(i+1);
			}
			x[i]=0;
		}
	}
}
 
int main()
{
	int x,y;
	scanf("%d%d%d",&n,&r,&m);
	for(int i=1;i<=r;i++)
	{
		scanf("%d%d",&x,&y);
		a[x+1][y+1]=1;
		a[y+1][x+1]=1;
	}
	dfs(1);
	if(count>0)
	{
		printf("%d\n",count);
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
