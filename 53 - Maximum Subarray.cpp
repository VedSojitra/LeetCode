class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ma=max(ma,sum);
            if(sum<0){
                sum=0;
            }
        }
        return ma;        
    }
};
