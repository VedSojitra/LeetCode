class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i =m; i<n+m ; i++){
            nums1[i] = nums2[j];
            j++;
        }

        for(int i=0; i<m+n-1; i++){
            int minvalue = i;

            for(int j =i+1;j<m+n;j++){
                if(nums1[j] < nums1[minvalue]){
                    minvalue = j;
                }
            }
            swap(nums1[i],nums1[minvalue]);
        }
    }
};
