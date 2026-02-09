#include <vector>
#include <string>
#include <cstring>

using namespace std;

// ==========================================
// Trie (Prefix Tree)
// ==========================================
// - Insert: O(L * Alpha) where L is string length
// - Search: O(L)
// - Remove: O(L)

struct Node {
    vector<int> nxt;
    int cnt_pref;
    int cnt_end; 

    Node(int alpha = 26) : nxt(alpha, 0), cnt_pref(0), cnt_end(0) {}
};

struct Trie {
    vector<Node> tr;
    const char NORM = 'a';

    Trie() {
        tr.emplace_back(); // Root node at index 0
    }

    void insert(const string &s) {
        int curr = 0;
        tr[curr].cnt_pref++; // Update root prefix count

        for (char c : s) {
            int idx = c - NORM;
            
            if (!tr[curr].nxt[idx]) {
                tr[curr].nxt[idx] = (int)tr.size();
                tr.emplace_back();
            }
            
            curr = tr[curr].nxt[idx];
            tr[curr].cnt_pref++;
        }
        
        tr[curr].cnt_end++;
    }

    // Counts words exactly equal to s
    int count_exact(const string &s) {
        int idx = find_node(s);
        return idx != -1 ? tr[idx].cnt_end : 0;
    }

    // Counts words that have s as a prefix
    int count_prefix(const string &s) {
        int idx = find_node(s);
        return idx != -1 ? tr[idx].cnt_pref : 0;
    }

    // Doesn't actually delete nodes to keep indices valid.
    void remove(const string &s) {
        if (count_exact(s) == 0) return;

        int curr = 0;
        tr[curr].cnt_pref--;
        
        for (char c : s) {
            int idx = c - NORM;
            curr = tr[curr].nxt[idx];
            tr[curr].cnt_pref--;
        }
        
        tr[curr].cnt_end--;
    }

    int find_node(const string &s) {
        int curr = 0;
        for (char c : s) {
            int idx = c - NORM;
            if (!tr[curr].nxt[idx]) return -1;
            curr = tr[curr].nxt[idx];
        }
        return curr;
    }
};