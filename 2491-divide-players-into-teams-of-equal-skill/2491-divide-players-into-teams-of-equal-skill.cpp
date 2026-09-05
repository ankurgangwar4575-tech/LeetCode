class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
       long long ans=0;
       sort(skill.begin(),skill.end());
       int n=skill.size();
       long long maxSkill=skill[0]+skill[n-1];
       for(int i=0,j=n-1;i<j;i++,j--){
        long long s=skill[i]+skill[j];
        if(s<maxSkill || s>maxSkill)return -1;
        else{
            ans=ans+(long long)skill[i]*skill[j];
        }
       }
return ans;
    }
};