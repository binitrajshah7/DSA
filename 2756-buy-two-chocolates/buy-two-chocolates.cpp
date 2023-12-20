class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int left_money = money - prices[0] - prices[1];
        return left_money>=0? left_money: money;
    }
};