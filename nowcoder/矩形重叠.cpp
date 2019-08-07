#include<iostream>
//#include<algorithm> 
#include<bits/stdc++.h>
using namespace std;
const int N=55;


int main()
{
	int num;
	cin>>num;
	int X[num*2],Y[num*2],x1[num],x2[num],y1[num],y2[num];
	for(int i=0;i<num;i++)
	{
		cin>>x1[i];
		X[i]=x1[i];
	}
	for(int i=0;i<num;i++)
	{
		cin>>y1[i];
		Y[i]=y1[i];
	}
	for(int i=0;i<num;i++)
	{
		cin>>x2[i];
		X[i+num]=x2[i];
	}
	for(int i=0;i<num;i++)
	{
		cin>>y2[i];
		Y[i+num]=y2[i];
	}
	sort(X,X+num*2);
	sort(Y,Y+num*2);
	int not_repeat_x=unique(X,X+2*num)-X;
	int not_repeat_y=unique(Y,Y+2*num)-Y;

int mp[2*55][2*55],lx,ly,rx,ry;
	
	for (int i=0;i<num;i++)
	{
		lx=lower_bound(X,X+not_repeat_x,x1[i])-X;
		ly=lower_bound(Y,Y+not_repeat_y,y1[i])-Y;
		rx=lower_bound(X,X+not_repeat_x,x2[i])-X;
		ry=lower_bound(Y,Y+not_repeat_y,y2[i])-Y;
		for(int j=lx+1;j<=rx;j++)
		{
			for(int p=ly+1;p<=ry;p++)
			{
				mp[j][p]++;
			}
		}
	}
	int ans=1;
	for(int i=0;i<not_repeat_x;i++)
	{
		for(int j=0;j<not_repeat_y;j++)
		{
			ans=max(ans,mp[i][j]);
		}
	}
	cout<<ans<<endl;
}
