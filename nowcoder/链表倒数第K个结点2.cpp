#include<iostream>
using namespace std;
struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
    ListNode(int x){
    	m_nKey=x;
    	m_pNext=NULL;
    }
};
int main()
{
	ListNode *L=new ListNode(1);
	ListNode *p=L;
	for (int i=2;i<=7;i++)
	{
		ListNode *t=new ListNode(i);
		p->m_pNext=t;
		p=t;
	}
	int k;
	cin>>k;
	if(L==NULL||k==0)
    		return NULL;

    ListNode* fast=L;
    ListNode* low=L;
    for(int i=0;i<k-1;i++)
    {
    	if(fast->m_pNext!=NULL)
    	fast=fast->m_pNext;
    else
    	return NULL;
    }
    while(fast->m_pNext!=NULL)
    {
    	fast=fast->m_pNext;
    	low=low->m_pNext;
    }
    cout<<low->m_nKey<<endl;
}