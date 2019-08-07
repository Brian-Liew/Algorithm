#include<iostream>
using namespace std;
int main()
{
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		int len;
		cin>>len;
		char *road=new char[len];
		for(int j=0;j<len;j++)
		{
			cin>>road[j];
		}
		int sum_of_light=0;
		for(int p=1;p<len+2;p++)
		{
			//only two option in this problem
			//one is the last one is needed
			//another one is you get the end edge so you should consider this option
			if(p==len+1)
			{
				if(road[p-1]=='.')
					sum_of_light=sum_of_light+1;
			}
			if(road[p-1]=='.')
			{
				sum_of_light=sum_of_light+1;
				p=p+2;
			}
		}
		cout<<sum_of_light<<endl;
	}
}