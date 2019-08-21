#include<iostream>
#include<map>
using namespace std;
int main()
{
	int arr[]={2,5,4,6,7,9,10,20,46};
	int target=30;
	map<int,int> test;
	map<int,int>::iterator iter;
	for(int i=0;i<9;i++)
	{
		iter=test.find(arr[i]);
		if(iter!=test.end())
		{
			cout<<test[arr[i]]<<" "<<i<<endl;
			break;
		}
		else
		{
			test[target-arr[i]]=i;
		}

	}
}
