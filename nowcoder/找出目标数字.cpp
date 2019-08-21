#include<iostream>
using namespace std;
int Binary_search(int begin ,int end ,int value,int *list)
{
	int end1=end;
	while(begin<=end)
	{
		int mid=(begin+end)/2;
		if(list[mid]>=value)
			end=mid-1;
		else
			begin=mid+1;
	}
	
	if (begin<end1)
		return begin;
	else
		return -1;
}
int main()
{
	int num;
	int ll[11]={1,2,3,4,5,6,6,6,7,8,9};
	cin>>num;
	cout<<Binary_search(0,10,num,ll)<<endl;


}
