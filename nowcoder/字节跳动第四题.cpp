#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int tol=0;
	int sum=0;
	int a1[500]={0},b1[500]={0},c1[500]={0},dp[500]={0};
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(b<=(a-b))
		{
			sum=sum+c;
			m=m+(a-b-b);
		}
		else
		{
			a1[++tol]=a;
			b1[tol]=b-(a-b);
			c1[tol]=c;
		}
	}
	for(int i=1;i<=tol;i++)
	{
		for(int j=m;j>=b1[i];j--)
			dp[j]=max(dp[j],dp[j-b1[i]]+c1[i]);
	}
	cout<<sum+dp[m]<<endl;
}
