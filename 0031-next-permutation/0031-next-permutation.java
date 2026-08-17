class Solution {
    public void reverseArray(int [] nums ,int start,int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    public void nextPermutation(int[] nums) {
      int idxOfSmallestElementFromRight=-1;
        int n=nums.length;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
             idxOfSmallestElementFromRight=i;
             break;   
            }
        }
        if(idxOfSmallestElementFromRight==-1) reverseArray(nums,0,n-1);
        else{
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idxOfSmallestElementFromRight]){
               int temp=nums[idxOfSmallestElementFromRight];
               nums[idxOfSmallestElementFromRight]=nums[i];
               nums[i]=temp;
                break;
            }
        }
      reverseArray(nums,idxOfSmallestElementFromRight+1,n-1);
        }  
    }
}