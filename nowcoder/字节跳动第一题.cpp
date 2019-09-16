/*
字节跳动第四题，但是因为是连续输入的原因导致没能ac
这里也学到了，主要是运用简单的方法就可以解决的；
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int array[n];
		for(int i=0;i<n;i++)
			cin>>array[i];
		int D;
		cin>>D;
		sort(array,array+n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int temp=array[i]+array[j];
				int num=lower_bound(array+j+1,array+n,D-temp)-(array+j+1);
				sum+=num;
			}
		}
		cout<<sum<<endl;

	}
}