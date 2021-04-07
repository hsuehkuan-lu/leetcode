//
// Created by 呂學寬 on 2021/3/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Data structure to store a max-heap node
struct PriorityQueue
{
private:
    // vector to store heap elements
    vector<int> heap;

    // return parent of `A[i]`
    // don't call this function if `i` is already a root node
    int PARENT(int i) {
        return (i-1) >> 1;
    }

    // return left child of `A[i]`
    int LEFT(int i) {
        return (i << 1) + 1;
    }

    // return right child of `A[i]`
    int RIGHT(int i) {
        return (i << 1) + 2;
    }

    // Recursive heapify-down algorithm.
    // The node at index `i` and its two direct children
    // violates the heap property
    void heapify_down(int i) {
        int max_idx = i;
        int left = LEFT(i), right = RIGHT(i);
        if(heap[max_idx] < heap[left] && left < size()) max_idx = left;
        if(heap[max_idx] < heap[right] && right < size()) max_idx = right;
        if(max_idx != i) {
            swap(heap[max_idx], heap[i]);
            heapify_down(max_idx);
        }
    }

    // Recursive heapify-up algorithm
    void heapify_up(int i)
    {
        if(!i) return;
        int parent = PARENT(i);
        if(heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            heapify_up(parent);
        }
    }

public:
    // return size of the heap
    unsigned int size() {
        return heap.size();
    }

    // Function to check if the heap is empty or not
    bool empty() {
        return size() == 0;
    }

    // insert key into the heap
    void push(int key) {
        heap.push_back(key);
        if(heap.size() > 1) {
            heapify_up(size() - 1);
        }
    }

    // Function to remove an element with the highest priority (present at the root)
    void pop() {
        if(empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    // Function to return an element with the highest priority (present at the root)
    int top() {
        if(empty()) return -1;
        return heap.front();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(1);
    pq.push(100);
    pq.push(80);
    pq.push(125);
    pq.top();
    pq.pop();
    pq.top();
    pq.pop();
    pq.top();
    return 0;
}