#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>

const int N = 1e3+5;
const int M = 1e9+7;
char mat[N][N];
int d1[N][N];
int vis[N][N];
int n,m;
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

pair<int,int> start,finish;
queue<pair<int,int>> q;
int f[N][N];


bool check(int x,int y){
    return 1<=x && x<=n && 1<=y && y<=m;
}


void bfs(){
    priority_queue<pair<int,ii>> pq;
    memset(f,M,sizeof(f));
    f[start.first][start.second] = d1[start.first][start.second];
    pq.push({f[start.first][start.second],start});
    while(!pq.empty()){
        auto tmp = pq.top();pq.pop();
        auto [u,v] = tmp.Y;
        int w = tmp.X;
        if(f[u][v] != w) continue;
        for(int i=0;i<4;i++){
            int dx = u + moveX[i];
            int dy = v + moveY[i];
            if(check(dx,dy) && mat[dx][dy] != '#'){
                if(max(f[u][v],d1[dx][dy]) < f[dx][dy]){
                    pq.push({min(f[u][v],d1[dx][dy]),{dx,dy} });
                    f[dx][dy] = min(f[u][v],d1[dx][dy]);

                }
            }
        }

    }
}
int main(){
    fast;
    indef();
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'S'){
                start.first = i;
                start.second = j;
            }
            if(mat[i][j] == 'E'){
                finish.first = i;
                finish.second = j;
            }
            if(mat[i][j] == '#'){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    //bfs for monsters to get distance 
    while(!q.empty()){
        auto [u,v] = q.front();q.pop();
        for(int i=0;i<4;i++){
            int dx = u + moveX[i];
            int dy = v + moveY[i];
            if(check(dx,dy) && !vis[dx][dy]){
                d1[dx][dy] = d1[u][v] + 1;
                vis[dx][dy] = 1;
                q.push({dx,dy});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]) d1[i][j] = M;
        }
    }
    
    bfs();

    if(f[finish.first][finish.second] >= 1e8)
        cout << 0;
    else
        cout << min(f[finish.first][finish.second],f[start.first][start.second]);
    
}
