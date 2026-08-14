class Solution {
    public int[] twoSum(int[] array, int k) {
        int firstIdx = -1, lastIdx = -1;
        HashMap<Integer,Integer> hashMap=new HashMap<>();
        for(int i=0;i<array.length;i++){
            if(hashMap.containsKey(k-array[i])) {
                lastIdx=i;
                firstIdx=hashMap.get(k-array[i]);
            }
             hashMap.put(array[i], i);
        }
        int [] ansArray={firstIdx,lastIdx};
        return ansArray;
    }
}