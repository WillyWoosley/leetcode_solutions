class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int lowest = prices[0];

        for (int n : prices) {
            max_profit = max(max_profit, n - lowest);
            if (n < lowest) {
                lowest = n;
            }
        }

        return max_profit;
    }
};
