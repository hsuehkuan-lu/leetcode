//We are given some website visits: the user with name username[i] visited the w
//ebsite website[i] at time timestamp[i]. 
//
// A 3-sequence is a list of websites of length 3 sorted in ascending order by t
//he time of their visits. (The websites in a 3-sequence are not necessarily disti
//nct.) 
//
// Find the 3-sequence visited by the largest number of users. If there is more 
//than one solution, return the lexicographically smallest such 3-sequence. 
//
// 
//
// Example 1: 
//
// 
//Input: username = ["joe","joe","joe","james","james","james","james","mary","m
//ary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","car
//eer","home","cart","maps","home","home","about","career"]
//Output: ["home","about","career"]
//Explanation: 
//The tuples in this example are:
//["joe", 1, "home"]
//["joe", 2, "about"]
//["joe", 3, "career"]
//["james", 4, "home"]
//["james", 5, "cart"]
//["james", 6, "maps"]
//["james", 7, "home"]
//["mary", 8, "home"]
//["mary", 9, "about"]
//["mary", 10, "career"]
//The 3-sequence ("home", "about", "career") was visited at least once by 2 user
//s.
//The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
//The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
//The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
//The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
// 
//
// 
//
// Note: 
//
// 
// 3 <= N = username.length = timestamp.length = website.length <= 50 
// 1 <= username[i].length <= 10 
// 0 <= timestamp[i] <= 10^9 
// 1 <= website[i].length <= 10 
// Both username[i] and website[i] contain only lowercase characters. 
// It is guaranteed that there is at least one user who visited at least 3 websi
//tes. 
// No user visits two websites at the same time. 
// 
// Related Topics Array Hash Table Sort 
// 👍 174 👎 1581


#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    unordered_map<string, map<int, string>> user2web;
    map<tuple<string, string, string>, int> visit;
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        for(int i=0; i<n; ++i) {
//            if(user2web.count(username[i])) {
//                auto &v = user2web[username[i]];
//                if(v.size() >= 2) {
//                    for(auto j=v.begin(); j!=v.end(); ++j) {
//                        auto k = j;
//                        advance(k, 1);
//                        for(; k!=v.end(); ++k) {
//                            ++visit[make_tuple(j->second, k->second, website[i])];
//                        }
//                    }
//                }
//            }
            user2web[username[i]][timestamp[i]] = website[i];
        }
        for(auto &u: user2web) {
            if(u.second.size() >= 3) {
                set<tuple<string, string, string>> s;
                auto &m = u.second;
                for(auto i=m.begin(); i!=m.end(); ++i) {
                    for(auto j=next(i); j!=m.end(); ++j) {
                        for(auto k=next(j); k!=m.end(); ++k) {
                            s.insert(make_tuple(i->second, j->second, k->second));

                        }
                    }
                }
                for(auto &elem: s) {
                    ++visit[elem];
                }
            }
        }
        int max_cnt = 0;
        vector<string> ans;
        for(auto &v: visit) {
            if(max_cnt < v.second) {
                ans.clear();
                ans.push_back(get<0>(v.first));
                ans.push_back(get<1>(v.first));
                ans.push_back(get<2>(v.first));
                max_cnt = v.second;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    vector<string> un = {"h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq"};
    vector<int> ts = {527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930};
    vector<string> wb = {"hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw"};
    solution.mostVisitedPattern(un, ts, wb);
    return 0;
}