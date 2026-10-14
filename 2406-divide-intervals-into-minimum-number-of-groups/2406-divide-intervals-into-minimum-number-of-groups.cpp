class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int maxi=0;
        for(int i=0;i<intervals.size();i++){
            maxi=max(maxi,intervals[i][1]);
        }
        vector<int> vec(maxi+2,0);
        int ans=1;

        for(int i=0;i<intervals.size();i++){
            vec[intervals[i][0]]++;
            vec[intervals[i][1]+1]--;
        }

        int sum=0;
        for(int i=0;i<vec.size();i++){
            sum+=vec[i];
            ans=max(ans,sum);
        }
        return ans;
        //0 2 1 -1 0 0 1 0 -1 0 -2
    }
};