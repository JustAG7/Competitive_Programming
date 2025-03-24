#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int nmax = (int)1e5 + 7;
const int mod = (int)1e9 + 7;

int n, r, q;
double p;
vector<pair<int, int>> a;

void ip() {
    cin >> n >> r >> q >> p;
    int cur_time = 0;
    int res = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0; i < r; ++i) {
        int si, ti; cin >> si >> ti;
        if(cur_time > si)continue;
        if(si > cur_time)cur_time = si;
        while(pq.size() && pq.top() <= cur_time){
            q += 1;
            pq.pop();
        }
        if(q > 0) {
            q -= 1;
            res += 1;
            pq.push(ti);
        }
    }
    double pr = 1.0 * res / (r * 1.0);
    pr *= 100.0;
    pr = 100.0 - pr;
//    cout << pr << '\n';
    cout << res << "/" << r << ":" << (pr > p ? " Yes" : " No");
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