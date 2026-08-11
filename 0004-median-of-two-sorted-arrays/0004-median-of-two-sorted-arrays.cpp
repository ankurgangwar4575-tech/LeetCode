class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }
        while(i<nums1.size()) temp.push_back(nums1[i++]);
        while(j<nums2.size()) temp.push_back(nums2[j++]);
        double median=(temp.size() & 1) ==1 ? temp[temp.size()/2.0f]:(temp[(temp.size()-1)/2]+temp[(temp.size()-1)/2+1])/2.0f;
        return median;
    }
};