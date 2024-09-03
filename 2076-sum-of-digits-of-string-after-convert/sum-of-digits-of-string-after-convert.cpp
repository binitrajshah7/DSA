class Solution {
public:
    int getLucky(string s, int k) {

        // get intial string set for numbers
        string number = "";
        for(char c: s){
            number += to_string(c - 'a' + 1);
        }

        // do k operations & keep decreasing the number
        while(k>0){
            int temp = 0;
            for(char x: number){
                temp += x - '0';
            }
            number = to_string(temp);
            k--;
        }

        return stoi(number);
    }
};