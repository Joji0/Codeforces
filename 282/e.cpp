#include <bits/stdc++.h>
using namespace std;

#define int int64_t

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
                ans |= (1LL << i);
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
                ans |= (1LL << i);
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
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    vector<int64_t> pref(n), suff(n);
    pref[0] = A[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] ^ A[i];
    }
    suff[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] ^ A[i];
    }
    BitTrie Trie(41);
    for (int i = 0; i < n; i++) {
        Trie.insert(suff[i]);
    }
    cerr << "DEBUG\n";
    for (int i = 0; i < n; i++) {
        cerr << pref[i] << " ";
    }
    cerr << '\n';
    cerr << "DEBUG\n";
    for (int i = 0; i < n; i++) {
        cerr << suff[i] << " ";
    }
    cerr << '\n';
    int64_t ans = 0;
    Trie.insert(0);
    for (int i = 0; i < n; i++) {
        Trie.erase(suff[i]);
        ans = max(ans, Trie.maxXor(pref[i]));
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, pref[i]);
        ans = max(ans, suff[i]);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
