class Solution {
public:
int helper(string s, int i, int sign, long long result){
    if (i >= s.length() || !isdigit(s[i])) return (int)(sign * result);

    int digit = s[i] - '0';

    // Check overflow BEFORE updating result
    if (result > (long long)INT_MAX / 10 || 
        (result == (long long)INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) {
        return sign == 1 ? INT_MAX : INT_MIN;
    }

    result = result * 10 + digit;

    return helper(s,i+1,sign, result);
}
    int myAtoi(string s) {
       int i=0,n=s.length();
       while(i<n && s[i]==' ') i++;
       int sign=1;
     if(i<n && s[i]=='+') { sign = 1; i++; }
else if(i<n && s[i]=='-') { sign = -1; i++; }

      
       return helper(s,i,sign,0);

     
    }
};