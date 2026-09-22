// using priority queue
// Time: O((V + E) * log(V))
// Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    const long long INF = 1e18;

    vector<long long> dist(V, INF);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d != dist[u])
            continue;

        for(auto [v, wt] : adj[u]) {
            if(d + wt < dist[v]) {
                dist[v] = d + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// using set
// Time: O((V + E) * log(V))
// Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    const long long INF = 1e18;

    vector<long long> dist(V, INF);

    set<pair<long long, int>> st;

    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());

        for(auto [v, wt] : adj[u]) {
            if(d + wt < dist[v]) {
                if(dist[v] != INF) {
                    st.erase({dist[v], v});
                }

                dist[v] = d + wt;
                st.insert({dist[v], v});
            }
        }
    }

    return dist;
}