class Solution {
public:
int best=INT_MAX;
    int helper(int row,int value,vector<vector<int>>&grid,vector<unordered_map<int,int>>&dp){
        if(row==grid.size()){
            best = min(best, value);
    return value;
        }
        if(value >= best) return INT_MAX;
        if(dp[row].find(value)!=dp[row].end())return dp[row][value];
        int ans=INT_MAX;
        for(int &el:grid[row]){
            ans=min(ans,helper(row+1,value|el,grid,dp));
        }
        return dp[row][value]=ans;
    }
    int minimumOR(vector<vector<int>>& grid) {
      int m=grid.size();
        int n=grid[0].size();
        for(auto &row:grid)sort(row.begin(),row.end());
        vector<unordered_map<int,int>>dp(m);
        return helper(0,0,grid,dp);
    }
};