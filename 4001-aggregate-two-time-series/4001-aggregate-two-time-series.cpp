class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n = series1.size(), m = series2.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (series1[i][0] == series2[j][0]) {
                ans.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
                j++;
            } else if (series1[i][0] < series2[j][0]) {
                ans.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
            } else {
                ans.push_back({series2[j][0], series1[i][1] + series2[j][1]});
                j++;
            }
        }
        while (i < n) {
            ans.push_back({series1[i][0], series1[i][1]});
            i++;
        }
        while (j < m) {
            ans.push_back({series2[j][0], series2[j][1]});
            j++;
        }

        return ans;
    }
};