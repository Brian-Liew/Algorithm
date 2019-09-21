#include<iostream>
#include<memory.h>
using namespace std;
int visit[299][299];
memset(visit,0,sizeof(visit));
int X,Y;
int inx[8]={-2,-1,1,2,2,1,-1,-2};
int iny[8]={1,2,2,1,-1,-2,-2,-1};
int dfs(int x,int y,int count)
{
	if(x==X&&y==Y)
	{
		return count;
	}
	int max_value=1000;
	for(int i=0;i<8;i++)
	{
		int tempx=x+inx[i];
		int tempy=y+inx[i];
		if(tempx>=0&&tempx<299&&tempy>=0&&tempy<299)
		{
			max_value=min(max_value,dfs(tempx,tempy,count+1));
		}
	}
	return;

}
int main()
{
	int nx,ny;
	cin>>nx>>ny;
	X=nx+149;
	Y=ny+149;
	cout<<dfs(149,149,0);
}