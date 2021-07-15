//In an alien language, surprisingly they also use english lowercase letters, bu
//t possibly in a different order. The order of the alphabet is some permutation o
//f lowercase letters. 
//
// Given a sequence of words written in the alien language, and the order of the
// alphabet, return true if and only if the given words are sorted lexicographical
//y in this alien language. 
// 
// Example 1: 
//
// 
//Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
//Output: true
//Explanation: As 'h' comes before 'l' in this language, then the sequence is so
//rted.
// 
//
// Example 2: 
//
// 
//Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
//Output: false
//Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1]
//, hence the sequence is unsorted.
// 
//
// Example 3: 
//
// 
//Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
//Output: false
//Explanation: The first three characters "app" match, and the second string is 
//shorter (in size.) According to lexicographical rules "apple" > "app", because '
//l' > '∅', where '∅' is defined as the blank character which is less than any oth
//er character (More info).
// 
//
// 
// Constraints: 
//
// 
// 1 <= words.length <= 100 
// 1 <= words[i].length <= 20 
// order.length == 26 
// All characters in words[i] and order are English lowercase letters. 
// 
// Related Topics Hash Table 
// 👍 1387 👎 588


#include <iostream>
#include <vector>
#include <string>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool comp(string &a, string &b, int arr[]) {
        for(int i=0; i<a.size(); ++i) {
            if(i >= b.size() || arr[a[i] - 'a'] > arr[b[i] - 'a']) return false;
            else if(arr[a[i] - 'a'] < arr[b[i] - 'a']) break;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[26] = {0};
        for(int i=0; i<order.size(); ++i) {
            arr[order[i] - 'a'] = i;
        }
        for(int i=0; i<words.size()-1; ++i) {
            if(!comp(words[i], words[i+1], arr)) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> words = {"kuvp", "q"};
    cout << solution.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz");
    return 0;
}