#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
	char* ss=new char[100];
	while(scanf("%s",ss)!=EOF)
	{
	
		int sum=0;
		
		for(int i=strlen(ss)-1;i>=2;i--)
		{
		
			char temp=ss[i];
		
			if(temp>='A'&&temp<='Z')
			sum=sum+(int(temp-'A')+10)*pow(16,strlen(ss)-1-i);
			else if(temp>='a'&&temp<='z')
			sum=sum+(int(temp-'a')+10)*pow(16,strlen(ss)-1-i);
			else
			sum=sum+int(temp-'0')*pow(16,strlen(ss)-1-i);
			
		}
		cout<<sum<<endl;
}
	
}
