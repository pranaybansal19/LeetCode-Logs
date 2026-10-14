class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        int start=intervals[0][0];
        int end=intervals[0][1];

        vector<vector<int>> vec;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }else{
                vec.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        vec.push_back({start,end});
        return vec;
        
    }
};