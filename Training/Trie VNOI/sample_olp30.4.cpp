#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
#define MASK(x, i) (((x) & (1 << (i))) ? 1 : 0)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

const int M = 1e9+7;
const int N = 1e5;
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

const int LG = 16;

int n, m, k;
int a[N];
struct Trie {
    struct Node {
        Node* child[2];
        int cnt;

        Node() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Node* root;
    Node* cur;
    int prev;

    Trie() {
        root = new Node();
        cur = root;
        prev = -1;
    }

    int lcp(int x, int y) {
        for (int i = m - 1; i >= 0; i--) {
            if (MASK(x, i) != MASK(y, i)) {
                return i; 
            }
        }
        return -1; 
    }

    void add_number(int x) {
        if (prev == -1) {
            cur = root;
        } else {
            int lcp_pos = lcp(x, prev);
            cur = root; 

            for (int i = m - 1; i > lcp_pos; i--) {
                int c = MASK(prev, i);
                cur = cur->child[c];
            }
        }

        for (int i = lcp(x, prev); i >= 0; i--) {
            int c = MASK(x, i);
            if (!cur->child[c]) cur->child[c] = new Node();
            cur = cur->child[c];
        }

        cur->cnt++;
        prev = x; 
    }

    int count(int mask, Node* node = nullptr, int pos = m - 1, int diff = 0) {
        if (!node) node = root;
        if (diff > k || k - diff > pos + 1) return 0;
        if (pos == -1) return (diff == k) ? node->cnt : 0;

        int cur_bit = MASK(mask, pos);
        int ans = 0;

        if (node->child[0]) 
        	ans += count(mask, node->child[0], pos - 1, diff + (cur_bit == 1));
        
        if (node->child[1]) 
        	ans += count(mask, node->child[1], pos - 1, diff + (cur_bit == 0));

        return ans;
    }
} trie;


void solve(int id) {
    cin >> n >> m >> k;
    int ans = 0, prev = -1;
    for (int i = 0; i < n; i++) {
        int x = 0;
        string s; cin >> s;
        reverse(all(s));
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') x |= (1 << j);
        }
        a[i] = x;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) {
            ans += prev;
            trie.cur->cnt++; 
        } else {
            prev = trie.count(a[i]);
            ans += prev;
            trie.add_number(a[i]);
        }
    }

    cout << ans;
}



int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}
