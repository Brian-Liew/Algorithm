#include<iostream>
using namespace std;
int main()
{
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		string ss;
		cin>>ss;
		string newss;
		for(int j=0;j<ss.size();j++)
		{
			if(newss.size()<2)
			{
				newss.append(1,ss[j]);
			}
			else if(newss.size()>=2)
			{
				if(ss[j]==newss[newss.size()-1]&&ss[j]==newss[newss.size()-2])
				{
					continue;
				}
				if(newss.size()>=3)
				{
					if(ss[j]==newss[newss.size()-1]&&newss[newss.size()-2]==newss[newss.size()-3])
					{
						continue;
					}
				}
				newss.append(1,ss[j]);
			}
		}
		cout<<newss<<endl;
	}
}
