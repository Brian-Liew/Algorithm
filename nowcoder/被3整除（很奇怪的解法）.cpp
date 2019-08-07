#include<iostream>
using namespace std;
int main()
{
	long long left,right;
	cin>>left>>right;
	long long sum=0;
	for(long long i=1;i<=left;i++)
	{
		sum=sum+i;		
	}
	int num=0;
	for(long long i=left;i<=right;i++)
	{
		if(sum%3==0)
			num++;
		sum=sum+i+1;
	}
	cout<<num<<endl;
}