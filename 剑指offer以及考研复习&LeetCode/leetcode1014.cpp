#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int res[n];
	for(int i=0;i<n;i++)
		cin>>res[i];
	int cur=0;
	int maxscore=0;
	for(int i=0;i<n;i++)
	{
		maxscore=max(maxscore,cur+res[i]);
		cur=max(cur,res[i])-1;
	}
	cout<<maxscore<<endl;
}