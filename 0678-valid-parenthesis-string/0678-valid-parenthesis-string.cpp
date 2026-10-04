
class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0;

        // Left to right: check that every ')' can be matched
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '*') {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt < 0) return false;
        }

        cnt = 0;

        // Right to left: check that every '(' can be matched
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt < 0) return false;
        }

        return true;
    }
};
