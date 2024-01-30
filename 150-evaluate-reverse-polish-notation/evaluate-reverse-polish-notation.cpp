class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> numbers;

        for(auto token: tokens){
            if(token.size() > 1 || isdigit(token[0]))
                numbers.push(stoi(token));
            
            else{
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();

                switch(token[0]){
                    case '+':
                        numbers.push(first+second);
                        break;
                    case '-':
                        numbers.push(second-first);
                        break;
                    case '*':
                        numbers.push(first*second);
                        break;
                    case '/':
                        numbers.push(second/first);
                        break;
                }

            }

        }
        return numbers.top();
    }
};