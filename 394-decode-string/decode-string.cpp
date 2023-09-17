class Solution {
public:
    // call by reference is necessary to keep index same at all recursive call
    // else when backtracking our index will move backward in recursion stack
    string decode_string(string s, int &i){
        string result;
        while (i < s.length() && s[i] != ']'){
            // if character is a alphabet we will simply add it to our result
            // our pointer will point to ] braces after last character in last iteration
            if(!isdigit(s[i]))
                result += s[i++];
            else{
                // else it is nums then we will get how many times it is i.e n
                int n = 0;
                while (i<s.length() && isdigit(s[i]))
                    n = n * 10 + (s[i++] - '0');
                // at this point we have skipped the number
                // and skip the '[' braces
                i++;
                // get all the alphabet inside braces in our temporary string
                string temp = decode_string(s, i);
                // skipping ']'
                i++;
                
                // add this to our final result n times
                while(n-- > 0)
                    result += temp;  
            }
        }
        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return decode_string(s, i);
    }
};