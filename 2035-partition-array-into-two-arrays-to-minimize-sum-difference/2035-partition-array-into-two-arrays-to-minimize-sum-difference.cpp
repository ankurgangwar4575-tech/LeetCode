class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
    int k = n/2;
    int total = accumulate(nums.begin(), nums.end(), 0);

    vector<int> left(nums.begin(), nums.begin()+k);
    vector<int> right(nums.begin()+k, nums.end());

    vector<vector<int>> L(k+1), R(k+1);

    for(int mask=0; mask<(1<<k); mask++){
        int sum=0, cnt=0;

        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
                sum+=left[i];
                cnt++;
            }
        }

        L[cnt].push_back(sum);
    }

    for(int mask=0; mask<(1<<k); mask++){
        int sum=0, cnt=0;

        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
                sum+=right[i];
                cnt++;
            }
        }

        R[cnt].push_back(sum);
    }

    for(int i=0;i<=k;i++)
        sort(R[i].begin(), R[i].end());

    int ans = INT_MAX;

    for(int i=0;i<=k;i++){

        for(int s1 : L[i]){

            int need = total/2 - s1;
            auto &vec = R[k-i];

            auto it = lower_bound(vec.begin(), vec.end(), need);

            if(it != vec.end())
                ans = min(ans, abs(total - 2*(s1 + *it)));

            if(it != vec.begin()){
                --it;
                ans = min(ans, abs(total - 2*(s1 + *it)));
            }
        }
    }

    return ans;
    }
};