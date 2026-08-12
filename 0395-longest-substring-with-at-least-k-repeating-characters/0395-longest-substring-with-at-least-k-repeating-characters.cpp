class Solution {
public:
int helper(string s,int k){
    if(s.length()<k)return 0;
    vector<int>hash(26,0);
    for(char &c:s)hash[c-'a']++;
    int idx=-1;
    for(int i=0;i<s.length();i++){
        if(hash[s[i]-'a']!=0 && hash[s[i]-'a']<k){
            idx=i;
            break;
        }
    }
    if(idx==-1)return s.length();
    int left=helper(s.substr(0,idx),k);
    int right=helper(s.substr(idx+1),k);
    return max(left,right);
}
    int longestSubstring(string s, int k) {
       int n=s.length();
       if(k==1)return n;
      return helper(s,k);
    }
};