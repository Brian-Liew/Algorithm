class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        bool dp[1111][1111];
	memset(dp,false,sizeof(dp));
	dp[0][0]=true;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int dis=stones[i]-stones[j];
            if(dis>=1110)
                continue;
			if(dp[j][dis]||(dp[j][dis-1]&&dis>0)||dp[j][dis+1])
				dp[i][dis]=true;

		}
	}
	for(int i=0;i<n;i++)
	{
		if(dp[n-1][i]==true)
		{
			return true;
		}
	}
	return false;
    }
};