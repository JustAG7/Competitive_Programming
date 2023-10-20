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
#define vi vector<int>

const int M=1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
class SegTree {
private:
    ll st[4*N];
 
public:
    SegTree() {
    }
 
    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        int m = (l+r)/2;
        build(id*2, l, m);
        build(id*2+1, m+1, r);
        st[id] = min(st[id*2] , st[id*2+1]);
    }
 
    void update(int id, int l, int r, int pos, int val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = (l+r)/2;
        update(id*2, l, m, pos, val);
        update(id*2+1, m+1, r, pos, val);
        st[id] = min(st[id*2],st[id*2+1]);
    }
 
    ll query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 2e9;
        if (u <= l && r <= v) return st[id];
        int m = (l+r)/2;
        return min(query(id*2, l, m, u, v) , query(id*2+1, m+1, r, u, v));
    }
};
void solve(){
	int n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	string s;
	cin >> s;
	vi ans;

}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}