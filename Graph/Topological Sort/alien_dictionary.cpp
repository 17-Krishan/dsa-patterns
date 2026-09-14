// Let L = total number of characters in all words.
// Time: O(L);
// Space: O(1);

class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        int V = 0;

        for(auto &word : words) {
            for(char ch : word) {
                if(!present[ch - 'a']) {
                    present[ch - 'a'] = true;
                    V++;
                }
            }
        }

        for(int i = 0; i < n - 1; i++) {
            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());
            bool found = false;

            for(int j = 0; j < len; j++) {
                if(a[j] != b[j]) {
                    int u = a[j] - 'a';
                    int v = b[j] - 'a';

                    adj[u].push_back(v);
                    indegree[v]++;

                    found = true;
                    break;
                }
            }

            if(!found && a.size() > b.size())
                return "";
        }

        queue<int> q;

        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0)
                q.push(i);
        }

        string ans;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            ans += char(u + 'a');

            for(int v : adj[u]) {
                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        if(ans.size() != V)
            return "";

        return ans;
    }
};