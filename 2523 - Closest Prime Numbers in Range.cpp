class Solution {
private:
    vector<int> generateprime(int range){
        vector<bool>store(range, true);
        vector<int> prime;
        store[0]=store[1]=0;
        for(int i = 2; i<=range; i++){
            if(store[i]){
                prime.push_back(i);
                for(int j = i*i; j<range; j=j+i){
                    store[j] = 0;
                }
            }
        }
        return prime;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes = generateprime(sqrt(right));
        vector<bool> dummy(right-left, true);
        vector<int> store;
        if(left == right){
            return{-1, -1};
        }

        for(auto i: primes){
            int firstmultiple = (left/i)*i;
            if(firstmultiple<left) firstmultiple += i; 
            for(int j = max(firstmultiple, i*i); j<=right; j+=i){
                dummy[j-left] = 0;
            }
        }
        if(left == 1){
            dummy[0] = 0;
        }
      
        for(int i = left; i<=right; i++){
            if(dummy[i-left]){
                store.push_back(i);
            }
        }
        for(int i = 0; i<store.size(); i++){
            cout<<store[i]<<endl;
        }
        
        int min = INT_MAX;
        int first, second;

        if(store.size()<=1 ){
            return {-1, -1};
        }
        else{
            for(int i = 1; i<store.size(); i++){

                if(store[i]-store[i-1]<min){
                    min = store[i]-store[i-1];
                    first = store[i-1];
                    second = store[i];
                }
            }
           
        }
        return {first, second};
    }
};    
