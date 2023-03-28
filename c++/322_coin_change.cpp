class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> change(amount+1);
        change[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int min_change = -1;
            for (int coin : coins) {
                if (coin <= i && change[i-coin] != -1) {
                    if (min_change == -1) {
                        min_change = 1 + change[i-coin];
                    } else {
                        min_change = min(min_change, 1 + change[i - coin]);
                    }
                }
            }
            change[i] = min_change;
        }

        return change[amount];
    }
};
