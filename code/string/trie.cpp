#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// Trie (Prefix Tree)

// A tree data structure used for efficiently storing and retrieving strings.
// Supports counting prefixes, exact matches, and erasing strings.

// 0-indexed internally for nodes (root is 0).
// Time Complexity: O(L) for Insert, Search, and Erase (where L is string length).
// Space Complexity: O(N * ALPHA) where N is the total length of all strings.

const int ALPHA = 26;
const char NORM = 'a';

struct Node {
    int nxt[ALPHA];
    int pref, end;

    Node() : pref(0), end(0) { memset(nxt, 0, sizeof(nxt)); }
};

struct Trie {
    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    void insert(string &s) {
        int curr = 0;
        nodes[curr].pref++;

        for (char &c : s) {
            int idx = c - NORM;
            
            if (!nodes[curr].nxt[idx]) {
                nodes[curr].nxt[idx] = (int)nodes.size();
                nodes.emplace_back();
            }
            
            curr = nodes[curr].nxt[idx];
            nodes[curr].pref++;
        }
        
        nodes[curr].end++;
    }

    int find(string &s) {
        int curr = 0;
        for (char &c : s) {
            int idx = c - NORM;
            if (!nodes[curr].nxt[idx]) return -1;
            curr = nodes[curr].nxt[idx];
        }
        return curr;
    }

    int count_end(string &s) {
        int idx = find(s);
        return idx != -1 ? nodes[idx].end : 0;
    }

    int count_pref(string &s) {
        int idx = find(s);
        return idx != -1 ? nodes[idx].pref : 0;
    }

    void erase(string &s) {
        if (count_end(s) == 0) return; // Só remove se realmente existir

        int curr = 0;
        nodes[curr].pref--;
        
        for (char &c : s) {
            int idx = c - NORM;
            curr = nodes[curr].nxt[idx];
            nodes[curr].pref--;
        }
        
        nodes[curr].end--;
    }
};