class Solution {
    public List<List<Integer>> aggregateTimeSeries(int[][] series1, int[][] series2) {
        int n = series1.length;
        int m = series2.length;
        List<List<Integer>> ans = new ArrayList<>();
        int i = 0, j = 0;
        int k = 0;
        while (i < n && j < m) {
            if (series1[i][0] == series2[j][0]) {
                ans.add(new ArrayList<>());
                ans.get(k).add(series1[i][0]);
                ans.get(k).add(series1[i][1] + series2[j][1]);
                i++;
                j++;
            } else if (series1[i][0] < series2[j][0]) {
                ans.add(new ArrayList<>());
                ans.get(k).add(series1[i][0]);
                ans.get(k).add(series1[i][1] + series2[j][1]);
                i++;
            } else {
                ans.add(new ArrayList<>());
                ans.get(k).add(series2[j][0]);
                ans.get(k).add(series1[i][1] + series2[j][1]);
                j++;
            }
            k++;
        }
        while (i < n) {
            ans.add(new ArrayList<>());
            ans.get(k).add(series1[i][0]);
            ans.get(k).add(series1[i][1]);
            i++;
            k++;
        }
        while (j < m) {
            ans.add(new ArrayList<>());
            ans.get(k).add(series2[j][0]);
            ans.get(k).add(series2[j][1]);
            j++;
            k++;
        }
        return ans;
    }
}