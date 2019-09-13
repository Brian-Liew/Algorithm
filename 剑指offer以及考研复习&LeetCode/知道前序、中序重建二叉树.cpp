//知道一颗树的先序遍历和中序遍历，重建这颗树：
TreeNode * reConstuct(vector<int> pre,vector<int> vin)
{
	if(pre.size()==0)
		return NULL;
	vector<int> left_pre,right_pre,left_vin,right_vin;
	//第一步找到先序遍历的头部
	TreeNode* head=new TreeNode(pre[0]);
	//第二步找到对应的中序遍历的头部
	int root=0;
	for(int i=0;i<pre.size();i++)
	{
		if(vin[i]==pre[0])
		{
			root=i;
			break;
		}

	}
	//第三部区分出左右子树
	for(int i=0;i<root;i++)
	{
		left_vin.push(vin[i]);
		left_pre.push(pre[i+1]);
	}
	for(int i=root+1;i<pre.size();i++)
	{
		right_vin.push(vin[i]);
		right_pre.push(pre[i]);
	}
	//第四部，递归重建，NICE
	head->left=reConstuct(left_pre,left_vin);
	head->right=reConstuct(right_pre,right_vin);
	return head;
}