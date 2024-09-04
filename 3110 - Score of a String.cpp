class Solution {
public:
    int scoreOfString(string s) {
        int value = 0;
        int sum = 0;
        for(int i = 0; i<s.length()-1; i++){
            sum = s[i]-s[i+1];
            if(sum < 0){
                sum = sum * -1;
            }
            value = value + sum;
        }
        return value;
    }
};
