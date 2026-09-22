// Time: O(NL² + PNL)
// Space: O(NL + PNL)
// where N = number of words, L = length of words, P = number of shortest paths.

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        int len = beginWord.size();

        if(!st.contains(endWord)) return {};

        queue<vector<string>> q;
        q.push({beginWord});
        st.erase(beginWord);

        vector<vector<string>> ans;
        bool found = false;

        while(!q.empty()) {
            int size = q.size();
            vector<string> levelWords;
            for(int i = 0; i < size; ++i) {
                vector<string> temp = q.front();
                q.pop();
                string lastWord = temp.back();
                if(lastWord == endWord) {
                    ans.push_back(temp);
                    found = true;
                }
                for(int i = 0; i < len; ++i) {
                    char ori = lastWord[i];
                    for(char c = 'a'; c <= 'z'; ++c) {
                        lastWord[i] = c;
                        if(st.contains(lastWord)) {
                            levelWords.push_back(lastWord);
                            temp.push_back(lastWord);
                            q.push(temp);
                            temp.pop_back();
                        }
                    }
                    lastWord[i] = ori;
                }
            }
            if(found) break;
            for(string& str: levelWords) {
                if(st.contains(str)) {
                    st.erase(str);
                }
            }
        }

        return ans;
    }
};

// Below is the optimized approach for leetcode submission.
// Time: O(26 * L^2 * (N + P))
// Space: O(N * L + P * L )
// where P = the sum of the lengths of all shortest paths

class Solution {
public:
    void dfs(vector<string>& temp, vector<vector<string>>& ans, string& beginWord, int len, unordered_map<string, int>& mp) {
        if(temp.back() == beginWord) {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            return;
        }
        string str = temp.back();
        for(int i = 0; i < len; ++i) {
            char ori = str[i];
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                str[i] = ch;
                if(mp.find(str) != mp.end() && mp[str] == mp[temp.back()] - 1) {
                    temp.push_back(str);
                    dfs(temp, ans, beginWord, len, mp);
                    temp.pop_back();
                }
            }
            str[i] = ori;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        int len = beginWord.size();
        if(!st.contains(endWord)) return {};
        unordered_map<string, int> mp;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        mp[beginWord] = 1;

        while(!q.empty()) {
            auto [str, level] = q.front();
            q.pop();
            if(str == endWord) break;
            for(int i = 0; i < len; ++i) {
                char ori = str[i];
                for(char c = 'a'; c <= 'z'; ++c) {
                    str[i] = c;
                    if(st.contains(str)) {
                        st.erase(str);
                        q.push({str, level + 1});
                        mp[str] = level + 1;
                    }
                }
                str[i] = ori;
            }
        }

        vector<vector<string>> ans;
        vector<string> temp = {endWord};
        dfs(temp, ans, beginWord, len, mp);
        return ans;
    }
};