#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	
	int num;

	while(scanf("%d",&num)!=EOF)
	{
	
	int ss[num];
	for(int i=0;i<num;i++)
	cin>>ss[i];
	sort(ss,ss+num);
	int re=ss[0];
	cout<<re<<endl;
	for(int i=1;i<num;i++)
	{
		if(ss[i]!=re)
		{
			re=ss[i];
			cout<<re<<endl;
		}
	}
}
}
