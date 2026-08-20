class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        if(n==0)
        {
            return 0;
        }
        int longest=1;
        unordered_set<int>st(nums.begin(),nums.end());
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int count=1;
                int x=it;
                while(st.find(x+1)!= st.end())
                {
                    count+=1;
                    x+=1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};