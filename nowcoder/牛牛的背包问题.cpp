#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int  state=0;
int v[100];
int bag(int num,int w)
{
	if(w<=0)
	return 0;
	if(num==1)
	{
		if(w>0&&v[0]<=w)
			return 2;
		else if(w>0&&v[0]>w)
			return 1;
	}
	return bag(num-1,w)+bag(num-1,w-v[num-1]);
    
}
int main()
{
	int n;
	int weight;
	cin>>n>>weight;
	long long  sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum=sum+v[i];
	}
	if(sum<=weight)
	{
		cout<<int(pow(2,n))<<endl;
		return 0;
	}
	state=bag(n,weight);
	cout<<state<<endl;
}
