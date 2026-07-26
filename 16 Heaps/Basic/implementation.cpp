/*
    ============================================================
    TOPIC   : Heaps - Basic
    PROBLEM : Implement MinHeap and MaxHeap from scratch (array-based)
    ============================================================

    INTUITION:
    ----------
    - A heap is stored as an array; for node at index i:
      parent = (i-1)/2, left = 2i+1, right = 2i+2.
    - insert(): push value at the end, then "bubble up" (swap with
      parent while it violates heap order) — this is sift-up.
    - extract_min/max(): swap root with last element, pop the last,
      then "bubble down" from root (heapify) — this is sift-down.
    - decrease_key/increase_key(): update a value in place, then
      bubble it up since it may now violate the parent relationship.
    - delete_at(i): push the value to an extreme (-inf/+inf) so it
      naturally bubbles to the root, then extract it.

    STEPS (MinHeap, MaxHeap mirrors it with flipped comparisons):
    ----------
    1. insert(val): push_back, then swap with parent while parent > val.
    2. heapify(i): recursively swap node i with its smaller child
       until heap property holds (used by extract_min).
    3. extract_min(): move last element to root, pop_back, heapify(0).
    4. decrease_key(i, val): set value, bubble up.
    5. delete_at(i): decrease_key to INT_MIN, then extract_min.

    VARIATIONS TO REMEMBER:
    ----------
    - std::priority_queue in C++ already does all this internally
      (max-heap by default; pass greater<int> for min-heap).
    - Same insert/heapify pattern is reused in Heap Sort, Kth
      largest/smallest, and Merge K Sorted Lists.

    TIME COMPLEXITY  : insert/decrease_key O(log n), extract O(log n),
                        heapify O(log n) -> height of the tree
    SPACE COMPLEXITY : O(n) -> array storing heap elements
    ============================================================
*/
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;
    int capacity;

    // Returns the index of the parent of node i
    int parent(int i) const {
        return (i - 1) / 2;
    }

    // Returns the index of the left child of node i
    int left(int i) const {
        return 2 * i + 1;
    }

    // Returns the index of the right child of node i
    int right(int i) const {
        return 2 * i + 2;
    }

    // Restores the min-heap property starting from index i downward
    void heapify(int i) {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    // Constructor: initializes heap with given capacity
    MinHeap(int cap) {
        this->capacity = cap;
    }

    // Inserts a new value into the heap and maintains min-heap property
    void insert(int val) {
        if (heap.size() == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        heap.push_back(val);
        int i = heap.size() - 1;

        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Returns the minimum element (root of the heap)
    int get_min() const {
        return heap.empty() ? INT_MAX : heap[0];
    }

    // Removes and returns the minimum element, then restores heap order
    int extract_min() {
        if (heap.empty())
            return INT_MAX;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapify(0);
        return root;
    }

    // Decreases the value at index i to val and restores heap order
    void decrease_key(int i, int val) {
        if (i < 0 || i >= heap.size())
            return;

        heap[i] = val;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Deletes the element at index i by reducing it to INT_MIN and extracting it
    void delete_at(int i) {
        if (i < 0 || i >= heap.size())
            return;

        decrease_key(i, INT_MIN);
        extract_min();
    }

    // Prints the current heap contents in array order
    void print() const {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

class MaxHeap {
    vector<int> heap;
    int capacity;

    // Returns the index of the parent of node i
    int parent(int i) const {
        return (i - 1) / 2;
    }

    // Returns the index of the left child of node i
    int left(int i) const {
        return 2 * i + 1;
    }

    // Returns the index of the right child of node i
    int right(int i) const {
        return 2 * i + 2;
    }

    // Restores the min-heap property starting from index i downward
    void heapify(int i) {
        int largest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Constructor: initializes heap with given capacity
    MaxHeap(int cap) {
        this->capacity = cap;
    }

    // Inserts a new value into the heap and maintains max-heap property
    void insert(int val) {
        if (heap.size() == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        heap.push_back(val);
        int i = heap.size() - 1;

        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Returns the maximum element (root of the heap)
    int get_max() const {
        return heap.empty() ? INT_MIN : heap[0];
    }

    // Removes and returns the maximum element, then restores heap order
    int extract_max() {
        if (heap.empty())
            return INT_MIN;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapify(0);

        return root;
    }

    // Decreases the value at index i to val and restores heap order
    void increase_key(int i, int val) {
        if (i < 0 || i >= heap.size())
            return;

        heap[i] = val;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Deletes the element at index i by increasing it to INT_MAX and extracting it
    void delete_at(int i) {
        if (i < 0 || i >= heap.size())
            return;

        increase_key(i, INT_MAX);
        extract_max();
    }

    // Prints the current heap contents in array order
    void print() const {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h(20);
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);

    cout << "Min value is " << h.get_min() << endl;

    h.insert(-1);
    cout << "Min value is " << h.get_min() << endl;

    h.decrease_key(3, -2);
    cout << "Min value is " << h.get_min() << endl;

    h.extract_min();
    cout << "Min value is " << h.get_min() << endl;

    h.delete_at(0);
    cout << "Min value is " << h.get_min() << endl;

    MaxHeap mh(20);
    mh.insert(4);
    mh.insert(1);
    mh.insert(2);
    mh.insert(6);
    mh.insert(7);
    mh.insert(3);
    mh.insert(8);
    mh.insert(5);

    cout << "Max value is " << mh.get_max() << endl;

    mh.insert(10);
    cout << "Max value is " << mh.get_max() << endl;

    mh.increase_key(3, 12);
    cout << "Max value is " << mh.get_max() << endl;

    mh.extract_max();
    cout << "Max value is " << mh.get_max() << endl;

    mh.delete_at(0);
    cout << "Max value is " << mh.get_max() << endl;

    return 0;
}
