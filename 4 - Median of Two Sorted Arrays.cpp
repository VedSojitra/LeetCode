class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int>merged;

        for(int i = 0; i<n; i++){
            merged.push_back(nums1[i]);
        }
        for(int i = 0; i<m; i++){
            merged.push_back(nums2[i]);
        }
        sort(merged.begin(),merged.end());

        int size = merged.size();
        int s = 0;
        int e = size - 1;
        int mid = s + (e-s)/2;
        
        if(size%2==0){
            double ans = ((merged[mid] + merged[mid+1]) / 2.0);
            return ans;
        }
        else{
            return merged[mid];
        }
    }
};
