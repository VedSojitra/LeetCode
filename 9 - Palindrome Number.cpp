class Solution {
public:
    bool isPalindrome(int x) {
        int ans = 0;
        if(x<0){
            return 0;
        }
        int n = x;

        while(n != 0){
            int digit = n % 10;
            if(ans < INT_MAX/10){
                ans  = ans * 10 + digit;
            }
            n = n / 10;
        }
        return x == ans;
    }
};
