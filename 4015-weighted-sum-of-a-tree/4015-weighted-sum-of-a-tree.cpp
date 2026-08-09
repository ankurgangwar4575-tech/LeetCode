using ll = long long;
class Solution {
public:
    ll weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        adj[0].push_back(0);
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);
        queue<int> q;
        vector<ll> depth(n, 0);
        depth[0] = 1;
        q.push(0);
        ll height = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nbr : adj[node]) {
                if (!depth[nbr]) {
                    depth[nbr] = depth[node] + 1;
                    height = max(height, depth[nbr]);
                    q.push(nbr);
                }
            }
        }
        ll ans = nums[0] * height;
        for (int i = 1; i < n; i++)
            ans += nums[i] * (height - depth[i] + 1);
        return ans;
    }
};