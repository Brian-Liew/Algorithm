#include<iostream>
#include<string>
#include<algorithm>
#include<set>
 
using namespace std;
 
int main()
{
	string instr="12ere2",outstr;
	set<char>  sc;
	
	for(int i=0;i<instr.size();i++)
	{
		if(sc.find(instr[i])==sc.end())
		{
			sc.insert(instr[i]);
			outstr.append(1,instr[i]);
		}
	}
	cout<<outstr<<endl;
   return 0;
}
