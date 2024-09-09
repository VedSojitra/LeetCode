class Solution {
private:
    bool isprime(int num){
        if(num==1){
            return false;
        }
        for (int i = 2; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int c = 0;
        int i = left;
        while(i<=right){
            
            if(isprime(__builtin_popcount(i))){
                c++;
            }
            i++;

        }
        return c;
    }
};
