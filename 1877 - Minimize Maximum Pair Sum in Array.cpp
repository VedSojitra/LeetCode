class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int maxi = 0;
        int n = nums.size()/2;
        while(n){
            int sum = nums[i] + nums[j];
            if(maxi<sum){
                maxi = sum;
            }
            i++;
            j--;
            n--;    
        }
        return maxi;
    }
};
