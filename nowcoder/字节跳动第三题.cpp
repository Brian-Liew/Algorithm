#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++)
		cin>>nums[i];
	int sum[n];
	int dp[n][n];
	sum[0]=nums[0];
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+nums[i];
	}
	for(int i=0;i<n;i++)
	{
		dp[i][i]=nums[i];
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			dp[i][j]=max(sum[j]-sum[i]+nums[i]-dp[i+1][j],sum[j]-sum[i]+nums[i]-dp[i][j-1]);
		}
	}
	
/*	for(int i=1;i<n;i++)
            for(int j=0;i+j<n;j++)
                dp[j][i+j]=max(sum[i+j]-sum[j]+nums[j]-dp[j+1][i+j],sum[i+j]-sum[j]+nums[j]-dp[j][i+j-1]);
*/
	cout<<dp[0][n-1]<<endl;
}
