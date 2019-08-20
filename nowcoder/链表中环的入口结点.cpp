class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	if(pHead==NULL)
    		return NULL;
    	ListNode *meetingnode=meetingNode(pHead);
    	if(meetingnode==NULL)
    		return NULL;
    	int nodesloop=1;
    	ListNode *Node1=meetingnode;
    	while(Node1->next!=meetingnode){
    		Node1=Node1->next;
    		nodesloop++;
    	}
    	Node1=pHead;
    	for(int i=0;i<nodesloop;i++)
    	{
    		Node1=Node1->next;
    	}
    	ListNode *Node2=pHead;
    	while(Node1!=Node2)
    	{
    		Node1=Node1->next;
    		Node2=Node2->next;

    	}
    	return Node1;
    }
private:
	ListNode* meetingNode(ListNode* pHead){
		ListNode *slow=pHead->next;
		if (slow==NULL)
			return NULL;
		ListNode *fast=slow->next;
		while(fast!=NULL&&slow!=NULL)
		{
			if(fast==slow)
				return fast;
			slow=slow->next;
			fast=fast->next;
			if(fast!=NULL)
			{
				fast=fast->next;
			}
		}
		return NULL;
	}
};