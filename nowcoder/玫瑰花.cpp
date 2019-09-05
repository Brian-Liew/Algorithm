/* 
这是一个动态规划问题，就是令dp[i][j]为第i个位置时用了j中颜色所用到的分配数量，
那么有两种情况，dp[i][j]=
(1)当前面i-1个位置用了j种颜色，那么第i个位置随意使用j种颜色；
(2)当前面i-1个位置用了j-1种颜色，那么第i个位置只能是一种颜色，但是前面的j-1种颜色可以选择出j种方案，因此
递归方程就是：
dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1]*j


*/
#include<iostream>
using namespace std;
int main()
{
	int N,k;
	cin>>N>>k;
	int dp[6000][32];
	dp[1][1]=1;
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%772235*j%772235;
		}
	}
	cout<<dp[N][k]<<endl;
}