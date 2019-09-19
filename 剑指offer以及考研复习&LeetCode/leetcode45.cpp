class Solution {
public:
    int jump(vector<int>& nums) {
        int num=nums.size();
        typedef pair<int,int > Pair;
	int visit[num]={0};
	visit[0]=1;
	queue<Pair> Q;
	Q.push(make_pair(0,0));
	while(Q.size())
	{
		Pair cur=Q.front();
		Q.pop();
		if(cur.first==num-1)
			return cur.second;
		for(int i=min(cur.first+nums[cur.first],num-1);i>=cur.first;i--)
		{
			if(!visit[i])
			{
				if(i==num-1)
					return cur.second+1;
				visit[i]=1;
				Q.push(make_pair(i,cur.second+1));
			}
		}
	}
	return -1;
    }
};