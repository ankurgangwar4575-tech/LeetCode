class Solution {
public:
    int minCost(int n) {
        int ans=0;
        for(int i=1;i<n;i++)ans+=i;
        return ans;
    }
};