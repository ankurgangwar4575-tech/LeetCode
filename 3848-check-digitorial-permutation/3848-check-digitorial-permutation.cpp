class Solution {
public:
    bool isDigitorialPermutation(int n) {
       vector<int>factorial={1,1,2,6,24,120,720,5040,40320,362880};
       int factSum=0;
       int temp=n;
       while(temp>0){
        factSum+=factorial[temp%10];
        temp/=10;
       } 
       string s1=to_string(factSum);
       string s2=to_string(n);
       sort(s1.begin(),s1.end());
       sort(s2.begin(),s2.end());
       return s1==s2;
    }
};