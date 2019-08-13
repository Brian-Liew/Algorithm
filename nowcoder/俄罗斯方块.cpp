#include<iostream>
#include<memory.h> 
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int fang[n];
	memset(fang,0,sizeof(fang));
	int sum=0;
	for(int i=0;i<m;i++)
	{
		int lie;
		cin>>lie;
		fang[lie-1]=fang[lie-1]+1;
		int flag=1;
		for(int j=0;j<n;j++)
		{
			if(fang[j]==sum)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			sum=sum+1;
		}
	}
	cout<<sum<<endl;
}
