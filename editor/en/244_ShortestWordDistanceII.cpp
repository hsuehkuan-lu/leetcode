//Design a data structure that will be initialized with a string array, and then
// it should answer queries of the shortest distance between two different strings
// from the array. 
//
// Implement the WordDistance class: 
//
// 
// WordDistance(String[] wordsDict) initializes the object with the strings arra
//y wordsDict. 
// int shortest(String word1, String word2) returns the shortest distance betwee
//n word1 and word2 in the array wordsDict. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["WordDistance", "shortest", "shortest"]
//[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"]
//, ["makes", "coding"]]
//Output
//[null, 3, 1]
//
//Explanation
//WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", 
//"coding", "makes"]);
//wordDistance.shortest("coding", "practice"); // return 3
//wordDistance.shortest("makes", "coding");    // return 1
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
// At most 5000 calls will be made to shortest. 
// 
// Related Topics Hash Table Design 
// 👍 518 👎 156


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class WordDistance {
    unordered_map<string, vector<int>> mp;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); ++i) {
            mp[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i=0, j=0;
        auto &v1 = mp[word1], &v2 = mp[word2];
        int min_diff = INT_MAX;
        while(i < v1.size() && j < v2.size()) {
            min_diff = min(min_diff, abs(v1[i] - v2[j]));
            if(v1[i] > v2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return min_diff;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<string> v = {"a", "b","c","d","d"};
    WordDistance obj = WordDistance(v);
    obj.shortest("a", "d");
    return 0;
}