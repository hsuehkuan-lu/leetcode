//You are given the head of a linked list, and an integer k. 
//
// Return the head of the linked list after swapping the values of the kth node 
//from the beginning and the kth node from the end (the list is 1-indexed). 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5], k = 2
//Output: [1,4,3,2,5]
// 
//
// Example 2: 
//
// 
//Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
//Output: [7,9,6,6,8,7,3,0,9,5]
// 
//
// Example 3: 
//
// 
//Input: head = [1], k = 1
//Output: [1]
// 
//
// Example 4: 
//
// 
//Input: head = [1,2], k = 1
//Output: [2,1]
// 
//
// Example 5: 
//
// 
//Input: head = [1,2,3], k = 2
//Output: [1,2,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is n. 
// 1 <= k <= n <= 105 
// 0 <= Node.val <= 100 
// 
// Related Topics Linked List 
// 👍 323 👎 22


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
    ListNode *threePassSolution(ListNode *head, int k) {
        if(!head || !head->next) return head;
        ListNode *fast, *slow;
        fast = slow = head;
        int total = 0;
        while(fast) {
            slow = slow->next;
            if(fast->next) {
                fast = fast->next->next;
                total += 2;
            } else {
                fast = fast->next;
                ++total;
            }
        }
        if(total % 2 && k == (total >> 1) + 1) return head;
        --k;
        int first_k = k, second_k = total - k - 1;
        ListNode *first, *second;
        first = second = head;
        for(int i=0; i<first_k; ++i) first = first->next;
        for(int i=0; i<second_k; ++i) second = second->next;
        swap(first->val, second->val);
        return head;
    }
    ListNode *singlePassSolution(ListNode *head, int &k) {
        /*
         * The idea of single pass is that start node is n-th node,
         * while end node is (n-k)-th node.
         */
        ListNode *cur, *start, *end;
        int length = 0;
        cur = head;
        while(cur) {
            ++length;
            if(end) end = end->next;
            if(length == k) {
                start = cur;
                end = head;
            }
            cur = cur->next;
        }
        swap(start->val, end->val);
        return head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        return singlePassSolution(head, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(9);
    solution.swapNodes(head, 5);
    return 0;
}