/*
感觉这道题就是要处理的数据比较多，应该加入一些东西，例如：
std::ios::sync_with_stdio(false);
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	cin.sync_with_stdio(false);
	int num;
	cin>>num;
	if(num==0)
		return 0;
	//vector<int> test;
	long long cur,task;
	cin>>cur>>task;
	long long max_task=task;
	//test.push_back(task);
	long long cur_next,task_next;
	for(int i=1;i<num;i++)
	{
		cin>>cur_next>>task_next;
		long long minu=min(cur_next-cur,task);
		task=task-minu;
		task=task+task_next;
		if(task>max_task)
			max_task=task;
		cur=cur_next;
	}
	cout<<cur+task<<" "<<max_task<<endl;
}
