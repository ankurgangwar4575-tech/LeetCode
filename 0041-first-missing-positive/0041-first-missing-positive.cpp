class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxEl=*max_element(nums.begin(),nums.end());
        if(maxEl<1) return 1;
        unordered_set<int>st;
        for(int &el:nums){
            if(el<0) continue;
            else st.insert(el);
        }
        for(int i=1;i<=maxEl;i++){
            if(st.find(i)==st.end()){
                return i;
            }
        }
        return maxEl+1;
    }
};