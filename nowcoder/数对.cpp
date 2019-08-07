#include<iostream>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k;
	if(k==0)
	{
		cout<<n*n<<endl;
		return 0;
	}
	long long count=0;
	for(int i=k;i<=n;i++)
	{
		count=count+(n/i)*(i-k);
		if(n%i>=k)
			count=count+n%i-k+1;
	}
	cout<<count<<endl;
}