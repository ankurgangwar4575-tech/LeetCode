class Solution {
public:
    long long mypow(long long  base, long long exp, long long mod){
        long long res=1;
        base%=mod;
        while(exp>0){
            if(exp & 1) res=(res*base)%mod;
            base=(base*base)%mod;
        exp=exp>>1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenCount=((n&1)==1) ? n/2+1:n/2;
        long long oddCount=n/2;
        long long mod=1000000007;
       long long  even=mypow(5,evenCount,mod);
       long long  odd=mypow(4,oddCount,mod);
       long long ans=(even*odd)%mod;
        return  (int)ans%mod;
    }
};