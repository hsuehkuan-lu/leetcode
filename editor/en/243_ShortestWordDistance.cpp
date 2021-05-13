//Given an array of strings wordsDict and two different strings that already exi
//st in the array word1 and word2, return the shortest distance between these two 
//words in the list. 
//
// 
// Example 1: 
//
// 
//Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 
//= "coding", word2 = "practice"
//Output: 3
// 
//
// Example 2: 
//
// 
//Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 
//= "makes", word2 = "coding"
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 1 <= wordsDict.length <= 3 * 104 
// 1 <= wordsDict[i].length <= 10 
// wordsDict[i] consists of lowercase English letters. 
// word1 and word2 are in wordsDict. 
// word1 != word2 
// 
// Related Topics Array 
// 👍 715 👎 54


#include <iostream>
#include <string>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int idx1=-1, idx2=-1, n=wordsDict.size();
        int min_diff = n;
        for(int i=0; i<n; ++i) {
            if(wordsDict[i] == word1)
                idx1 = i;
            else if(wordsDict[i] == word2)
                idx2 = i;
            if(idx1 != -1 && idx2 != -1)
                min_diff = min(min_diff, abs(idx1 - idx2));
        }
        return min_diff;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    return 0;
}