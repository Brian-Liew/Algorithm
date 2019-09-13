#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;
    int matrix[row][col];
    int dp[row][col];
    int path[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cin>>matrix[i][j];
    } 
  
    dp[0][0] = matrix[0][0];
  
    //计算第一列的值
    for(int i = 1; i < row; i ++)
    {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
  
        path[i][0] = 0;
    }
  
    //计算第一行的值
    for(int j = 1; j < col; j++)
    {
        dp[0][j] = dp[0][j- 1] + matrix[0][j];
  
        path[0][j] = 1;
    }
  
    //计算其它的值
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            int direction = dp[i][j-1] < dp[i-1][j] ? 1 : 0;
            dp[i][j] = (direction ?  dp[i][j-1] : dp[i-1][j]) + matrix[i][j];
            path[i][j] = direction;
        }
    }//for
    int lujing[100];
    int len=0;
    int index1=row-1;
    int index2=col-1;

    for(int i=1;i<=row+col-2;i++)
    {
        if(path[index1][index2]==0)
        {
            lujing[len++]=matrix[index1][index2];
            index1=index1-1;
            
        }
        else
        {
            lujing[len++]=matrix[index1][index2];
            index2=index2-1;
        }
    }
    cout<<matrix[0][0]<<endl;
    for(int i=len-1;i>=0;i--)
        cout<<lujing[i]<<endl;
    cout<<dp[row-1][col-1]<<endl; 
}
