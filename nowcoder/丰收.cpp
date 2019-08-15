#include<iostream>
using namespace std;
int binarysearch(int num,int* arr_num,int end)
{
	int left=0;
	int right=end-1;
	int index;
	while(left<right)
	{
		int mid=(left+right)/2;
		if(num<arr_num[mid])
			right=mid;
		else if(num>arr_num[mid])
			left=mid+1;
		else if(num==arr_num[mid])
			{
				index=mid;
				return index;
			}
	}
	index=(left+right)/2;
	return index;


}
int main()
{
	int n;
	cin>>n;
	int arr_num[n];
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		if(i!=0)
		{
			arr_num[i]=arr_num[i-1]+temp;
		}
		else
		{
			arr_num[i]=temp;
		}
	}
	int search_num=0;
	cin>>search_num;
	for(int i=0;i<search_num;i++)
	{
		int num;
		cin>>num;
		int index=binarysearch(num,arr_num,n);
		cout<<index+1<<endl;
	}
}
