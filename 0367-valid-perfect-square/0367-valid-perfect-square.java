class Solution {
    public boolean isPerfectSquare(int num) {
     int i=1;
     int j=num;
     while(i<=j){
        int m=i+(j-i)/2;
        long sq = (long) m * m;
        if(sq==num) return true;
        else if(sq<num) i=m+1;
        else j=m-1;
     }   
     return false;
    }
}