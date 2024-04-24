#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 1e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
    #define JA "input"
    if(fopen(JA ".inp", "r")){
        freopen(JA ".inp","r",stdin);
        freopen(JA ".out","w",stdout);  
    }
}

vector<pair<int,int>> g[N];
bool check[N], used[N];
int n, m, s, k;
ll a[N], score = 0;
priority_queue<ii, vii, greater<ii>> pq;
bool ok = false;
int getNum(int x){
    map<int, bool> mp;
    int ans = 1;
    priority_queue<ii, vii, greater<ii>> pq;
    for(auto [v, w] : g[x]){
        if(mp[v] || check[v]) continue;
        pq.push({w, v});
    }
    mp[x] = 1;
    while(!pq.empty()){
        auto [w, u] = pq.top();pq.pop();
        if(mp[u]) continue;
        if(score >= w){
            mp[u] = 1;
            ans++;
            for(auto [v, val] : g[u]){
                if(mp[v] || check[v]) continue;
                pq.push({val, v});
            }
        }
        else break;
    }
    return ans;
}
void solve(){
    cin >> n >> m >> s >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }   

    pq.push({-1, s});
    while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        if(check[u]) continue;
        if(score >= w){
            check[u] = 1;
            if(!ok) score += a[u];
            for(auto [v, val] : g[u]){
                if(check[v]) continue;
                pq.push({val, v});
            }
        }
        else{
            pq.push({w, u});
            break;
        }       
    }
    int ans = 0, tmp = 0;
    for(int i=1;i<=n;i++) ans += check[i];
    if(k > 0){
        while(!pq.empty()){
            auto [w, u] = pq.top();pq.pop();
            if(used[u] || check[u]) continue;
            used[u] = 1;
            tmp = max(tmp, getNum(u));
        }
    }
    cout << ans + tmp;
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
