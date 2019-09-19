class Solution {
public:
    bool isMatch(string s, string p) {
        int len1=s.size();
	int len2=p.size();
	bool dp[len1+1][len2+1];
	for(int i=len1;i>=0;i--)
	{
		for(int j=len2;j>=0;j--)
		{
			if(i==len1&&j==len2)
			{
				dp[i][j]=1;
				continue;
			}
			else if(i==len1)
			{
				dp[i][j]=(p[j]=='*' &&dp[i][j+1]) ? 1:0;

			}
			else if (j==len2)
			{
				dp[i][j]=0;
			}
			else
			{
				if(s[i]==p[j]||p[j]=='?')
					dp[i][j]=dp[i+1][j+1];
				else if(p[j]=='*')
					dp[i][j]=dp[i+1][j]||dp[i][j+1];
				else
					dp[i][j]=0;
			}
		}
	}
	return dp[0][0];
    }
};