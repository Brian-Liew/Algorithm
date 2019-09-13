void dfs(vector<int> > &grid,int x,int y int count,int n, int process)
{
	if(x<0||x>=n||y<0||y>=n||grid[x][y]==-1)
	{
		return ;
	}
	else if(x==0||y==0&&process==2)
	{
		maxCount=max(maxCount,count);
	}
	else
	{
		if(x==n-1&&y==n-1&&process==1)
			process=2;
		bool hasCherry =false;
		if(grid[x][y]==1)
		{
			hasCherry=true;
			count++;
			grid[x][y]=0;
		}
		if(process==1)
		{
			dfs(grid,x+1,y,count,n,process);
			dfs(grid,x,y+1,count,n,process);
		}
		else if (process==2)
		{
			dfs(grid,x-1,y,count,n,process);
			dfs(grid,x,y-1,count,n,process);
		}
		if(hasCherry==true)
		{
			hasCherry=false;
			count--;
			grid[x][y]=1;
		}
	}

}