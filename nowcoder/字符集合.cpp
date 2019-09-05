#include<iostream>
#include<memory.h>
using namespace std;
int main()
{
	string ss;
	while(cin>>ss)
	{

	int alpha[2000];
	memset(alpha,0,sizeof(int)*2000);
	for(int i=0;i<ss.size();i++)
	{
		if(alpha[ss[i]-'A']==0)
		{
			alpha[int(ss[i]-'A')]=1;
			cout<<ss[i];
		}
		else
		{
			continue;
		}
	}
	cout<<endl;
}
}
