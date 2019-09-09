//用两个栈来实现队列：
void push(int node)
{
	stack1.push(node);
}
void pop()
{
	if(stack2.empty())
	{
		while(stack1.size(!=0))
		{
			int data=stack1.top();
			stack1.pop();
			stack2.push(data);
		}
		int data=stack2.top();
		stack2.pop();
		return data;
	}
}