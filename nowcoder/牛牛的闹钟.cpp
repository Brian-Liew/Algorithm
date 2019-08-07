#include<iostream>
#include<algorithm>
bool cmp1(int *a,int *b)
{
	if(a[0]==b[0])
		return a[1]<b[1];
	return a[0]<b[0];
};
using namespace std;
int main()
{
	int num;
	cin>>num;
	int **clock=new int*[num];
	for(int i=0;i<num;i++)
	{
		clock[i]=new int[2];
		cin>>clock[i][0]>>clock[i][1];
	}
	sort(clock,clock+num,cmp1);
	int path,hour,min;
	cin>>path>>hour>>min;
	for(int i=num-1;i>=0;i--)
	{
		int hour_now=clock[i][0];
		int min_now=clock[i][1];
		int min_arr=(min_now+path)%60;
		int hour_arr=(min_now+path)/60+hour_now;
		if((hour_arr<hour)||((hour_arr==hour)&&min_arr<=min))
		{
			cout<<clock[i][0]<<" "<<clock[i][1]<<endl;
			break;
		}
	}
}
