#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp(int *a,int *b)
{
	if(a[1]==b[1])
		return a[0]<b[0];
	return a[1]<b[1];
}
int main()
{
	int n;
	cin>>n;
	int **ji=new int*[n];
	for(int i=0;i<n;i++)
	{
		ji[i]=new int[2];
		cin>>ji[i][0]>>ji[i][1];
	}
	sort(ji,ji+n,cmp);
	int dp[n];
	dp[0]=ji[0][0];
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(ji[i][0]>=dp[len-1])
			dp[len++]=ji[i][0];
		else
		{
			*(upper_bound(dp,dp+len,ji[i][0]))=ji[i][0];
		}
	}
	cout<<len<<endl;
}