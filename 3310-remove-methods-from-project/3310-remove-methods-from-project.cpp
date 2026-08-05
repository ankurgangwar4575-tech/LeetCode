class Solution {
public:
    vector<int> remainingMethods(int n, int k,vector<vector<int>>& invocations){
        vector<vector<int>> adj(n);
        for (auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> vis(n, false);
        dfs(k, vis, adj);
        bool check = false;
        for (auto& edge : invocations) {
            if (!vis[edge[0]] && vis[edge[1]]) {
                check = true;
                break;
            }
        }

        vector<int> ans;
        if (check) {
            for (int i = 0; i < n; i++)
                ans.push_back(i);
            return ans;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }
        return ans;
    }

private:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
        if (!vis[node])
            vis[node] = true;
        for (int& nbr : adj[node]) {
            if (!vis[nbr])
                dfs(nbr, vis, adj);
        }
    }
};