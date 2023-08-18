#include<bits/stdc++.h>
using namespace std;
/*
// Trapping Rain Water
int trap(vector<int>& height) {
    int n = height.size();

    vector<int> lm(n, 0);
    vector<int> rm(n, 0);

    int l_max = 0;
    for (int i = 0; i < n; i++){
        lm[i] = l_max;
        l_max = max(l_max, height[i]);
    }

    int r_max = 0;
    for (int i = n-1; i >= 0; i--){
        rm[i] = r_max;
        r_max = max(r_max, height[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++){
        int cap = min(lm[i], rm[i]) - height[i];
        if (cap > 0)
            water += cap;
    }

    return water;
}

// vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
//     int water = trap(height);
//     cout << water << endl;

*/

/*
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 == 0){
        int idx = n2 / 2;
        cout << idx << endl;
        if (n2 % 2 == 0){
            return double(nums2[idx-1] + nums2[idx]) / 2;
        }
        return nums2[idx];
    }

    if (n2 == 0){
        int idx = n1 / 2;
        if (n1 % 2 == 0){
            return double(nums1[idx-1] + nums1[idx])/2;
        }
        return nums1[idx];
    }
    
    if(n1>n2) 
        findMedianSortedArrays(nums2, nums1);

    int n = n1+n2;
    int partition = (n+1)/2;
    
    int low = 0, high = n1;

    while (low <= high){
        int cut1 = (low + high) / 2;
        int cut2 = partition - cut1;

        int left1 = cut1 == 0? INT_MIN: nums1[cut1-1];
        int right1 = cut1 == n1? INT_MAX: nums1[cut1];
            
        int left2 = cut2 == 0? INT_MIN: nums2[cut2-1];
        int right2 = cut2 == n2? INT_MAX: nums2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if(n%2 == 0){
                int l_max = max(left1, left2);
                int r_min = min(right1, right2);
                return double(l_max+r_min)/2;
            }
            return double(max(left1, left2));
        }
        if (left1 > right2)
            high = high - 1;
        else
            low = low+1;
    }
    return 0.0;
}

int main(){
    vector<int>nums1 {};
    vector<int>nums2 {2, 3};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
*/

/* 
https://leetcode.com/problems/container-with-most-water/
int maxArea(vector<int>& height) {
    int n = height.size();
    int left=0, right=n-1;
    
    int result = 0;
    while(left<right){
        int cap = min(height[left], height[right]) * (right-left);
        cout << "cap: " << cap << " left: " << left << " right: " << right << endl;
        result = max(result, cap);

        if(height[left]<height[right]) left++;
        else if(height[right]<height[left]) right--;
        else{
            left++;
            right--;
        }
    }
    return result;
}


int main(){
    vector<int>height {2, 3, 4, 5, 18, 17, 6};
    cout << maxArea(height) << endl;
    return 0;
} 
*/

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock 
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int profit = 0, min_value=prices[0];

    for (int i = 1; i < n; i++){
        min_value = min(min_value, prices[i]);
        if(prices[i] > prices[i-1]){
            int curr_profit = prices[i] - min_value;
            profit = max(curr_profit, profit);
        }
    }
    return profit;
}

int main(){
    vector<int>prices {7,6,4,3,1};
    cout << maxProfit(prices) << endl;
    return 0;
}
*/

/*
https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/

Hints: Always keep in mind that any point where mid lies it is sure that one half of the array will be sorted
so check which half is sorted and set your high and low to that part according to range
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high)/ 2;
        cout << "low: " << low << " high: " << high <<" mid: " << mid << endl;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid]){
            if (target >= nums[low] && target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else {
            if(target >= nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums {5, 1, 3};
    int target = 3;
    cout << search(nums, target) << endl;
    return 0;
}
*/

/*
https://leetcode.com/problems/number-of-islands
bool isPair(char first, char second){
    return ((first == '(' && second == ')') || (first == '{' && second == '}') || (first == '[' && second == ']'));
}

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else{
            if (!st.empty()){
                char top = st.top();
                st.pop();
                bool check = isPair(top, s[i]);
                if(!check) return false;
            }
            else
                return false;
        }
    }

    if (st.empty())
        return true;
    return false;
}

int main(){
    string s = "";
    cout << isValid(s) << endl;
    return 0;
}
*/


int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();

    return 0;
}

int main(){
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid) << endl;
    return 0;
}