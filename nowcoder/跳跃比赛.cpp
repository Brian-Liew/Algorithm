/*
题目描述 
给出一组正整数，你从第一个数向最后一个数方向跳跃，每次至少跳跃1格，每个数的值表示你从这个位置可以跳跃的最大长度。计算如何以最少的跳跃次数跳到最后一个数。

输入描述: 
第一行表示有多少个数n 
第二行开始依次是1到n个数，一个数一行 
输出描述: 
输出一行，表示最少跳跃的次数。 
示例1 
输入 
7 
2 
3 
2 
1 
2 
1 
5 
输出 
3
分析：使用动态规划，每一次都是判断前一个状态是否可以到达这个状态，然后计算当前状态与
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int migong[n];
	int dp[n];
	for(int i=0;i<n;i++)
	{
		cin>>migong[i];
		dp[i]=i;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(migong[j]>=i-j)
			{
				dp[i]=min(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n-1]<<endl;
}
