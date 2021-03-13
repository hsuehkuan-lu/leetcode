//A linked list of length n is given such that each node contains an additional 
//random pointer, which could point to any node in the list, or null. 
//
// Construct a deep copy of the list. The deep copy should consist of exactly n 
//brand new nodes, where each new node has its value set to the value of its corre
//sponding original node. Both the next and random pointer of the new nodes should
// point to new nodes in the copied list such that the pointers in the original li
//st and copied list represent the same list state. None of the pointers in the ne
//w list should point to nodes in the original list. 
//
// For example, if there are two nodes X and Y in the original list, where X.ran
//dom --> Y, then for the corresponding two nodes x and y in the copied list, x.ra
//ndom --> y. 
//
// Return the head of the copied linked list. 
//
// The linked list is represented in the input/output as a list of n nodes. Each
// node is represented as a pair of [val, random_index] where: 
//
// 
// val: an integer representing Node.val 
// random_index: the index of the node (range from 0 to n-1) that the random poi
//nter points to, or null if it does not point to any node. 
// 
//
// Your code will only be given the head of the original linked list. 
//
// 
// Example 1: 
//
// 
//Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// Example 2: 
//
// 
//Input: head = [[1,1],[2,1]]
//Output: [[1,1],[2,1]]
// 
//
// Example 3: 
//
// 
//
// 
//Input: head = [[3,null],[3,0],[3,null]]
//Output: [[3,null],[3,0],[3,null]]
// 
//
// Example 4: 
//
// 
//Input: head = []
//Output: []
//Explanation: The given linked list is empty (null pointer), so return null.
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 1000 
// -10000 <= Node.val <= 10000 
// Node.random is null or is pointing to some node in the linked list. 
// 
// Related Topics Hash Table Linked List 
// 👍 4844 👎 803


#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    int findIdx(Node *cur) {
        int idx = 0;
        while(cur) {
            ++idx;
            cur = cur->next;
        }
        return idx;
    }
    Node *iterationSolution(Node *head) {
        if(!head) return nullptr;
        unordered_map<int, Node*> mp;
        Node *new_head, *cur;
        new_head = cur = nullptr;
        while(head) {
            int idx = findIdx(head);
            // construct node first
            Node *new_node, *random_node;
            new_node = random_node = nullptr;
            if(mp.find(idx) != mp.end())
                new_node = mp[idx];
            else {
                new_node = new Node(head->val);
                mp[idx] = new_node;
            }
            // construct random node
            if(head->random) {
                int rand_idx = findIdx(head->random);
                if(mp.find(rand_idx) != mp.end())
                    random_node = mp[rand_idx];
                else {
                    random_node = new Node(head->random->val);
                    mp[rand_idx] = random_node;
                }
            }
            // assign back to cur
            if(!new_head) {
                cur = new_node;
                cur->random = random_node;
                new_head = cur;
            } else {
                cur->next = new_node;
                cur->next->random = random_node;
                cur = cur->next;
            }
            head = head->next;
        }
        return new_head;
    }
    Node *optimizeHashMapSolution(Node *head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node *new_head, *cur;
        new_head = cur = nullptr;
        while(head) {
            // construct node first
            Node *new_node, *random_node;
            new_node = random_node = nullptr;
            if(mp.find(head) != mp.end())
                new_node = mp[head];
            else {
                new_node = new Node(head->val);
                mp[head] = new_node;
            }
            // construct random node
            if(head->random) {
                if(mp.find(head->random) != mp.end())
                    random_node = mp[head->random];
                else {
                    random_node = new Node(head->random->val);
                    mp[head->random] = random_node;
                }
            }
            // assign back to cur
            if(!new_head) {
                cur = new_node;
                cur->random = random_node;
                new_head = cur;
            } else {
                cur->next = new_node;
                cur->next->random = random_node;
                cur = cur->next;
            }
            head = head->next;
        }
        return new_head;
    }
    Node *constantSpaceSolution(Node *head) {
        /*
         * O(1) space solution uses the idea of appending created nodes to original nodes:
         * e.g. A->B->C => A->A'->B->B'->C->C'
         * 1. Create a new node following original nodes (A'->A, B'->B, etc.).
         * 2. Iterate the list and find random nodes for generated nodes based on original random nodes.
         *  - A'->random = A->random->next, if A's random is B, then A->random->next will access to B'
         * 3. Split the original nodes with generated nodes, and make 2 lists.
         */
        if(!head) return nullptr;
        Node *new_head, *cur;
        // insert a new node after original node
        for(cur=head; cur; cur=cur->next->next) {
            Node *next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
        }
        // assign random nodes
        for(cur=head; cur; cur=cur->next->next) {
            Node *next = cur->next;
            if(cur->random) next->random = cur->random->next;
        }
        new_head = head->next;
        // split nodes
        for(cur=head; cur; cur=cur->next) {
            Node *next = cur->next;
            cur->next = next->next;
            if(next->next) next->next = next->next->next;
        }
        return new_head;
    }
    Node* copyRandomList(Node* head) {
//        return iterationSolution(head);
//        return optimizeHashMapSolution(head);
        return constantSpaceSolution(head);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution solution;
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->random = head;
    head->next->next = new Node(11);
    head->next->next->random = head->next;
    solution.copyRandomList(head);
    return 0;
}