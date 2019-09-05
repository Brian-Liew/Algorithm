#include<iostream>
#include<memory.h> 
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{


	int a[num];
	memset(a,0,num*sizeof(int));
	int sum=0;
	int index=-1;
	while(sum<num)
	{
		for(int i=1;i<=3;i++)
		{
			while(a[(index+1)%num]==1)
			{
				index=(index+1)%num;
			}
			index=(index+1)%num;
		}
		a[index]=1;
		sum=sum+1;

	}
	cout<<index<<endl;
}
}
