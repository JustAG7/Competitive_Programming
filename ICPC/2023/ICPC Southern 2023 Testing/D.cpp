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
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define rev(i,start,n) for(int (i)=(start);(i)>=(n);(i--))
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';

const int N = 1e3+5;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

int vis[N][N];
int f[N][N];
int w,h,n;
bool check(int x,int y){
	return 1 <= x && x <= w && 1 <= y && y <= h;
}
int main(){
    fast;
    
    cin >> w >> h >> n;
    queue<ii> q;
    int ans = 0;
    rep(i,0,n){
        int u,v;
        cin >> u >> v;
        q.push({u,v});
        vis[u][v] = 1;
    }
    while(!q.empty()){
        auto [u,v] = q.front();q.pop();
        rep(i,0,4){
            int dx = u + moveX[i];
            int dy = v + moveY[i];
            if(check(dx,dy) && !vis[dx][dy]){
                vis[dx][dy] = 1;
                f[dx][dy] = f[u][v] + 1;
                q.push({dx,dy});
            }
        }
    }
    
    rep(i,0,w){
        rep(j,0,h){
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans;
}
