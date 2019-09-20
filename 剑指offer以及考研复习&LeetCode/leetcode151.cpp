class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string s1,res;
        while(ss>>s1)
        {
        	res.insert(0,+" ");
        }
        if(res.size())
        {
        	return string(res.begin(),res.end()-1);
        }
        return "";
    }
};