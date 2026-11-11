class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        if(mx==0) return "0";
        
        vector<string> vec;
        for (int i : nums) {

            vec.push_back(to_string(i));
        }
        
        sort(vec.begin(), vec.end(), []( string a, string b) {
            if (a + b != b + a) {
                return a + b > b + a;
            }

            return a.size() < b.size();
        });

        string s = "";
        for (string a : vec) {

            s += a;
        }
        // if(stoi(s)==0) return "0";

        return s;
    }
};