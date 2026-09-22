// Time: O(N * L^2);
// Space: O(N * L);

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); 
        int len = beginWord.size();
        if(!st.contains(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()) {
            auto [str, steps] = q.front();
            q.pop();
            if(str == endWord) return steps;
            for(int i = 0; i < len; ++i) {
                char ori = str[i];
                for(char c = 'a'; c <= 'z'; ++c) {
                    str[i] = c;
                    if(st.contains(str)) {
                        st.erase(str);
                        q.push({str, steps + 1});
                    }
                }
                str[i] = ori;
            }
        }

        return 0;
    }
};