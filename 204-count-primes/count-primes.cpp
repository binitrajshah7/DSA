class Solution {
public:
    // Algorithm: Sieve of Erastothenis
    int countPrimes(int n) {
        vector<bool> is_prime(n+1, true);
        // if current is prime then mark all multiples as non prime going till sqrt(n) cause it will have atleast one factor that
        // is less than sqrt(n)
        for(int i=2; i<sqrt(n); i++){
            if(is_prime[i]){
                // starting from i*i & marking all multiples as false
                // starting at i*i cause all the markings will have been done by previous smaller element
                // eg: for marking 5 multiple we start from 25 cause all less than 25 is marked by 2, 3
                for(int j=i*i; j<=n; j+=i){
                    is_prime[j] = false;
                }
            }
        }

        int result = 0;
        for(int i=2; i<n; i++){
            if(is_prime[i])
                result++;
        }
        return result;
    }

};