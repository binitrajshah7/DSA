class Solution {
public:
    bool is_set_bit(int index, uint32_t number){
        if ((1<<(index-1) & number) != 0)
            return true;
        return false;
    }

    // Intuition: Check if ith bit from last is set or not for whole 32 bit integer
    // if set then we set ith bit from first in our result
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=1; i<=32; i++){
            // checks if ith bit is set or not
            if(is_set_bit(i, n)){
                // if set then we set from ith element of first in result
                result = 1<<(32-i) | result;
            }
        }
        return result;
    }
};