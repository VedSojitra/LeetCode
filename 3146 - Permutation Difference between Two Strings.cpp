class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum = 0;
        int value = 0;
        for(int i = 0; i<s.length(); i++){
            for(int j = 0; j<s.length(); j++){
                if(s[i]==t[j]){
                    value = abs(i-j);
                    sum += value;
                }
            }
        }
        return sum;
    }
};
