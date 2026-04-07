#include <bits/stdc++.h>

using namespace std;
#define ll long long

// Monotonic Stack

// Time Complexity: O(N)
// Space Complexity: O(N)
// Rule of thumb: Always store INDICES in the stack, not the values themselves!

// Example 1: Next Greater Element (NGE)
// Returns an array where ans[i] is the index of the first 
// element to the right of i that is strictly greater than arr[i].
// (Returns -1 if no such element exists).

vector<int> next_greater_element(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // While the current element is GREATER than the element at the stack's top
        // it means the current element is the NGE for the stack's top!
        while (!st.empty() && arr[i] > arr[st.top()]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i); // Push current index to find its NGE later
    }
    return nge;
}

// ---------------------------------------------------------
// Example 2: Largest Rectangle in Histogram (Maximum Area)
// Finds the maximum rectangular area that can be formed within a histogram.
// Uses an INCREASING Monotonic Stack to find the Next Smaller Element on both sides.
// ---------------------------------------------------------
long long max_area_histogram(const vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    ll max_area = 0;

    // We iterate up to 'n' (inclusive) to act as a dummy bar of height 0 at the end.
    // This forces the stack to empty out and calculate areas for all remaining bars.
    for (int i = 0; i <= n; i++) {
        int curr_height = (i == n) ? 0 : heights[i];

        // If we find a smaller bar, it acts as the RIGHT boundary for the bar at stack top
        while (!st.empty() && heights[st.top()] > curr_height) {
            ll h = heights[st.top()]; st.pop();
            
            // If stack is empty, it means no smaller bar exists to the LEFT.
            // Otherwise, the new stack top is the LEFT boundary.
            ll w = st.empty() ? i : (i - st.top() - 1);
            
            max_area = max(max_area, h * w);
        }
        st.push(i);
    }
    
    return max_area;
}