/*
给定义一些坐标，求小于某个距离的匹配点
*/
#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<math.h> 
using namespace std;
int returnint(string ss)
{
	int sum=0;
	int len=ss.size();
	for(int i=0;i<len;i++)
	{
		int temp=ss[i]-'0';
		sum=sum*10+temp;
	}
	return sum;
}
int main()
{
	string ss;
	cin>>ss;
	int aa[51];
	int bb[51];
	int length1=0;
	int length2=0;
	string num;
	int flag=1;
	int index;
	for(int i=3;i<ss.size();i++)
	{
		if(ss[i]!=','&&ss[i]!='}')
		{
			
			num.append(1,ss[i]);
		}
		else if(ss[i]==',')
		{
			aa[length1++]=returnint(num);
			num="";
		}
		else if(ss[i]=='}')
		{
			aa[length1++]=returnint(num);
			num="";
			index=i+5;
			break;
		}
	}

	string num2;
	for(int i=index;i<ss.size();i++)
	{
		if(ss[i]!=','&&ss[i]!='}')
		{
			num2.append(1,ss[i]);
		}
		else if(ss[i]==',')
		{
			bb[length2++]=returnint(num2);
			num2="";
		}
		else if(ss[i]=='}')
		{
			bb[length2++]=returnint(num2);
			num2="";
			index=i+4;
			break;
		}
	}



	string num3;
	for(int i=index;i<ss.size();i++)
	{
		num3.append(1,ss[i]);
	}
	int R=returnint(num3);




	for(int i=0;i<length1;i++)
	{
		int fff=0;
		for(int j=0;j<length2;j++)
		{
			if(aa[i]<=bb[j])
			{
				if(abs(aa[i]-bb[j])<=R)
				{
					fff=1;
					cout<<"("<<aa[i]<<","<<bb[j]<<")";
				}
				else
				{
					if(fff==0)
					{
						cout<<"("<<aa[i]<<","<<bb[j]<<")";
						break;
					}
				}
				
			}

		}
	}
	cout<<endl;
}
