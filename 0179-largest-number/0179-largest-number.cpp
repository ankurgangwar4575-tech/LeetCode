class Solution {
public:
    static bool comparator(int a1,int a2){
        string a=to_string(a1),b=to_string(a2);
        return a+ b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comparator);
        string ans="";
        for(int &el:nums){
            ans=ans+to_string(el);

        }
        if(ans[0]=='0' && ans[1]=='0')return "0";
        return ans;
    }
};