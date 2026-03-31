#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int wordLadder(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord not in list
        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q; // {word, steps}
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If reached endWord
            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (st.find(temp) != st.end()) {
                        q.push({temp, steps + 1});
                        st.erase(temp); // mark visited
                    }
                }
            }
        }

        return 0; // no path found
    }
};
int main() {
    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution obj;
    int result = obj.wordLadder(beginWord, endWord, wordList);

    cout << "Shortest Transformation Length: " << result;

    return 0;
}