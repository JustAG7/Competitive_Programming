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

const int M=1e9+7;
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	fast;
	indef();
	int l, r; 
	cin >> l >> r;
    int n = r-l+1;
    vector<string> a;
    for (int i = l; i <= r; ++i)
        a.push_back(to_string(i));
    
    vector<string> f(1, a[0]);
    for (string i: a) {
        if (i > f.back()) 
            f.push_back(i);
        else if (i <= f[0])
            f[0] = i;
        else {
            int j = lower_bound(f.begin(), f.end(), i) - f.begin();
            f[j] = i;
        }
    }
    cout << n - f.size();
}