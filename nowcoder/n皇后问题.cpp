#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
int n,i;//n记录是多少个皇后的问题，i记录的是第几个皇后 
int a[101];//数组下标表示行号，数组值表示列号 
int sum;//记录有多少种解法 
bool judge(int a[],int N) //检测当前位置的皇后是否是合法的 
{  
    for(int j=1;j<N;j++)  
    {  
        if(abs(a[j]-a[N])==abs(j-N) || a[j]==a[N])//////////////见下面注释  
            return false;  
    }  
    return true;  
}  
void print_ans(){//打印输出每一种解的方案。 
    for(int j=1;j<=n;j++)
        cout<<"<"<<j<<","<<a[j]<<">"<<"   ";
    cout<<endl; 
} 
void solve(int i){//使用该函数来实现递归检测八皇后合法性
    if(i>n){//递归出口，每出现一次，意味着得到了一种解 
        sum++; 
        print_ans();//输出答案； 
        return ;
    } 
    for(int j=1;j<=n;j++){//每一行8列都尝试走一遍 
        a[i]=j;
        if(judge(a,i)){//判断当前皇后是否满足要求，满足则递归至下一层 
            solve(i+1);
        }            
    }
}
int main(){
    cin>>n;
    sum=0; 
    solve(1);//
    cout<<"一共有多少组解："<<sum; 
}
