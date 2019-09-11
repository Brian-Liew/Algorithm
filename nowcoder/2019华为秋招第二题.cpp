/*
倒序输出
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string ss;
	getline(cin,ss);

	string num="";

	for(int i=ss.size()-1;i>=0;i--)
	{
		if(i==0)
		{
			num.append(1,ss[i]);
			reverse(num.begin(),num.end());
			for(int j=0;j<num.size();j++)
				cout<<num[j];
			num="";
		}

		if((ss[i]>='a'&&ss[i]<='z')||(ss[i]>='0'&&ss[i]<='9'))
		{
	
			num.append(1,ss[i]);
		}
		else if(ss[i]=='-'&&((ss[i-1]>='a'&&ss[i-1]<='z')||(ss[i-1]>='0'&&ss[i-1]<='9'))&&((ss[i+1]>='a'&&ss[i+1]<='z')||(ss[i+1]>='0'&&ss[i+1]<='9')))
		{
			num.append(1,ss[i]);
		}

		else
		{
			int flag=0;
			reverse(num.begin(),num.end());
			for(int j=0;j<num.size();j++){
				flag=1;
				cout<<num[j];
			}
			if(flag==1)
			cout<<" ";
		flag=0;
			num="";
		}
	}
	cout<<endl;
}
