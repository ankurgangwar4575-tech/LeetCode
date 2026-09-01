class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n=nums.size();
       int maxLen=INT_MIN;
    unordered_map<int,int>mp;
    mp[0]=-1;
    int currSum=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0)nums[i]=-1;
    }
    for(int i=0;i<n;i++){
        currSum+=nums[i];
        if(mp.count(currSum))maxLen=max(maxLen,i-mp[currSum]);
        if(!mp.count(currSum))mp[currSum]=i;
    }

       return maxLen!=INT_MIN?maxLen:0;
    }
};