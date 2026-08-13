class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                mp1[nums[i] ^ nums[j]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (auto& it : mp1)
                mp2[nums[i] ^ it.first];
        }
        return mp2.size();
    }
};