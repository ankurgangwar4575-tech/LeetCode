class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
       int n=nums.size(),q=queries.size();
        for(auto &query:queries){
           for(int i=query[0];i<query[1]+1;i+=query[2]){
            nums[i]=(1LL*nums[i]*query[3])%mod;
           } 
        }
       int ans=0;
       for(auto &el:nums)ans^=el;

       return ans; 
    }
};