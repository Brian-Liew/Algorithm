#include<iostream>
#include<queue>
using namespace std;
const int maxn=1000;
char maze[maxn][maxn];
bool visited[maxn][maxn];
struct node{int x,y;int step;}S,T,Node;
int n,m;
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
bool isok(int x,int y)
{
	if(x>=n||x<0||y>=m||y<0)
	{
		return false;
	}
	if(maze[x][y]=='*')
	{
		return false;
	}
	if(visited[x][y]==true)
	{
		return false;
	}
	return true;
}
int BFS()
{
	queue<node> q;
	q.push(S);
	while(!q.empty())
	{
		node top = q.front();
		q.pop();
		if(top.x==T.x&&top.y==T.y)
		{
			return top.step;
		}
		for(int i=0;i<4;i++)
		{
			int tmpx=top.x+x[i];
			int tmpy=top.y+y[i];
			if(isok(tmpx,tmpy))
			{
				Node.x=tmpx;
				Node.y=tmpy;
				Node.step=top.step+1;
				q.push(Node);
				visited[tmpx][tmpy]=true;
			}
		}
	}
	return -1;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		getchar();
		for(int j=0;j<m;j++)
		{
			maze[i][j]=getchar();
		}
		//maze[i][m+1]='\0';
	}
	cin>>S.x>>S.y>>T.x>>T.y;
	S.step=0;
	cout<<BFS();
}
