#include<iostream>
using namespace std;
int main()
{
	int num=-1;
	while(cin>>num)
	{
		int sum=num;
		int re=0;
		while(sum/3!=0)
		{
			re=sum/3+re;
			sum=sum/3+sum%3;
		}
		if(sum/3==0)
		{
			if(sum==2)
			{
				re=re+1;
			}
		}
		cout<<re<<endl;
	
	}
 } 
