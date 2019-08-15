#include<iostream>
#include<memory.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int interest[n];
	for(int i=0;i<n;i++)
	{
		cin>>interest[i];
	}
	int state[n];
	int fix_num=0;
	int arr_num[n];
	memset(arr_num,0,sizeof(arr_num));
	for(int i=0;i<n;i++)
	{
		cin>>state[i];
		if(state[i]==1)
		{
			fix_num=fix_num+interest[i];
			if(i!=0)
				arr_num[i]=arr_num[i-1];
		}
		if(state[i]==0)
		{
			if(i==0)
				arr_num[i]=interest[i];
			else
			{
				arr_num[i]=arr_num[i-1]+interest[i];
			}
		}
	}
	
	int max_num=0;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		if(state[i]==0)
		{
			int end=i+k-1;
			if(i+k-1>n-1)
				end=n-1;
			int start=i-1;
			if(start<0)
				sum=arr_num[end];
			else
			{
				sum=arr_num[end]-arr_num[start];
			}
			if(sum>max_num)
				max_num=sum;

		}
	}
	cout<<max_num+fix_num<<endl;

}
