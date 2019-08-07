#include<iostream>
#include<algorithm>
using namespace std;
struct job
{
	int dif;
	int money;
};
struct  people
{
	int index;
	int dif;
	int money;
};
bool cmp1(job a,job b)
{
	return a.dif<b.dif;
}
bool cmp2(people a,people b)
{
	return a.dif<b.dif;
}
bool cmp3(people a,people b)
{
	return a.index<b.index;
}
int main()
{
	int num_of_job,num_of_people;
	cin>>num_of_job>>num_of_people;
	job *Job=new job[num_of_job];
	people *People =new people[num_of_people];
	for(int i=0;i<num_of_job;i++)
	{
		cin>>Job[i].dif>>Job[i].money;
	}
	for(int i=0;i<num_of_people;i++)
	{
		cin>>People[i].dif;
		People[i].index=i;
	}
	sort(Job,Job+num_of_job,cmp1);
	sort(People,People+num_of_people,cmp2);
	int j=0;int maxmoney=0;
	for(int i=0;i<num_of_people;i++)
	{
		while(j<num_of_job)
		{
			if(Job[j].dif>People[i].dif)
				break;
			else
			{
				maxmoney=max(maxmoney,Job[j].money);
				j++;
			}
		}
		People[i].money=maxmoney;
	}
	sort(People,People+num_of_people,cmp3);
	for(int i=0;i<num_of_people;i++)
	{
		cout<<People[i].money<<endl;
	}
}