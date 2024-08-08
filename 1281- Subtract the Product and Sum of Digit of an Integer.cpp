class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        for(int i=1;n!=0;){
            int digit = n%10;
            prod = prod * digit;
            sum = sum + digit;

            n = n/10;
        }
        int result = prod - sum;
        return result;
        
    }
};
