#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int nmax = (int)1e5 + 7;
const int mod = (int)1e9 + 7;

struct Node{
    int val, hi;
    Node *L, *R;
    Node* par;

    Node() {
        val = 0;
        hi = 0;
        L = nullptr;
        R = nullptr;
        par = nullptr;
    }
};

Node *root;
Node* push_node(int val) {
    Node *p = root;
    while(true) {
        if(val < p -> val) {
            if(p -> L == nullptr) {
                p -> L = new Node();
                p -> L -> val = val;
                p -> L -> par = p;
                p -> L -> hi = p -> hi + 1;
                return p -> L;
                break;
            }
            else p = p->L;
        }
        else {
            if(p -> R == nullptr) {
                p -> R = new Node();
                p -> R -> val = val;
                p -> R -> par = p;
                p -> R -> hi = p -> hi + 1;
                return p -> R;
                break;
            }
            else p = p -> R;
        }
    }
}
vector<int> c;
Node *na, *nb;
int a, b;
int n;

void lca() {
    int r_min = INT_MAX;
    int r_max = INT_MIN;

    r_min = min(r_min, na -> val);
    r_min = min(r_min, nb -> val);
    r_max = max(r_max, na -> val);
    r_max = max(r_max, nb -> val);

    while(na -> val != nb -> val) {
        cerr << na -> val << " " << nb -> val << '\n';
        if(na -> hi > nb -> hi) {
            na = na -> par;
        }
        else if (nb -> hi > na -> hi) {
            nb = nb -> par;
        }
        else {
            na = na -> par;
            nb = nb -> par;
        }
        r_min = min(r_min, na -> val);
        r_min = min(r_min, nb -> val);
        r_max = max(r_max, na -> val);
        r_max = max(r_max, nb -> val);
    }
    cout << r_min << " " << r_max;
}

void ip() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int ci; cin >> ci;
        c.push_back(ci);
    }
    cin >> a >> b;
    for(int i = 0; i < n; ++i) {
        int ci = c[i];
        if(i == 0) {
            root = new Node();
            root -> val = ci;
            root -> hi = 0;
            if(a == ci)na = root;
            if(b == ci)nb = root;
        }
        else {
            if(ci == a)na = push_node(ci);
            else if(ci == b)nb = push_node(ci);
            else push_node(ci);
        }
    }
    if(a == b) {
        cout << a << " " << b;
    }
    else {
        lca();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    if(fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
    int tt = 1;
//    cin >> tt;
    while(tt--) {
        ip();
//        cout << '\n';
    }
}