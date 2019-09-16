#include<iostream> 
#include<math.h>
#include<memory.h>
using namespace std;
int main()
{
	int n;
	cin>>n; 
	int piles[n];
	memset(piles,0,sizeof(piles));
	for(int i=0;i<n;i++)
		cin>>piles[i];
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	int tt=0;
	int sum[n];
	memset(sum,0,sizeof(sum));
	for(int i=n-1;i>=0;i--)
	{
		tt+=piles[i];
		sum[i]=tt;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(i+2*j>=n)
			{
				dp[i][j]=sum[i];
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>=1;j--)
		{
			for(int x=1;x<=2*j&&i+x<n;x++)
				dp[i][j]=max(dp[i][j],sum[i]-dp[i+x][max(x,j)]);
		}
	}
	cout<<dp[0][1]<<endl;
}

/*
class Solution {
public:
    int mem[101][101]={};
    int max(int a,int b){
        return a>b?a:b;
    }
    int solve(int start,int M,int n, int* sum){
        if(mem[start][M]) return mem[start][M];
        int res=0;
        for(int i=1;i<=2*M&&start+i<=n;i++){
         //   cout<<sum[start]<<endl;
            res=max(res,sum[start]-solve(start+i,max(M,i),n,sum));
           // cout<<res<<endl;
        }
        return mem[start][M]=res;
    }
    int stoneGameII(vector<int>& piles) {
        //最大石头数量;
        //记忆递归;
        int n=piles.size();
        int sum[101]={};
        sum[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            //cout<<sum[i]<<endl;
           // cout<<piles[i]<<endl;
            sum[i]=sum[i+1]+piles[i];
           // cout<<sum[i]<<endl;
        }
        return solve(0,1,n,sum);
    }
};
*/