class Solution:

    def singleNumber(self, nums: List[int]) -> List[int]:
        # Stores total_xor of all the elements in the array 
        total_xor = 0
        for e in nums:
            total_xor ^= e
        # total_xor = 3^5

        # here d is set at last set bit other all bits are 0
        # eg: total_xor = 6 [101] then d = 001 
        # setting it this way implies that at this point the bit of 3 and 5 differed so it is 1 after xor op
        d = total_xor & (-total_xor)

        # Grouping it into 2 categories where bit is set at this position and 
        # not set at this position
        result = [0, 0]
        for e in nums:
            if(e & d):
                result[0] ^= e
            else:
                result[1] ^= e
        return result