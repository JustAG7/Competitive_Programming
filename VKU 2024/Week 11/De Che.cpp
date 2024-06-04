#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define dbgArr(a, index) for (int i = 0; i < (index); i++) cerr << a[i] << ' ';
#define dbgMat(a, n, m) for (int i = 0; i < (n); i++) {for (int j = 0; j < (m); j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";

const int M = 1e9 + 7;
const int N = 5e5 + 5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
    #define JA "input"
    if (fopen(JA ".inp", "r")) {
        freopen(JA ".inp", "r", stdin);
        freopen(JA ".out", "w", stdout);  
    }
}

struct Segment{
    int l, r, type, idx;
    bool operator < (const Segment &other) const {
        if(l != other.l) return l < other.l;
        if(type != other.type) return type > other.type;
        return r < other.r;
    }
    Segment(int _l, int _r,int _type, int _idx){
        l = _l;
        r = _r;
        type = _type;
        idx = _idx;
    }
};
int a[N], res[N];
int n, q;
int bit[N], answers[N];
vector<Segment> query;
void update(int u, int val) {
    for (; u <= n; u += u & -u) {
        bit[u] += val;
    }
}

int get(int u) {
    int ans = 0;
    for (; u > 0; u -= u & -u) {
        ans += bit[u];
    }
    return ans;
}

void process(){
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty()) {
            int idx = s.top();
            if(a[idx] > a[i]){
                res[i] = idx;
                break;
            }
            else s.pop();
        }
        s.push(i);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    process();  
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        query.pb(Segment(l, r, 0, i));
    }
    for(int i=1;i<=n;i++){
        query.pb(Segment(res[i] + 1, i, 1, -1));
    }
    sort(all(query));
    for (int i = 0; i < q + n; i++) {

        if(query[i].type == 1){
            update(query[i].r, 1);
        }
        else{
            answers[query[i].idx] = get(query[i].r) - get(query[i].l - 1);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << answers[i] << nl;
    }
}

int main() {
    fast;
    indef();
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
