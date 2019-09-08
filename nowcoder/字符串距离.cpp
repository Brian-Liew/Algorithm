#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
	string ss;
	cin>>ss;
	char s;
	cin>>s;
	if(ss.size()==1)
	{
		cout<<"[0]"<<endl;
		return 0;
	}
	vector<int> test;
	for(int i=0;i<ss.size();i++)
	{
		if(ss[i]==s)
			test.push_back(i);
	}
	cout<<"[";
	for(int i=0;i<test.size();i++)
	{
		int position=test[i];
		int nextpositon,preposition;
		if(i==0)
		{
			preposition=-1;
			for(int i=preposition+1;i<position;i++)
			cout<<position-i<<",";
			cout<<0<<",";
		}
		else
		{
			preposition=test[i-1];
			for(int i=(preposition+position)/2+1;i<position;i++)
			cout<<position-i<<",";
		cout<<0<<",";
		}
		if(i==test.size()-1)
		{
			nextpositon=ss.size()-1;
			for(int i=position+1;i<=nextpositon;i++)
		{
			if(i!=ss.size()-1)
			{
				cout<<i-position<<",";
			}
			else
				cout<<i-position<<"]"<<endl;
		}
		}
		else
		{
			nextpositon=test[i+1];
			for(int i=position+1;i<=(nextpositon+position)/2;i++)
		{
			if(i!=ss.size()-1)
			{
				cout<<i-position<<",";
			}
			else
				cout<<i-position<<"]"<<endl;
		}
		}
		
		
		
	}
}
