/*
对于这一类使用string来进行运算的，步骤一般都很简单：
1、倒序，
2、将两个string排成等长，用最小数填充空位
3、对于每一位进行相加，注意进位要加上去，（一开始初始化进位为0），然后更新进位，得到取余的结果
4、从后面开始输出结果
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string ss1,ss2;
	cin>>ss1>>ss2;
	int length1=ss1.size();
	int length2=ss2.size();

	reverse(ss1.begin(),ss1.end());
	reverse(ss2.begin(),ss2.end());
	if(length1<length2)
	{
		for(int i=length1;i<length2;i++)
			ss1[i]='a';
	}
	else if(length1>length2)
	{
		for(int i=length2;i<length1;i++)
			ss2[i]='a';
	}


	string math26="abcdefghijklmnopqrstuvwxyz";
	int carry=0;
	string result;
	int i;
	for( i=0;i<max(length2,length1);i++)
	{
		int temp=ss1[i]+ss2[i]-'a'-'a';
		temp=temp+carry;

		if(temp>=26)
			carry=1;
		else
			carry=0;
		temp=temp%26;
		result[i]=math26[temp];
	}
	if(carry==1)
		result[i]='b';
	for( int j=max(length2,length1)+carry-1;j>=0;j--)
		cout<<result[j];
	cout<<endl;
}
