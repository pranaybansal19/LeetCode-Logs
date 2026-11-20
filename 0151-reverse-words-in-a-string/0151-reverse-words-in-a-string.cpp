class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";
        string temp = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (temp != "" && res != "") {
                    res = temp + ' ' + res;
                } else if (temp != "" && res == "") {
                    res = temp + res;
                }
                temp = "";
            } else {
                temp += s[i];
            }
        }
        if (temp != "") {
            if (res != "") {

                res = temp + ' ' + res;
            } else {
                res = temp;
            }
        }
        return res;
    }
};