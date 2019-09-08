#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
	map<int ,int> student;
	for(int i=1;i<=n;i++)
	{
		int score;
		cin>>score;
		student[i]=score;
	}
	for(int i=1;i<=m;i++)
	{
		string test;
		cin>>test;
		if(test=="U")
		{
			int a,b;
			cin>>a>>b;
			student[a]=b;
		}
		if(test=="Q")
		{
			int a,b;
			cin>>a>>b;
			if(b<a)
				swap(a,b);
			int max_value=a;
			for(int j=a;j<=b;j++)
			{
				if(student[j]>student[max_value])
					max_value=j;
			}
			cout<<student[max_value]<<endl;
		}
	}
	}
}