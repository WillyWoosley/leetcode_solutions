class Solution {
public:
    string predictPartyVictory(string senate) {
        int r_vote = 0, d_vote = 0;
        bool r_seen = true, d_seen = true;

        while (r_seen && d_seen) {
            r_seen = false, d_seen = false;
            for (int i = 0; i < senate.size(); i++) {
                if (senate[i] == 'R') {
                    r_seen = true;
                    if (d_vote > 0) {
                        d_vote -= 1;
                        senate[i] = 'E';
                    } else {
                        r_vote += 1;
                    }
                } else if (senate[i] == 'D') {
                    d_seen = true;
                    if (r_vote > 0) {
                        r_vote -= 1;
                        senate[i] = 'E';
                    } else {
                        d_vote += 1;
                    }
                }
            }
        }

        return r_seen ? "Radiant" : "Dire";
    }
};
