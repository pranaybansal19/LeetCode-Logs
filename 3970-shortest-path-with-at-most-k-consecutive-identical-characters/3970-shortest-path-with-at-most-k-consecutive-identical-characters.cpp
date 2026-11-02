class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [weigh, node, cnt] = pq.top();
            pq.pop();

            if (weigh != dist[node][cnt])
                continue;

            if (node == n - 1)
                return weigh;

            for (auto [v, d] : adj[node]) {
                int newCnt;

                if (labels[v] == labels[node])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if (newCnt > k)
                    continue;

                int newDist = weigh + d;

                if (newDist < dist[v][newCnt]) {
                    dist[v][newCnt] = newDist;
                    pq.push({newDist, v, newCnt});
                }
            }
        }

        return -1;
    }
};