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
const int N = 2e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}
int cnt[N];
vector<ll> res[N];
ll a[N];
struct BIT{
	vector<ll> bit;
	vector<int> pos;
	int x;
	int size;
	void init(int newX, int newSize){
		if(!newSize) return;
		x = newX;
		size = newSize;
		bit.resize(size + 2, 0);
		pos.resize(size + 2, 0);
		for(int i=1;i<=size;i++){
			update(i, res[x][i - 1]*res[x][i - 1], res[x][i - 1]);
		}
	}
	void update(int u,ll val,int newPos){
		pos[u] = newPos;
		for(;u <= size; u += u & (-u)){
			bit[u] += val;
		}	
	}
	int PosValue(int x){
		return pos[x];
	}
	int getPos(int val){
		if(!bit.size()) return 0;
		int x = upper_bound(pos.begin() + 1, pos.begin() + size + 1, val) - pos.begin() - 1;
		if(x >= size) x = size;
		return x;
	}
	ll query(int u){
		if(!bit.size()) return 0LL;
		ll ans = 0;
		for( ;u > 0;u -= u & (-u)){
			ans += bit[u];
		}
		return ans;
	}
	int getSize(){
		return bit.size();
	}
	void print(){
		if(!bit.size()) return;
		for(int i=1;i<=size;i++) cout << bit[i] << ' ';cout << nl;
		for(int i=1;i<=size;i++) cout << pos[i] << ' ';
		cout << nl;
	}
};
void solve(){
	int n,q;
	cin >> n >> q;
	BIT bit[n + 1];
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		cnt[a[i]]++;
		res[a[i]].pb(i);
	}
	for(int i=1;i<=n;i++){
		bit[i].init(i, cnt[i]);
		// bit[i].print();
	}
	ll last = 0;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			ll u;
			cin >> u;
			u = (u + last - 1) % (n - 1) + 1;
			int pos1 = bit[a[u]].getPos(u);
			int pos2 = bit[a[u + 1]].getPos(u + 1);
			int newPos1 = bit[a[u]].PosValue(pos1);
			int newPos2 = bit[a[u + 1]].PosValue(pos2);
			bit[a[u + 1]].update(pos1, u*u - (u + 1)*(u + 1), newPos1);
			bit[a[u]].update(pos2, - u*u + (u + 1)*(u + 1), newPos2);
			swap(a[u],a[u + 1]);
		}
		else{
			ll u,v,k;
			cin >> u >> v >> k;
			u = (u + last - 1) % n + 1;
			v = (v + last - 1) % n + 1;
			k = (k + last - 1) % n + 1;
			if(u > v) swap(u, v);
			cout << u << ' ' << v << ' ' << k << nl;
			if (t == 2) {
		        int pos1 = bit[k].getPos(u);
		        int pos2 = bit[k].getPos(v);

		        if(u == v){
		        	cout << pos1 << ' ' << pos2 << nl;
		        	pos1 = max(pos1, 1);
		        	if(pos1 == pos2) pos1 = pos2;
		        	
		        	bit[k].print();
		        }
		        
		        last = bit[k].query(pos2) - bit[k].query(pos1 - 1);
		    }
		    else {
		        // bit[k].print();
		        last = bit[k].query(v) - bit[k].query(u - 1);
		    }
			cout << last << nl;
		}

	}

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}