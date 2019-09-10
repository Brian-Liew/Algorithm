//注意到map有自动排序key的功能可以应用
#include<iostream>
#include<map> 
#include<string>
#include<string.h>
using namespace std;
/*
题目描述 
给你一个原始字符串，根据该字符串内每个字符出现的次数，按照ASCII码递增顺序重新调整输出。

【温馨提示】 
(1).原始字符串中仅可能出现“数字”和“字母”； 
(2).请注意区分字母大小写。 
输入描述: 
eeefgghhh 
输出描述: 
efghegheh 
示例1 
输入 
eeefgghhh 
输出 
efghegheh
*/


int main()
{
	string ss;
	cin>>ss;
	map<char,int> test;
	
	for(int i=0;i<ss.size();i++)
	{
		if(test.find(ss[i])==test.end())
		{
			test[ss[i]]=1;
		}
		else
			test[ss[i]]++;
	}
	while(!test.empty())
	{
		map<char,int> ::iterator item;
		for(item=test.begin();item!=test.end();)
		{
			cout<<item->first;
			item->second--;
			if(item->second==0)
			{
				//这里只能这样写，不然会删了指针使得没了
				test.erase(item++);
			}
			else
				item++;
			
		}
	}
	cout<<endl;

}
/*
int main()
{
	string s;
	cin >> s;
 
	typedef map<char,int> mci;
	mci m;
	for(int i=0;i<s.size();i++)
	{
		m[s[i]]++;
	}
	while(!m.empty())
	{
		mci::iterator it;
		for(it = m.begin(); it != m.end(); )
		{
			cout << it->first;
			it->second--;
			if(it->second == 0)
			{
				/*auto temp = it;
				it++;               
				m.erase(temp); /////////这里有个指针,野指针问题!
				m.erase(it++);
				
			
			}
			else
			{
				it++;
			}
		}
	}
	cout << endl;
	return 0;
}
*/
