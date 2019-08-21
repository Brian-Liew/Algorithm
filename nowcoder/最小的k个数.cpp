class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
    	vector<int> result;
    	int length=input.size();
    	if(length<=0||k<=0||k>length)
    		return result;
    	for(int i=0;i<length;i++)
    	{
    		if(result.size()<k)
    			result.push_back(input[i]);
    		else
    		{
                /*
    			for(int j=k/2-1;j>=0;j--)
    			{
    				HeapAdjust(result,j,k);
    			}
    			for(int j=k-1;j>0;j--)
    			{
    				swap(result[0],result[j]);
    				HeapAdjust(result,0,j);
    			}*/
                sort(result.begin(),result.end());
    			if(result[k-1]>input[i])
    			{
    				result[k-1]=input[i];
    			}
    		}
    	}
    	return result;
    }
private:
	void HeapAdjust(vector<int> &list,int parent,int length)
	{
		int temp=list[parent];
		int child=parent*2+1;
		while(child<length)
		{
			if(child+1<length&&list[child]<list[child+1])
				child++;
			if(temp>=list[child])
				break;
			list[parent]=list[child];
			parent=child;
			child=2*parent+1;
		}
		list[parent]=temp;
	}

};