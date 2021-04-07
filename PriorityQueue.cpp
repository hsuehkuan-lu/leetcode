//
// Created by 呂學寬 on 2021/4/7.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class PriorityQueue {
public:
    struct maxHeap {
        bool operator() (const int &a, const int &b) const {
            return a < b;
        }
    };
    struct minHeap {
        bool operator() (const int &a, const int &b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, minHeap> p;
};

int main() {
    PriorityQueue heap;
    auto p = heap.p;
    p.push(5);
    p.push(2);
    p.push(4);
    while(!p.empty()) {
        cout << p.top() << endl;
        p.pop();
    }
    vector<int> nums = {5,67,2,1,7};
    sort(nums.begin(), nums.end(), [](const int &a, const int &b){
        return a > b;
    });
    return 0;
}
