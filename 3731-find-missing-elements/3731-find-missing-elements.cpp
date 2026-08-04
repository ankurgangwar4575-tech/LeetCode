class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int maxEl=*max_element(nums.begin(),nums.end());
        int minEl=*min_element(nums.begin(),nums.end());
        unordered_set<int>st(nums.begin(),nums.end());
        
        for(int i=minEl;i<=maxEl;i++) {
            if(st.find(i)==st.end())ans.push_back(i);
        }
        
        return ans;
    }
};