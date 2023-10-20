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

const int M = 1e9+7;
const int N = 2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll a[N];
void solve(){
	int n,k;
	cin >> n >> k;
	vector<ii> a(n);
	priority_queue<ii> left; // smaller or equal than the median value
	priority_queue<ii, vector<ii>, greater<ii> > right; // greater than the median value
	ll leftSum = 0, rightSum = 0;
	int m = (k + 1)/2, curr = 0;
	for(int i=0;i<n;i++){
		cin >> a[i].X;
		a[i].Y = i;
	}
	for(int i=0;i<n;i++){
		// remove all the elements that out of bounds
		while(!right.empty() && right.top().Y <= i - k) right.pop();
		while(!left.empty() && left.top().Y <= i - k) left.pop();			
		if(curr < m){ //push (k + 1)/2 elements to left
			right.push(a[i]);
			rightSum += a[i].X;
			
			left.push(right.top());
			leftSum += right.top().X;

			rightSum -= right.top().X;
			right.pop();

			curr++;
		}
		else{ // push the k - (k + 1)/2 elements to right
			left.push(a[i]);
			leftSum+=a[i].X;

			right.push(left.top());
			rightSum += left.top().X;

			leftSum -= left.top().X;
			left.pop();
		}

		// remove all the elements that out of bounds (just to make sure)
		while(!right.empty() && right.top().Y <= i - k) right.pop();
		while(!left.empty() && left.top().Y <= i - k) left.pop();

		if(i < k - 1) continue; // get to k first lmao

		ll median = left.top().X;
		// cout << median << ' ';
		ll leftAns = m*median - leftSum;
		ll rightAns = rightSum - (k - m)*median;
		cout << leftAns + rightAns << ' ';
		if(a[i - k + 1].X <= left.top().X){ // if the elements out of bounds is in the left
											// then remove it and decrease the curr to get a new median
			curr--;
			leftSum -= a[i - k + 1].X;
		}
		else rightSum -= a[i - k + 1].X; // else just relax
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}