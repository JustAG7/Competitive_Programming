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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define MASK(x, i) (((x) >> (i)) & 1)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


const int M = 1e9+7;
const int N = 3e5+5;
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

struct Trie {
	struct Node {
		Node* child[2];
		int cnt;

		Node() {
			for(int i = 0; i < 2; i++) child[i] = NULL;
			cnt = 0;
		}
	};

	Node* root;
	Trie() {
		root = new Node();
	}

	void add(int x) {
        Node* p = root;
        for(int i = 30; i >= 0; i--) {
            int mask = MASK(x, i);
            if(p->child[mask] == NULL) p->child[mask] = new Node();
            p = p->child[mask];
            p->cnt++;
        }
    }

	void del(int x) {
        Node* p = root;
        for(int i = 30; i >= 0; i--) {
            int mask = MASK(x, i);
            if(p->child[mask] == NULL) return; 
            Node* next = p->child[mask];
            next->cnt--;
            if(next->cnt == 0) {
                p->child[mask] = NULL;
                delete next;
                return;
            }
            p = next;
        }
    }

	int query(int cur) {
		Node* p = root;
		int ans = 0;
		for(int i = 30; i >= 0; i--) {
			int mask = MASK(cur, i);
			int new_mask = mask ^ 1;
			if(p->child[new_mask]) {
				ans |= (1 << i);
				p = p->child[new_mask];
			}
			else {
				if(p->child[mask]) p = p->child[mask];
				else break;
			}
		}
		return ans;
	}
};
void solve(int id){
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 5);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	Trie trie;

	int ans = M;
	for(int l = 1, r = 1; r <= n; r++) {
		trie.add(a[r]);

		int res = trie.query(a[r]);
		while(l <= r && res >= k) {
			ans = min(ans, r - l + 1);
			trie.del(a[l++]);
			res = trie.query(a[r]);
		}
	}
	cout << (ans == M ? -1 : ans) << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}