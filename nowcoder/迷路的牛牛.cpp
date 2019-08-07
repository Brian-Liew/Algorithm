#include<iostream>
using namespace std;
int main()
{
	char state[4]={'W','N','E','S'};
	int num;
	cin>>num;
	int nowstate=1;
	for(int i=0;i<num;i++)
	{
		char direction;
		cin>>direction;
		if(direction=='L')
		{
			nowstate=nowstate-1;
			if(nowstate<0)
				nowstate=3;
		}
		else if(direction=='R')
		{
			nowstate=(nowstate+1)%4;
		}
	}
	cout<<state[nowstate]<<endl;

}
