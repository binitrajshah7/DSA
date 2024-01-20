class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // Get the size of the input array
        int n = arr.size();

        // Arrays to store the indices of the previous and next smaller elements for each index
        vector<int> pre_smaller(n), next_smaller(n);

        // Stacks to keep track of indices of elements
        stack<int> s1, s2;

        // Initialize the arrays with default values
        for (int i = 0; i < n; i++) {
            pre_smaller[i] = i;
            next_smaller[i] = n - i - 1;
        }

        // Loop to update the next smaller array using the first stack (s1)
        for (int i = 0; i < n; i++) {
            // Update the next smaller array while maintaining a monotonic decreasing stack
            while (!s1.empty() && arr[s1.top()] >= arr[i]) {
                next_smaller[s1.top()] = i - s1.top() - 1;
                s1.pop();
            }
            s1.push(i);
        }

        // Loop to update the previous smaller array using the second stack (s2)
        for (int i = n - 1; i >= 0; i--) {
            // Update the previous smaller array while maintaining a monotonic decreasing stack
            while (!s2.empty() && arr[s2.top()] > arr[i]) {
                pre_smaller[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }
            s2.push(i);
        }

        // Initialize result and modulo value
        int ans = 0;
        int mod = 1e9 + 7;

        // Loop to calculate the final result
        for (int i = 0; i < n; i++) {
            ans=(ans+(arr[i]*(long long)(next_smaller[i]+1)*(pre_smaller[i]+1))%mod)%mod;
        }

        // Return the final result
        return ans;
    }

};