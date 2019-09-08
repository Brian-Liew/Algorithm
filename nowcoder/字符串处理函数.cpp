#include<iostream>
#include<algorithm>
#include<memory.h>
#include<map>
using namespace std;
int main()
{
	map<char,int> text;
	map<char,int>::iterator iter;
	string ss;
	cin>>ss;
	char max_index=ss[0];
	for(int i=0;i<ss.size();i++)
	{
		if(text.find(ss[i])==text.end())
			text[ss[i]]=1;
		else
			text[ss[i]]++;
		if(text[max_index]<text[ss[i]])
			max_index=ss[i];
	}
	for(int i=0;i<text[max_index];i++)
	cout<<max_index;
	for(int i=0;i<ss.size();i++)
	{
		if(ss[i]!=max_index)
		cout<<ss[i];
	}
	cout<<endl; 

}
