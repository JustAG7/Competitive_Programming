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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 2e6+100;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

struct Point{
    ll x,y1,y2;
    int type;
    Point() {};
    Point(ll _x, ll _y1, ll _y2, int _type) : x(_x), y1(_y1), y2(_y2), type(_type){};
    bool operator<(const Point& A)  {
        if (x != A.x) return x < A.x;
        return type < A.type;
    }

};


struct Node{
    ll x = 0,y = 0;
    Node() {};
};

vector<ll> posY;
vector<Point> a;
ll length(ll y1,ll y2){
    return posY[y2] - posY[y1];
}


struct SegmentTree {
    Node Tree[N * 4];
    int n;

    SegmentTree() {};
    SegmentTree(int _n) {
        n = _n;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (l >= v || r <= u) return;;
        if (l >= u && r <= v) {
            Tree[id].x += val;
        } else {
            int m = (l + r) >> 1;
            update(id << 1, l, m, u, v, val);
            update(id << 1 | 1, m, r, u, v, val);
        }
        if (Tree[id].x >= 1) {
            Tree[id].y = length(l, r);
        } else {
            Tree[id].y = (l == r ? 0 : Tree[id << 1].y + Tree[id << 1 | 1].y);
        }
    }

    void update_Y(int y1, int y2, int val) {
        update(1, 0, n - 1, y1, y2, val);
    }
};


ll getArea(){
    int m = posY.size();
    SegmentTree ST(m);
    ll ans = 0;
    for(int i=0;i<a.size() - 1;i++){
        ll y1 = lower_bound(all(posY),a[i].y1) - posY.begin();
        ll y2 = lower_bound(all(posY),a[i].y2) - posY.begin();
        ST.update_Y(y1, y2, a[i].type);
        ll ansX = a[i + 1].x - a[i].x;
        ll ansY = ST.Tree[1].y;
        ans += ansX*ansY;
    }
    return ans;
}
int main(){
    fast;
    indef();
    int k,n;
    cin >> k >> n;
    ll x = 0, y = 0;
    for(int i=0;i<n;i++){
        char c;int d;
        cin >> c >> d;
        ll tmpx = x, tmpy = y;
        if(c == 'N') tmpy -= d;
        else if(c == 'S') tmpy += d;
        else if(c == 'E') tmpx += d;
        else tmpx -= d;

        ll x1 = min(x, tmpx);
        ll y1 = min(y, tmpy);
        ll x2 = max(x + k, tmpx + k);
        ll y2 = max(y + k, tmpy + k);

        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        posY.pb(y1);posY.pb(y2);
        a.pb(Point(x1,y1,y2,1));
        a.pb(Point(x2,y1,y2,-1));
        x = tmpx, y = tmpy;
    }
    sort(all(a));sort(all(posY));
    posY.resize(unique(all(posY)) - posY.begin());

    cout << getArea();
}
