#include <bits/stdc++.h>

using namespace std;

// MinQueue

// - push(x): Adds element to Queue.
// - pop(): Removes element from queue. (removes oldest element).
// - min(): Returns minimum Queue.

// O(1) amortized per operation.

template<typename T>
struct MinQueue : deque<pair<T, int>> {
    T min() { return this->front().first; }

    void push(int x) {
        int cnt = 1;
        while (!this->empty() and x <= this->front().first) {
            cnt += this->back().second;
            this->pop_back();
        }
        this->push_back({x, cnt});
    }

    void pop() {
        if (!--this->front().second) this->pop_front();
    }
};