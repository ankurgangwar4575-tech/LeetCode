class Solution {
public:
    int scoreDifference(vector<int>& nums) {
       bool chance=true; // first player chance
        int firstScore=0,secondScore=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)chance=chance ?false:true;
            if((i+1)%6==0)chance=chance ?false:true;
            if(chance)firstScore+=nums[i];
            else secondScore+=nums[i];
        }

        return firstScore-secondScore;
    }
};