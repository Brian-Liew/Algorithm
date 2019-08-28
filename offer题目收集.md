### PYTHON：

##### 进程与线程的区别：

进程拥有一个完整的虚拟地址空间，不依赖线程而独立存在；反之，线程是进程的一部分，没有自己的地址空间，与进程内其他线程一起共享分配给该进程的所有资源。

##### 为什么说python的线程是伪线程：

在python的原始解释器CPython中存在着GIL（全局解释器锁），因此在解释执行代码时，会产生互斥锁来限制线程对共享资源的访问，知道解释器遇到I/O操作或者操作次数达到一定数目时才会释放GIL。所以虽然CPython的线程库直接封装了系统的原生线程，但CPython整体作为一个进程，同一时间只会有一个线程在跑，其他处于等待，造成多核CPU中多线程也只是分时切换而已。

##### python的append和extend什么区别：

extend接受一个列表参数，把这个列表的元素添加到列表的尾部，append接受对象参数，把对象添加列表尾部。

### 数据结构：

#### 链表：

##### 找出单链表的的倒数k个元素：

使用两个指针追赶的方法，一个fast一个low，fast先走k步（链表长度应该大于K），然后同时走，当fast走到尾部，slow指的就是倒数第K个。

可以看一下代码（剑指offer）：

```C++
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead==NULL||k==0)
    		return NULL;

    ListNode* fast=pListHead;
    ListNode* low=pListHead;
    for(int i=0;i<k-1;i++)
    {
    	if(fast->next!=NULL)
    	fast=fast->next;
    else
    	return NULL;
    }
    while(fast->next!=NULL)
    {
    	fast=fast->next;
    	low=low->next;
    }
    return low;
    }
};
```



##### 找出单链表中间元素：

使用指针追赶的方法，一个fast，一个low，同时走，fast每次走两步，low每次走一步，当fast到达尾部，slow就是中间。代码参照上一道题。

##### 判断单链表是否有环：

使用指针追赶法，同样每次fast走两步，low走一步，如果相遇则有环，否则fast会遇到NULL退出。

##### 已知单链表有环，如何知道环的长度：

使用追赶法，一个fast每次走两步，一个low每次走一步，找到碰撞点，low再继续走回到原点就是环的长度。

##### 如何找到环的入口结点：

按照上一题的方法找到环的长度，然后从头开始遍历，同样适用追赶法，一个快k步，然后以相同的速度前进，如果遇到就是找到入口。

##### 判断两个无环单链表是否相交：

分别遍历到两个链表尾部，判断是否相同，因为他们如果相交，那么从相交到尾结点是一样的。

##### 如何知道两个单链表是否相交（可能有环）：

根据有没有环进行处理，如果没有环就按照上面的方法处理，如果一个有环一个没有，肯定不相交；如果两个都有环，在A表上进行追赶法，找到碰撞点，如果也在B上，就相交。

##### 寻找两个相交链表的第一个公共节点：

先砍掉长链表的头，让两个链表长度一样长，同时遍历也能找到公共节点。这样的算法时间复杂度是O（m+n），空间复杂是O（max（m，n））

##### 反转链表：

使用三个指针，代表前一个和当前和后一个，遍历交换：（剑指offer）

```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
    	if(pHead==NULL)
    		return NULL;
    	ListNode *preview=NULL;
    	ListNode *now=pHead;
    	ListNode *later=pHead->next;
    	while(later!=NULL)
    	{
    		now->next=preview;
    		preview=now;
    		now=later;
    		later=later->next;
    	}
    	now->next=preview;
    	return now;
    }
};
```

#### 数组：

##### 给定一个数组，给定一个目标数字，找出出现第一位置，如果不存在，返回-1：

使用二分查找，稍微修改一下限定条件：

```c++
#include<iostream>
using namespace std;
int Binary_search(int begin ,int end ,int value,int *list)
{
	int end1=end;
	while(begin<=end)
	{
		int mid=(begin+end)/2;
		if(list[mid]>=value)
			end=mid-1;
		else
			begin=mid+1;
	}
	
	if (begin<end1)
		return begin;
	else
		return -1;
}
int main()
{
	int num;
	int ll[11]={1,2,3,4,5,6,6,6,7,8,9};
	cin>>num;
	cout<<Binary_search(0,10,num,ll)<<endl;


}
```

##### 给定一个数组，里面有很多数字是乱序，找出最大4个数字：

使用堆排序，维护一个存储最大4个数的最大堆，（其实也可以用快排）：

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
    	vector<int> result;
    	int length=input.size();
    	if(length<=0||k<=0||k>length)
    		return result;
    	for(int i=0;i<length;i++)
    	{
    		if(result.size()<k)
    			result.push_back(input[i]);
    		else
    		{
                /*
    			for(int j=k/2-1;j>=0;j--)
    			{
    				HeapAdjust(result,j,k);
    			}
    			for(int j=k-1;j>0;j--)
    			{
    				swap(result[0],result[j]);
    				HeapAdjust(result,0,j);
    			}*/
                sort(result.begin(),result.end());
    			if(result[k-1]>input[i])
    			{
    				result[k-1]=input[i];
    			}
    		}
    	}
    	return result;
    }
private:
	void HeapAdjust(vector<int> &list,int parent,int length)
	{
		int temp=list[parent];
		int child=parent*2+1;
		while(child<length)
		{
			if(child+1<length&&list[child]<list[child+1])
				child++;
			if(temp>=list[child])
				break;
			list[parent]=list[child];
			parent=child;
			child=2*parent+1;
		}
		list[parent]=temp;
	}

};
```

##### 给定一个整数的数组nums，返回相加为target的两个数字的索引值，假设每次输入只有一个答案：

如果是已经排好序的数组，就可以定义一个头指针和一个尾指针，如果它们的和大于结果值，就尾指针往左移，如果小于则头指针向右移。直到相等为止。

如果没有排好序，则可以遍历找，也可以用哈希表进行查找，然后直接找到对应的索引：

```c++
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

```

##### 给定一个字符串，找到最长无重复子字符串（例如给定“abcabcbb”，答案是：“abc”）：

定义两个变量，一个存储最长子字节串的长度，另外一个存储无重复子串左边的起始位置，然后创建一个哈希表，遍历字符串，如果没有出现在哈希表，说明没有遇到这个字符，此时计算最长无重复字串，当哈希表值小于left，说明位置更新了，需要重新计算最长无重复子串，每次在哈希表中对应赋值加一。

```c++
#include<iostream>
#include<map>
using namespace std;
int main()
{
	string ss="pwwkew";
	map<char,int> test;
	map<char,int>::iterator iter;
	int longest=0;
	int left=0;
	for(int i=0;i<ss.size();i++)
	{
		iter=test.find(ss[i]);
		if(iter==test.end()||test[ss[i]]<left)
		{
			longest=max(longest,i-left+1);
			test[ss[i]]=left;
		}
		else
		{
			left=i;
			test[ss[i]]=i;
		}
	}
	cout<<longest<<endl;
}
```

#### 其他：

##### 不适用现成的开根号函数，如何实现开平方根操作：

```python
def sqrt_binary(target):
	left=0;
	right=target;
	mid=(right+left)/2
	while abs(mid*mid-target)>0.000001:
		if mid*mid==target:
			return mid
		elif mid*mid>target:
			right=mid
		else:
			left=mid
		mid=(left+right)/2
	return mid

def sqrt_newton(target):
	k=target
	while abs(k*k-target) > 0.000001:
		k=0.5*(k+target/k)
	return k
```

#### 机器学习：

##### 什么是归一化：

归一化就是将数据变化为（0,1）之间的小数，这样的映射是把有量纲（物理大小与物理单位有关）表达式变为无量纲表达式，成为一种简化运算的纯量，提高迭代求解的收敛速度，提高求解精度。

##### 深度学习中的归一化应该怎么理解：

神经网络的学习过程本质就是为了学习数据分布，一旦训练数据与测试数据分布不同，那么网络的泛化能力（预测能力）也会大大降低，另外，一旦每一批的训练数据的分布各不相同，那么网络每一次迭代的学习都要适应不同的分布，大大降低了训练的速度。对于深度网络的训练，只要其那面的几层发生微笑的裱花，后面几层就会被累积放大小区，一旦某一层的数据分布发生了变化，那么就会导致这一层的网络的需要去适应学习这个新的数据分布，所以将会大幅影响训练速度，因此就要就行白化处理，也就是使得它的均值是0，方差是1。

##### 标准化是什么：

与归一化的区别就是，归一化是将样本的特征值转换到统一量纲下进行映射到[0,1]区间，而标准化是标准化正态分布，将整体数据处理成均值为0，方差为1的数据分布，一般使用的方法是先减去平均值再除以方差。

##### 在推导公式时，为什么要使用向量化：

将多组数据放到一个矩阵里面，进行矩阵运算，简化了运算。

##### sigmoid函数与tanh函数的区别：

值域不同，sigmoid函数将数据映射到0-1的范围，而tanh将数据映射到-1-1的范围内，他们的过零点值不同，一个是0.5，一个是0，当我们偏向于激活函数输入是0，输出是0时采用tanh函数。

#### 业务场景：

##### 给定数据，数据已经标注好，已经做好分类，现在训练一个模型，对新数据进行分类，怎么做？

首先是一个分类问题，第一步是特征工程，对于数据分成两部分，一部分用于训练，另一部分用于测试，然后是对于数据特征的选择，需要进行一定的过滤，（例如，可以随机选取特征，分别计算误差，选出误差相对较小的一部分；或者使用原始所有特征进行训练，剔除权重小的特征，重新训练）；然后是对于一些数据进行过滤，对于一些影响结果很大的干扰数据进行剔除，此外还可以尝试对数据进行归一化处理，将数据无量纲化，然后对于已经处理好的特征送入分类算法中，让其学习，通过测试测试集的精度来进行必要的优化测试。

##### 如果给你一亿个数据，让你找出第1000大的数据，你会怎么做？

可以用堆排序，创建1000个数据的小根堆，先将前1000个数据放到堆里面，然后对于插入的新的数据，如果与小根堆的最下值进行比较，如果比这个值小，那么不插入，如果比这个值大，就插入重新调整遍历，知道终止，输出小根堆的值就是第1000大的数据。

常见的