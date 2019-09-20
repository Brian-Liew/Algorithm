#include<iostream>
using namespace std;
int main()
{
	int N=1001;
	dp[N];
	dp[0]=1;
	for(int i=1;i<N;i++)
	{
		int t=1;
		while(t<=i)
		{
			dp[i]+=dp[i-t];
			dp[i]%=1000000003;
			t=t*2;
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		cout<<dp[temp]<<endl;
	}
}