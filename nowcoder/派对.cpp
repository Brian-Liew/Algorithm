/*
对品种数量进行排序，如果比较小的两者加起来的两倍都没有最大的，那么就是比较小的两者的和；
否则，就是三者和除以三；
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        long long *a=new long long[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        long long sum=0;
        if((a[0]+a[1])*2<=a[2])
            sum=a[0]+a[1];
        else
            sum=(a[0]+a[1]+a[2])/3;
        cout<<sum<<endl;
    }
}