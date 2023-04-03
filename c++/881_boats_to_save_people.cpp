class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat_count = 0;
        int l = 0, r = people.size() - 1;

        // Sort people from smallest to heaviest
        sort(people.begin(), people.end());
        
        // Two pointers loop from front and back
        while (l <= r) {
            // Pair the heaviest and lightest person, if they are over the limit
            // together then send the heaviest person alone
            if (people[l] + people[r] <= limit) {
                boat_count += 1;
                l += 1;
                r -= 1;
            } else {
                boat_count += 1;
                r -= 1;
            }
        }

        return boat_count;
    }
};
