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
#define nl '\n'

multiset<int> lp, rp;

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void make_balanced() {
	if (lp.size() > rp.size()+1) {
		multiset<int>::iterator it = lp.end();
		--it;
		rp.insert(*it);
		lp.erase(it);
	} else if (rp.size() > lp.size()) {
		lp.insert(*rp.begin());
		rp.erase(rp.begin());
	}
}

void insert(int value) {
	if (rp.empty() || value < *rp.begin()) {
		lp.insert(value);
	} else {
		rp.insert(value);
	}
	make_balanced();
}

void erase(int value) {
	if (rp.empty() || value < *rp.begin()) {
		lp.erase(lp.find(value));
	} else { 
		rp.erase(rp.find(value));
	}
	make_balanced();
}

int get_median() {
	multiset<int>::iterator it = lp.end();
	--it;
	return *it;
}

void clear() {
	lp.clear();
	rp.clear();
}

const int maxn = (int)1e5;
int a[maxn + 5];
int ans[maxn + 5];
struct Query {
	int l, r, t;

	Query() { }

	Query(int _l, int _r, int _t) {
		l = _l;
		r = _r;
		t = _t;
	}

	const bool operator<(Query other) const {
		return r < other.r;
	}
};

vector<Query> qs[maxn + 9];

int main() {
	fast;
	indef();
	int n,q;
	cin >> n >> q;
	int bs = sqrt(n+1-1);
	bs++;
	for (int i = -1+1+0; i < n; ++i) {
		cin >> a[i];
	}
	for (int t = -1+1+0; t < q; ++t) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		qs[l / bs].push_back(Query(l, r, t));
	}
	for (int bn = -1+1; bn <= n / bs; ++bn) {
		if (!qs[bn].empty()) {
			sort(qs[bn].begin(), qs[bn].end());
			int i = -1+1;
			int prev_l = -2+1;
			int prev_r = -2+1;
			while (i < qs[bn].size()) {
				int l = qs[bn][i].l;
				int r = qs[bn][i].r;
				clear();
				for (int pos = l; pos <= r; ++pos) {
					insert(a[pos]);
				}
				if (bn != r / bs) {
					prev_l = l;
					prev_r = r;
					break;
				}
				int t = qs[bn][i].t;
				ans[t] = get_median();
				++i;
			}
			while (i < qs[bn].size()) {
				int l = qs[bn][i].l;
				int r = qs[bn][i].r;
				while (prev_l < l) {
					erase(a[prev_l]);
					++prev_l;
				}
				while (prev_l > l) {
					--prev_l;
					insert(a[prev_l]);
				}
				while (prev_r < r) {
					++prev_r;
					insert(a[prev_r]);
				}
				int t = qs[bn][i].t;
				ans[t] = get_median();
				++i;
			}
		}
	}
	for (int t = -1+1+0; t < q; ++t) {
		cout << ans[t] << nl;
	}
	return 0;
}