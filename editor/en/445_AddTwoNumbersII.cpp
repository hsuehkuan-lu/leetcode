//You are given two non-empty linked lists representing two non-negative integer
//s. The most significant digit comes first and each of their nodes contain a sing
//le digit. Add the two numbers and return it as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the nu
//mber 0 itself. 
//
// Follow up: 
//What if you cannot modify the input lists? In other words, reversing the lists
// is not allowed.
// 
//
// 
//Example:
// 
//Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 8 -> 0 -> 7
// 
// Related Topics Linked List 
// 👍 2265 👎 196


#include <iostream>
struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        for(auto cur=l1; cur; cur=cur->next) ++len1;
        for(auto cur=l2; cur; cur=cur->next) ++len2;
        if(len2 > len1) swap(l1, l2);
        auto head1 = l1, head2 = l2;
        for(int i=0; i<abs(len1-len2); ++i) head1 = head1->next;
        while(head1 && head2) {
            head1->val += head2->val;
            head1 = head1->next;
            head2 = head2->next;
        }
        // adjust carry
        bool is_done;
        ListNode *cur, *prev;
        do {
            is_done = true;
            cur = l1, prev = nullptr;
            while(cur) {
                if(cur->val >= 10) {
                    if(!prev) {
                        ListNode *new_head = new ListNode(cur->val / 10);
                        cur->val %= 10;
                        new_head->next = cur;
                        cur = new_head;
                        l1 = cur;
                    } else {
                        prev->val += cur->val / 10;
                        cur->val %= 10;
                    }
                }
                if(prev && prev->val >= 10) is_done = false;
                prev = cur;
                cur = cur->next;
            }
        } while(!is_done);
        return l1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    ListNode *l1 = new ListNode(1), *l2 = new ListNode(9);
//    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(4);
//    l1->next->next->next = new ListNode(3);
    l2->next = new ListNode(9);
//    l2->next->next = new ListNode(4);
    solution.addTwoNumbers(l1, l2);
    return 0;
}