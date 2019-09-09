//给定一棵树以及每个节点给出了左右子树，以及父子树，求当前节点的下一个节点，
/*
分析：因为在树中，如果一个节点有右子树，那么它的下一个节点就是这个右子树的最左节点，
第二种情况就是一个节点没有右子树，那么它的下一个节点取决于它的父节点，如果它是父节点的
左子树，那么父节点就是下一个节点，如果它是父节点的右子树，那么它要遍历找到父父父节点中
的左子树是它的父父节点的点才算找到。
*/
TreeNode* findthenext(TreeNode* T)
{
	if(T==NULL)
		return NULL;
	if(T->right!=NULL)
	{
		TreeNode* p=T->right;
		while(p->left!=NULL)
			p=p->left;
		return p;
	}
	else if(T->parent!=NULL)
	{
		TreeNode* p=T;
		TreeNode* next=T->parent;
		while(next->right==p&&parent!=NULL)
		{
			p=next;
			next=p->parent;
		}
		return next;
	}
	return NULL;
}