#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
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
const int N = 5e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

typedef struct snode *sn;
struct snode {       // borrow from Benq  
	sn p, c[2];        
	bool flip = 0;     
	int sz;            
	ll sub, vsub = 0;  
	ll val;            
	ll sum;
	snode(int _val) : val(_val) {
		p = c[0] = c[1] = NULL;
		calc();
	}
	friend int getSz(sn x) { return x ? x->sz : 0; }
	friend ll getSub(sn x) { return x ? x->sub : 0; }
	friend ll getSum(sn x) { return x ? x->sum : 0; }
	void prop() {  
		if (!flip) return;
		swap(c[0], c[1]);
		flip = 0;
		for (int i = 0; i < 2; i++)
			if (c[i]) c[i]->flip ^= 1;
	}
	void calc() { 
		for (int i = 0; i < 2; i++)
			if (c[i]) c[i]->prop();
		sz = 1 + getSz(c[0]) + getSz(c[1]);
		sub = val + getSub(c[0]) + getSub(c[1]) + vsub;
		sum = val + getSum(c[0]) + getSum(c[1]);
	}
	
	int dir() {
		if (!p) return -2;
		for (int i = 0; i < 2; i++)
			if (p->c[i] == this) return i;
		return -1;  
	}  
	
	bool isRoot() { return dir() < 0; }
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y;
	}
	void rot() {  
		assert(!isRoot());
		int x = dir();
		sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x ^ 1], x);
		setLink(this, pa, x ^ 1);
		pa->calc();
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
		calc();
	}
	sn fbo(int b) {  
		prop();
		int z = getSz(c[0]); 
		if (b == z) {
			splay();
			return this;
		}
		return b < z ? c[0]->fbo(b) : c[1]->fbo(b - z - 1);
	}
	
	void access() {  
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay();  
			if (pre) v->vsub -= pre->sub;
			if (v->c[1]) v->vsub += v->c[1]->sub;
			v->c[1] = pre;
			v->calc();
			pre = v;
		}
		splay();
		assert(!c[1]);  
	}
	void makeRoot() {
		access();
		flip ^= 1;
		access();
		assert(!c[0] && !c[1]);
	}
	
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access();
		if (!x->p) return NULL;
		x->splay();
		return x->p ?: x;  
	} 
	friend bool connected(sn x, sn y) { return lca(x, y); }
	
	int distRoot() {
		access();
		return getSz(c[0]);
	}
	sn getRoot() {  
		access();
		sn a = this;
		while (a->c[0]) a = a->c[0], a->prop();
		a->access();
		return a;
	}
	sn getPar(int b) {  
		access();
		b = getSz(c[0]) - b;
		assert(b >= 0);
		return fbo(b);
	}  
	
	void set(int v) {
		access();
		val = v;
		calc();
	}
	friend void link(sn x, sn y, bool force = 0) {
		assert(!connected(x, y));
		if (force) y->makeRoot();  
		else {
			y->access();
			assert(!y->c[0]);
		}
		x->access();
		setLink(y, x, 0);
		y->calc();
	}
	friend void cut(sn y) {  
		y->access();
		assert(y->c[0]);
		y->c[0]->p = NULL;
		y->c[0] = NULL;
		y->calc();
	}
	friend void cut(sn x, sn y) {  
		x->makeRoot();
		y->access();
		assert(y->c[0] == x && !x->c[0] && !x->c[1]);
		cut(y);
	}
};

sn LCT[N];

void solve(int id){
	int q;
	cin >> q;
	int n = 1;
	LCT[1] = new snode(1);
	for(int i = 0; i < q; i++) {
		char t; int u;
		cin >> t >> u;
		if(t == 'A') {
			n++;
			LCT[n] = new snode(1);
			link(LCT[u], LCT[n], 1);
		}
		else if(t == 'C') {
			cut(LCT[u]);
		}
		else {
			LCT[u]->access();
			cout << LCT[u]->vsub + LCT[u]->val << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}