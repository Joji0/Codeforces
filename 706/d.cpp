#include <bits/stdc++.h>
using namespace std;

struct BitTrie {
    struct Node {
        int nxt[2];
        int pass, end;
        Node() {
            nxt[0] = nxt[1] = -1;
            pass = 0;
            end = 0;
        }
    };
    vector<Node> t;
    int B;
    BitTrie(int B = 31) : B(B) {
        t.reserve(1 << 20);
        t.push_back(Node());
    }
    void insert(int x) {
        int v = 0;
        t[v].pass++;
        for (int i = B; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (t[v].nxt[b] == -1) {
                t[v].nxt[b] = (int)t.size();
                t.push_back(Node());
            }
            v = t[v].nxt[b];
            t[v].pass++;
        }
        t[v].end++;
    }
    bool erase(int x) {
        if (!count(x))
            return false;
        int v = 0;
        t[v].pass--;
        for (int i = B; i >= 0; i--) {
            int b = (x >> i) & 1;
            v = t[v].nxt[b];
            t[v].pass--;
        }
        t[v].end--;
        return true;
    }
    int count(int x) const {
        int v = 0;
        for (int i = B; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (t[v].nxt[b] == -1)
                return 0;
            v = t[v].nxt[b];
        }
        return t[v].end;
    }
    bool exists(int x) const { return count(x) > 0; }
    int countPrefixBits(int x, int k) const {
        int v = 0;
        for (int i = B; i > B - k; i--) {
            int b = (x >> i) & 1;
            if (t[v].nxt[b] == -1)
                return 0;
            v = t[v].nxt[b];
        }
        return t[v].pass;
    }
    int countSubtree(int v) const {
        int res = t[v].end;
        for (int b = 0; b < 2; b++) {
            int u = t[v].nxt[b];
            if (u != -1)
                res += countSubtree(u);
        }
        return res;
    }
    int goPrefix(int x, int k) const {
        int v = 0;
        for (int i = B; i > B - k; i--) {
            int b = (x >> i) & 1;
            if (t[v].nxt[b] == -1)
                return -1;
            v = t[v].nxt[b];
        }
        return v;
    }
    bool erasePrefixBits(int x, int k) {
        int v = 0;
        vector<int> path = {0};
        for (int i = B; i > B - k; i--) {
            int b = (x >> i) & 1;
            if (t[v].nxt[b] == -1)
                return false;
            v = t[v].nxt[b];
            path.push_back(v);
        }
        int total = countSubtree(v);
        if (total == 0)
            return false;
        for (int node : path)
            t[node].pass -= total;
        queue<int> q;
        q.push(v);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            t[x].pass = 0;
            t[x].end = 0;
            for (int b = 0; b < 2; b++) {
                int u = t[x].nxt[b];
                if (u != -1)
                    q.push(u);
                t[x].nxt[b] = -1;
            }
        }
        return true;
    }
    int maxXor(int x) const {
        int v = 0, ans = 0;
        for (int i = B; i >= 0; i--) {
            int b = (x >> i) & 1;
            int want = b ^ 1;
            if (t[v].nxt[want] != -1 && t[t[v].nxt[want]].pass > 0) {
                ans |= (1 << i);
                v = t[v].nxt[want];
            } else {
                v = t[v].nxt[b];
            }
        }
        return ans;
    }
    int minXor(int x) const {
        int v = 0, ans = 0;
        for (int i = B; i >= 0; i--) {
            int b = (x >> i) & 1;
            int want = b;
            if (t[v].nxt[want] != -1 && t[t[v].nxt[want]].pass > 0) {
                v = t[v].nxt[want];
            } else {
                ans |= (1 << i);
                v = t[v].nxt[want ^ 1];
            }
        }
        return ans;
    }
    void eraseAll() {
        t.clear();
        t.reserve(1 << 20);
        t.push_back(Node());
    }
};

void solve() {
    int q;
    cin >> q;
    BitTrie trie(31);
    trie.insert(0);
    while (q--) {
        char t;
        int x;
        cin >> t >> x;
        if (t == '+') {
            trie.insert(x);
        } else if (t == '-') {
            trie.erase(x);
        } else {
            cout << trie.maxXor(x) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
