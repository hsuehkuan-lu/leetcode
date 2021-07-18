//Given a linked list, reverse the nodes of a linked list k at a time and return
// its modified list. 
//
// k is a positive integer and is less than or equal to the length of the linked
// list. If the number of nodes is not a multiple of k then left-out nodes, in the
// end, should remain as it is. 
//
// You may not alter the values in the list's nodes, only nodes themselves may b
//e changed. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], k = 2
//Output: [2,1,4,3,5]
// 
//
// Example 2: 
//
// 
//Input: head = [1,2,3,4,5], k = 3
//Output: [3,2,1,4,5]
// 
//
// Example 3: 
//
// 
//Input: head = [1,2,3,4,5], k = 1
//Output: [1,2,3,4,5]
// 
//
// Example 4: 
//
// 
//Input: head = [1], k = 1
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range sz. 
// 1 <= sz <= 5000 
// 0 <= Node.val <= 1000 
// 1 <= k <= sz 
// 
//
// 
//Follow-up: Can you solve the problem in O(1) extra memory space? Related Topic
//s Linked List Recursion 
// 👍 4298 👎 420
	

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *subReverse(ListNode *prev, ListNode *tail, ListNode *head) {
        ListNode *next_list = head->next;
        ListNode *cur = tail->next;
        head->next = tail;
        tail->next = nullptr;
        while(cur != head) {
            ListNode *tmp = head->next, *next_cur = cur->next;
            head->next = cur;
            cur->next = tmp;
            cur = next_cur;
        }
        if(prev) prev->next = head;
        tail->next = next_list;
        return tail;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode *start = head;
        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *ans = nullptr;
        int cnt = 0;
        while(cur) {
            ++cnt;
            if(cnt % k == 0) {
                if(!ans) ans = cur;
                cur = subReverse(prev, start, cur);
                prev = cur;
                start = cur->next;
            }
            cur = cur->next;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    solution.reverseKGroup(head, 3);
    return 0;
}