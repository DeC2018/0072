#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        
        for (int j = 0; j <= m; j++) prev[j] = j;
        
        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

int main() {
    Solution solution;
    
    string word1 = "horse";
    string word2 = "ros";
    cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << endl;
    cout << "Output: " << solution.minDistance(word1, word2) << endl;
    
    word1 = "intention";
    word2 = "execution";
    cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << endl;
    cout << "Output: " << solution.minDistance(word1, word2) << endl;
    
    return 0;
}
