class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });

        int q=queries.size();
        vector<pair<int, int>> sortedQ;
        for(int i=0;i<q;i++){
            sortedQ.push_back({queries[i],i});
        }
        sort(sortedQ.begin(),sortedQ.end());

        vector<int> freq(n+1,0);
        vector<int> ans(q);
        int cnt=0;
        int l=0,r=0;

        for(auto it:sortedQ){
            // first we will add all the values till tar, later we will trim down the search to window x
            int tar=it.first;
            int idx=it.second;
            while(r<logs.size() && logs[r][1]<=tar){
                int id=logs[r][0];

                if(freq[id]==0){
                    cnt++;
                }
                freq[id]++;
                r++;
            }
            // for example in case of 10, all the logs that started before 10 are taken

            while(l<r && logs[l][1]<tar-x){
                int id=logs[l][0];

                freq[id]--;
                if(freq[id]==0){
                    cnt--;
                }
                l++;
            }
            ans[idx]=n-cnt;
        }

        return ans;
        
    }
};