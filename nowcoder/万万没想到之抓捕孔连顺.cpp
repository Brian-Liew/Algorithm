#include<iostream>
#include<memory.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	long long dp[n];
	long long migong[n];
	memset(dp,0,sizeof(long long)*n);
	for(int i=0;i<n;i++)
	{
		cin>>migong[i];
	}
	if(migong[2]-migong[0]<=m)
		dp[2]=1;
	for(int i=3;i<n;i++)
	{
		int temp=0;
		int flag=0;
		for(int j=0;j<=i-2;j++)
		{
			if(migong[i]-migong[j]>m)
				continue;
			else
			{
				flag=1;
				temp=j;
				break;
			}
		}
		if(flag==1)
		dp[i]=(i-temp)*(i-temp-1)/2;

	}
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+dp[i];
		
	}
	cout<<sum%99997867<<endl;
}
