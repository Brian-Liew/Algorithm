/*
对于这样的一个动态规划，我们需要用一个二维的数组来解决，首先就是用
dp[i][0]来表示长度为i最后一位是0-9之间的个数，而用
dp[i][1]来表示长度为i最后一位为有括号的个数，所以状态转移方程为：
dp[i][0]=((dp[i-1][0]*10+(dp[i-2][0]+dp[i-2][1])*10*2LL))
dp[i][1]=(dp[i-2][0]+dp[i-2][1])
for(int j=1;i-j-3>=1;j++)//减3是减去“+（）”3个字符的长度，j是左边合法表达式的长度，i-j-3是右边合法表达式的长度
            dp[i][1]=(dp[i][1]+((dp[j][0]+dp[j][1])*(dp[i-j-3][0]+dp[i-j-3][1])*2LL)%mod)%mod;

*/

#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
long long dp[1000+10][2];
const long long mod=1000000007;
int main()
{
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    dp[1][0]=10;
    dp[1][1]=0;
    for(int i=2;i<=n;i++)
       {
           dp[i][0]=(dp[i-1][0]*10+(dp[i-2][0]+dp[i-2][1])*20LL)%mod;
           dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod;
           for(int j=1;i-j-3>=1;j++)
            dp[i][1]=(dp[i][1]+((dp[j][0]+dp[j][1])*(dp[i-j-3][0]+dp[i-j-3][1])*2LL)%mod)%mod;
       }
    cout<<(dp[i][0]+dp[i][1])%mod<<endl;


//原文链接：https://blog.csdn.net/hero_ds/article/details/82084625