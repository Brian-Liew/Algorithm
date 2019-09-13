#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<vector<int> > grid(N, vector<int> (N, -1));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cin>>grid[i][j];
	}
	int maxSize=2*(N)-1;
	vector<vector<int> > dp (N, vector<int> (N, -1));
	dp[0][0]=grid[0][0];
	for(int step=1;step<maxSize;step++)
	{
		vector<vector<int> > dp2(N, vector<int>(N, -1));
		for(int i=0;i<N&&i<=step;i++)
		{
			if(step-i>=N)
				continue;
			for(int j=0;j<N&&j<=step;j++)
			{
				if(step-j>=N)
					continue;

				int i2=step-i;
				int j2=step-j;
				if(grid[i][i2]==-1||grid[j][j2]==-1)
				{
			
					continue;
				}
				int temp=dp[i][j];
				if(i>0)
				{
					temp=max(dp[i-1][j],temp);
				}
				if(j>0)
				{
					temp=max(dp[i][j-1],temp);
				}
				if(i>0&&j>0)
				{
					temp=max(temp,dp[i-1][j-1]);
				}
				if(temp==-1)
				{
					continue;
				}
				if(i==j)
				{
					temp+=grid[i][i2];
				}
				else
				{
					temp+=grid[i][i2]+grid[j][j2];
				}
				dp2[i][j]=temp;
			}
		}
		dp=dp2;
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	cout<<dp[i][j]<<endl; 
}
