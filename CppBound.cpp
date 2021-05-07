//
// Created by 呂學寬 on 2021/5/7.
//

#include <vector>

using namespace std;

int lower_bound(vector<int> &v, int num) {
    int low = 0, high = v.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(v[mid] >= num) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int upper_bound(vector<int> &v, int num) {
    int low = 0, high = v.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(v[mid] > num) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}


int main() {
    vector<int> v = {1,3,5,7,9};
    upper_bound(v, 7);
    return 0;
}
