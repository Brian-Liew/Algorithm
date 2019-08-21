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