#include<iostream>
#include<map>
using namespace std;
int main()
{
	string ss="pwwkew";
	map<char,int> test;
	map<char,int>::iterator iter;
	int longest=0;
	int left=0;
	for(int i=0;i<ss.size();i++)
	{
		iter=test.find(ss[i]);
		if(iter==test.end()||test[ss[i]]<left)
		{
			longest=max(longest,i-left+1);
			test[ss[i]]=left;
		}
		else
		{
			left=i;
			test[ss[i]]=i;
		}
	}
	cout<<longest<<endl;
}
