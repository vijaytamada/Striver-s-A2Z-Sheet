/*
    ============================================================
    TOPIC   : STL - Standard Template Library
    CONCEPT : vector (Dynamic Array)
    ============================================================

    WHAT & WHY:
    ----------
    - vector is a resizable array - grows automatically as you push
      elements, unlike a fixed-size C array. It's the default go-to
      container for most DSA problems.

    KEY POINTS:
    ----------
    1. push_back() -> O(1) amortized (occasionally O(n) when it needs to
       resize/reallocate internally).
    2. Random access via [] or .at() -> O(1). .at() also bounds-checks
       (throws) while [] does not.
    3. insert()/erase() in the middle -> O(n) because elements must shift.
    4. Many construction styles: default, size+fill value, initializer
       list, copy constructor (deep copy - modifying one doesn't affect
       the other), assign(), from a raw array, or from another container's
       iterators.
    5. size() = number of elements currently stored; capacity() = how much
       space is allocated before the next resize is needed.

    COMMON PITFALLS / GOTCHAS:
    ----------
    - Copying a vector (v5 = v4) makes a full independent copy - changing
      v4 afterwards does NOT affect v5.
    - Using [] out of bounds is undefined behavior (no exception, may
      crash or corrupt memory) - use .at() when safety matters more than
      speed.
    - erase(begin()) shifts every remaining element - O(n), avoid in a
      loop if you need many removals.
    ============================================================
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    // 1. Empty vector
    vector<int> v1;
    cout << "v1 (empty): size = " << v1.size() << endl;

    // 2. Fixed size with default value
    vector<int> v2(5);       // 5 elements initialized to 0
    vector<int> v3(5, 100);  // 5 elements initialized to 100

    // 3. Initializer list
    vector<int> v4 = {1, 2, 3, 4, 5};

    // 4. Copy constructor
    vector<int> v5 = v4;

    v4[0] = 100;
    cout << "After modifying v4[0] to 100: " << v5[0] << " (v5 remains unchanged)" << endl;

    // 5. assign() method
    vector<int> v6;
    v6.assign(4, 99);

    // 6. From array
    int arr[] = {10, 20, 30};
    vector<int> v7(arr, arr + 3);

    // 7. From another container (list)
    list<int> lst = {7, 8, 9};
    vector<int> v8(lst.begin(), lst.end());

    // Display all initialized vectors
    cout << "\nInitialized vectors:\n";
    cout << "v2: ";
    for (int x : v2)
        cout << x << " ";
    cout << "\nv3: ";
    for (int x : v3)
        cout << x << " ";
    cout << "\nv4: ";
    for (int x : v4)
        cout << x << " ";
    cout << "\nv5 (copy of v4): ";
    for (int x : v5)
        cout << x << " ";
    cout << "\nv6 (assigned): ";
    for (int x : v6)
        cout << x << " ";
    cout << "\nv7 (from array): ";
    for (int x : v7)
        cout << x << " ";
    cout << "\nv8 (from list): ";
    for (int x : v8)
        cout << x << " ";
    cout << endl;

    // --- Original operations ---
    vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    cout << "\nVector operations:\n";
    cout << "Original: ";
    for (int num : numbers)
        cout << num << " ";
    cout << "\nFirst element: " << numbers[0];
    cout << "\nSecond element: " << numbers.at(1);

    // Insert 15 at index 1
    numbers.insert(numbers.begin() + 1, 15);
    cout << "\nAfter insertion: ";
    for (int num : numbers)
        cout << num << " ";

    numbers.pop_back();
    cout << "\nAfter pop_back: ";
    for (int num : numbers)
        cout << num << " ";

    cout << "\nSize: " << numbers.size();
    cout << "\nCapacity: " << numbers.capacity() << endl;

    // Sort the vector
    sort(numbers.begin(), numbers.end());
    cout << "After sorting: ";
    for (int num : numbers)
        cout << num << " ";
    cout << endl;

    // Reverse sorting
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "After reverse sorting: ";
    for (int num : numbers)
        cout << num << " ";

    numbers.erase(numbers.begin());  // Remove first element

    // remove nth element

    return 0;
}