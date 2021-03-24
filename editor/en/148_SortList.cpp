//Given the head of a linked list, return the list after sorting it in ascending
// order. 
//
// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.
//e. constant space)? 
//
// 
// Example 1: 
//
// 
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
// 
//
// Example 2: 
//
// 
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
// 
//
// Example 3: 
//
// 
//Input: head = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 5 * 104]. 
// -105 <= Node.val <= 105 
// 
// Related Topics Linked List Sort 
// 👍 4002 👎 171


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
    void quickSortSolution(ListNode *left, ListNode *right) {
        /*
         * Having trouble with pointer reference!
         */
        if(!left || !right || left == right) return;
        ListNode *pivot = left;
    }
    ListNode *merge(ListNode *left_head, ListNode *right_head) {
        if(!left_head) return right_head;
        if(!right_head) return left_head;
        ListNode *head, *cur;
        if(left_head->val < right_head->val) {
            head = new ListNode(left_head->val);
            left_head = left_head->next;
        } else {
            head = new ListNode(right_head->val);
            right_head = right_head->next;
        }
        cur = head;
        while(left_head || right_head) {
            if(!left_head) {
                cur->next = new ListNode(right_head->val);
                right_head = right_head->next;
            }
            else if(!right_head) {
                cur->next = new ListNode(left_head->val);
                left_head = left_head->next;
            } else {
                if(left_head->val < right_head->val) {
                    cur->next = new ListNode(left_head->val);
                    left_head = left_head->next;
                } else {
                    cur->next = new ListNode(right_head->val);
                    right_head = right_head->next;
                }
            }
            cur = cur->next;
        }
        return head;
    }
    ListNode *mergeSortSolution(ListNode *left, ListNode *right) {
        if(!left || !right) return nullptr;
        if(left == right) return new ListNode(left->val);
        ListNode *mid = left, *fast = left;
        int cnt = 1;
        while(fast != right) {
            if(cnt % 2 == 0) mid = mid->next;
            fast = fast->next;
            ++cnt;
        }
        return merge(mergeSortSolution(left, mid), mergeSortSolution(mid->next, right));
    }
    ListNode *findMid(ListNode *head) {
        ListNode *mid, *fast;
        mid = head;
        fast = head->next->next;
        while(fast) {
            mid = mid->next;
            if(fast->next) fast = fast->next->next;
            else fast = fast->next;
        }
        return mid;
    }
    ListNode *optimizeMerge(ListNode *head_a, ListNode *head_b) {
        ListNode *head = new ListNode(), *cur = head;
        while(head_a || head_b) {
            if(!head_a) {
                cur->next = head_b;
                head_b = head_b->next;
                cur = cur->next;
            }
            else if(!head_b) {
                cur->next = head_a;
                head_a = head_a->next;
                cur = cur->next;
            } else {
                if(head_a->val < head_b->val) {
                    cur->next = head_a;
                    cur = cur->next;
                    head_a = head_a->next;
                } else {
                    cur->next = head_b;
                    cur = cur->next;
                    head_b = head_b->next;
                }
            }
        }
        return head->next;
    }
    ListNode *optimizeMergeSortSolution(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *mid = findMid(head), *prev = mid;
        mid = mid->next;
        prev->next = nullptr;
        return optimizeMerge(optimizeMergeSortSolution(head), optimizeMergeSortSolution(mid));
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        return optimizeMergeSortSolution(head);
//        quickSortSolution(head, end);
//        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    solution.sortList(head);
    return 0;
}