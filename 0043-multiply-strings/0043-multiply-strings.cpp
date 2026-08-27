class Solution {
public:
string addTwoStrings(string s1,string s2){
    if(s1.empty())return s2;
    if(s2.empty())return s1;
    string ans="";
    int i=s1.length()-1,j=s2.length()-1,carry=0;
    while(i>=0 || j>=0){
        int sum=0;
        if(i>=0){
            sum=sum+(s1[i]-'0');
            i--;
        }
        if(j>=0){
            sum=sum+(s2[j]-'0');
            j--;
        }
        sum+=carry;
        ans.push_back((sum%10)+'0');
        carry=sum/10;
    }
    if(carry!=0)ans.push_back(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        vector<string>arr;
        int k=0,n1=num1.length(),n2=num2.length();
        for(int i=n1-1;i>=0;i--){
            string temp="";
            int carry=0;
            int x=num1[i]-'0';
            for(int j=n2-1;j>=0;j--){
                int number=carry+x*(num2[j]-'0');
                temp.push_back((number%10)+'0');
                carry=number/10;
            }
            if(carry!=0)temp.push_back(carry+'0');
            reverse(temp.begin(),temp.end());
            for(int l=0;l<k;l++)temp.push_back('0');
            k++;
            arr.push_back(temp);
        }
        string ans="";
        for(string &s:arr){
            ans=addTwoStrings(ans,s);
        }
        return ans;
    }
};