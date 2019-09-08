#include<iostream>
using namespace std;
int main()
{
	string ss;
	cin>>ss;
	int len=ss.size();
	bool **dp=new bool*[len];
	int max_value=1;
	int a,b;

	for(int i=0;i<len;i++)
	{
		dp[i]=new bool[len];
		dp[i][i]=1;
		a=i;
		b=i;
	}
	
	for(int i=0;i<len-1;i++)
	{
		if(ss[i]==ss[i+1])
		{
			dp[i][i+1]=1;
			max_value=2;
			a=i;
			b=i+1;
		}
	}
	for(int i=3;i<=len;i++)
	{
		for(int j=0;j<len-i+1;j++)
		{
			int end=i+j-1;
			if(ss[end]==ss[j]&&dp[j+1][end-1]==1)
			{
				dp[j][end]=1;
				if(i>=max_value)
				{
					max_value=i;
					a=j;
					b=end;
				}
			}
		}
	}
	if(max_value==1)
	{
		cout<<ss[0]<<endl;
		return 0;
	}
	for(int i=a;i<=b;i++)
		cout<<ss[i];
	cout<<endl;
}