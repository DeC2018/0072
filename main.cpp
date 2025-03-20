#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int n = word1.size();
        int m = word2.size();
        std::vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int j = 0; j <= m; j++) prev[j] = j;
        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                }
                else {
                    cur[j] = 1 + std::min(prev[j], std::min(cur[j - 1], prev[j - 1]));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

int main() {
    Solution solution;
    std::string word1 = "horse";
    std::string word2 = "ros";
    std::cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << std::endl;
    std::cout << "Output: " << solution.minDistance(word1, word2) << std::endl;

    word1 = "intention";
    word2 = "execution";
    std::cout << "Input: word1 = \"" << word1 << "\", word2 = \"" << word2 << "\"" << std::endl;
    std::cout << "Output: " << solution.minDistance(word1, word2) << std::endl;

    return 0;
}
