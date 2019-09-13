class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
      int N=grid.size();
        int maxSize=2*(N)-1;
   int dp[N][N];
   memset(dp,-1,N*N*sizeof(int));
   dp[0][0]=grid[0][0];
   for(int step=1;step<maxSize;step++)
   {
      for(int i=min(N-1,step);i>=0&&i>=step-N+1;i--)
      {
         //if(step-i>=N)
            //continue;
         for(int j=min(N-1,step);j>=0&&j>=step-N+1;j--)
         {
            //if(step-j>=N)
               //continue;

            int i2=step-i;
            int j2=step-j;
            if(grid[i][i2]==-1||grid[j][j2]==-1)
            {
               dp[i][j]=-1;
               continue;
            }
            if(i>0)
            {
               dp[i][j]=max(dp[i-1][j],dp[i][j]);
            }
            if(j>0)
            {
               dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
            if(i>0&&j>0)
            {
               dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            }
            if(dp[i][j]==-1)
            {
               continue;
            }
            if(i==j)
            {
               dp[i][j]+=grid[i][i2];
            }
            else
            {
               dp[i][j]+=grid[i][i2]+grid[j][j2];
            }
         }
      }
   }
   return max(dp[N-1][N-1],0);
    }
};