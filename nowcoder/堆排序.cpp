#include<iostream>
#include<vector>
using namespace std;
void HeapAdjust(vector<int> &list,int parent,int length)
{
	int temp=list[parent];
	int child=2*parent+1;
	while(child<length)
	{
		if(child+1<length&&list[child]>list[child+1])
			child++;
		if(temp<=list[child])
			break;
		list[parent]=list[child];
		parent=child;
		child=2*parent+1;
	}
	list[parent]=temp;
}


vector<int> HeapSort(vector<int> list){
	int length=list.size();
	for(int i=length/2-1;i>=0;i--)
	{
		HeapAdjust(list,i,length);
	}
	for (int i=length-1;i>0;i--)
	{
		int temp=list[i];
		list[i]=list[0];
		list[0]=temp;
		HeapAdjust(list,0,i);
		cout<<"µÚ£º"<<length-i<<"ÌËÅÅÐò£º";
		for(int i=0;i<list.size();i++)
		{
			cout<<list[i]<<" ";
		}
		cout<<endl;
	}
	return list;
} 
int main()
{
	int arr[]={6,4,8,9,2,3,1};
	vector<int> test(arr,arr+sizeof(arr)/sizeof(arr[0]));
	cout<<"ÅÅÐòÇ°£º";
	for(int i=0;i<test.size();i++)
	{
		cout<<test[i]<<" ";
	}
	cout<<endl;
	vector<int> result;
	result=HeapSort(test);
	cout<<"ÅÅÐòºó£º";
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	
}
