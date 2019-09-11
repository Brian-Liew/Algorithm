/*
航班修改信息
*/
#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<string,string> test;

	for(int i=0;i<n;i++)
	{
		string ss;
		cin>>ss;
		int num=0;
		string s1="";
		string s2="";
		int flag=1;
		for(int j=0;j<ss.size();j++)
		{
			if(ss[j]==',')
			{
				if(num==0)
				{
					num++;
				}
				else if(num!=0)
				{
					flag=2;
				}
			}
			if(ss[j]!=',')
			{
				if(flag==1)
				s1.append(1,ss[j]);
			    else
				s2.append(1,ss[j]);
			}

		}
		test[s1]=s2;
		
	}

	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		string ss;
		cin>>ss;
		int num=0;
		int flag=1;
		string s1="";
		string s2="";
		for(int j=0;j<ss.size();j++)
		{
			if(ss[j]!=',')
			{
				if(flag==1)
					s1.append(1,ss[j]);
				else
					s2.append(1,ss[j]);
			}
			else if(ss[j]==',')
			{
				if(num==0)
				{
					num++;
				}
				else
				{
					flag=2;
				}
			}
		}
		map<string,string>::iterator item;
		item=test.find(s1);
		string temp2=item->second;
		test[s2]=temp2;
		test.erase(item);
		
	}
	map<string,string>::iterator item;
	for(item=test.begin();item!=test.end();)
	{
		string sss=item->first;
		for(int i=0;i<sss.size()-2;i++)
			cout<<sss[i];
		cout<<",";
		for(int i=sss.size()-2;i<sss.size();i++)
			cout<<sss[i];
		cout<<",";
		cout<<item->second;
		cout<<endl;
		item++;
	}


}
