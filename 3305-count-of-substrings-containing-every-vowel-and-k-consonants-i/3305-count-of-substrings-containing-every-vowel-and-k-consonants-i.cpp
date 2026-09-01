class Solution {
public:
    int countConsonant(string &s,int i,int j){
        int ctr=0;
        for(int k=i;k<=j;k++){
            if(s[k]!='a' && s[k]!='e' && s[k]!='i' && s[k]!='o' && s[k]!='u')ctr++;
        }
        return ctr;
    }
    bool checkVowel(string &s,int i,int j){
        bool checkA=false,checkE=false,checkI=false,checkO=false,checkU=false;
        for(int k=i;k<=j;k++){
            if(s[k]=='a')checkA=true;
            else if(s[k]=='e')checkE=true;
            else if(s[k]=='i')checkI=true;
            else if(s[k]=='o')checkO=true;
            else if(s[k]=='u')checkU=true;
            if(checkA && checkE && checkI && checkO && checkU)break;
        }
        return checkA && checkE && checkI && checkO && checkU;
    }
    int countOfSubstrings(string word, int k) {
      int n=word.length();
      if(n<5)return 0;
      int ans=0;
      
      for(int i=0;i<n-4;i++){
        for(int j=i;j<n;j++){
 int consonant=countConsonant(word,i,j);
    if(checkVowel(word,i,j) && consonant==k)ans++;
        }
      }
       
      
      return ans;  
    }
};