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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> a(n);
	int m = (k + 1)/2, curr = 0;
	ll leftSum = 0, rightSum = 0;
	priority_queue<ii> left; // smaller or equal to median
	priority_queue<ii,vector<ii>,greater<ii>> right; // greater than median

	for(int i=0;i<n;i++){
		cin >> a[i].X;
		a[i].Y = i;
	}
	int index = -1;
	ll medianAns = -1;
	ll ans = 1e18;
	for(int i=0;i<n;i++){
		while(!right.empty() && right.top().Y <= i - k) right.pop();
		while(!left.empty() && left.top().Y <= i - k) left.pop();

		if(curr < m){ // push to left 
			right.push(a[i]);
			rightSum += a[i].X;

			left.push(right.top());
			leftSum += right.top().X;

			rightSum -= right.top().X;
			right.pop();

			curr++;
		}
		else{ // push to right
			left.push(a[i]);
			leftSum += a[i].X;

			right.push(left.top());
			rightSum += left.top().X;

			leftSum -= left.top().X;
			left.pop();
		}

		while(!right.empty() && right.top().Y <= i - k) right.pop();
		while(!left.empty() && left.top().Y <= i - k) left.pop();

		if(i < k - 1) continue;

		ll median = left.top().X;
		ll leftAns = m*median - leftSum;
		ll rightAns = rightSum - (k - m)*median;

		if(leftAns + rightAns < ans){ // get the answer
			ans = leftAns + rightAns;
			medianAns = median;
			index = i;
		}

		if(a[i - k + 1].X <= left.top().X){
			curr--;
			leftSum -= a[i - k + 1].X;
		}
		else rightSum -= a[i - k + 1].X;
	}

	if(ans == 0){
		cout << ans << nl;
		for(int i=0;i<n;i++) cout << a[i].X << nl;
	}
	else{
		cout << ans << nl;
		for(int i = index; i>= index - k + 1;i--) a[i].X = medianAns;
		for(int i=0;i<n;i++) cout << a[i].X << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}