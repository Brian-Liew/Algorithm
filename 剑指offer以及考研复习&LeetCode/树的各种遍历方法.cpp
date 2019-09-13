//实现一个树的先序遍历（使用了递归的方法）：
void preorder(Tree T)
{
	if(T!=NULL)
	{
		visit(T);
		preorder(T->left);
		preorder(T->right);
	}
}

//实现一颗树的中序遍历：（递归法）
void midorder(Tree T)
{
	if(T!=NULL)
	{
		midorder(T->left);
		visit(T);
		midorder(T->right);
	}
}

//实现一颗树的后续遍历：（递归—）
void postorder(Tree T)
{
	if(T!=NULL)
	{
		postorder(T->left);
		postorder(T->right);
		visit(T);
	}
}

//通过使用非递归的方法，也就是循环的方法进行中序排序，需要使用栈
void midorder_cycle(Tree T)
{
	initStack(S);
	Tree p =T;
	while(p!=NULL||!S.empty())
	{
		if(p!=NULL)
		{
			S.push(p);
			p=p->left;
		}
		else
		{
			p=S.pop();
			visit(p);
			p=p->right;

		}
	}
}

//通过使用非递归的方法，实现循环前序排序，需要使用栈
void preorder_cycle(Tree T)
{
	initStack(S);
	Tree p=T;
	while(p!=NULL||!S.empty())
	{
		if(p!=NULL)
		{
			visit(p);
			S.push(p);
			p=p->left;
		}
		else
		{
			p=S.pop();
			p=p->right;
		}
	}
}

//对一颗树进行层次遍历：使用到队列：
void levelorder(Tree T)
{
	initQueue(Q);
	Tree p=T;
	Q.push(p);
	while(!Q.empty())
	{
		p=pop(Q);
		visit(p);
		if(p->left!=NULL)
			Q.push(p->left);
		if(p->right!=NULL)
			Q.push(p->right);
	}
}