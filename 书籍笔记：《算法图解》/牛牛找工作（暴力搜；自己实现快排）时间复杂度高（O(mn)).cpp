#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a[] , int b[])
{
	if(a[1]==b[1])
	{
		return a[0]>b[0];
	}
	return a[1]>b[1];
}
//use the quicksort algorithm to solve the two dimension array
void quicksort(int **a,int left,int right)
{
	int pos1=left;
	int pos2=right;
	if(left<right)
	{
		int temp=a[left][0];
		int temp1=a[left][1];
		while(left<right)
		{
			while(left<right&&(a[right][0]>temp||(a[right][0]==temp&&a[right][1]>temp1)))
				right--;
			a[left][0]=a[right][0];
			a[left][1]=a[right][1];
			while(left<right&&(a[left][0]<temp||(a[left][0]==temp&&a[left][1]<temp1)))
				left++;
			a[right][0]=a[left][0];
			a[right][1]=a[left][1];
		}
		a[left][0]=temp;
		a[left][1]=temp1;
		quicksort(a,pos1,left-1);
		quicksort(a,left+1,pos2);
	}


}
int main()
{
	int num_of_work,num_of_worker;
	cin>>num_of_work>>num_of_worker;
	int **work=new int*[num_of_work];
	for(int i=0;i<num_of_work;i++)
	{
		work[i]=new int[2];
		cin>>work[i][0]>>work[i][1];
	}
	//sort the array by the algorithm in C++,and we get the ascent order
	sort(work,work+num_of_work,cmp);
	//sort the array by the self function,and we get the descent order
	//quicksort(work,0,num_of_work-1);

	int *worker=new int[num_of_worker];
	int *money=new int[num_of_worker];
	for(int i=0;i<num_of_worker;i++)
	{
		cin>>worker[i];
		int cando=worker[i];
		for(int j=0;j<num_of_work;j++)
		{
			if(cando>=work[j][0])
			{
				money[i]=work[j][1];
				break;
			}
		}
	}
	for(int i=0;i<num_of_worker;i++)
		cout<<money[i]<<endl;
	



}
