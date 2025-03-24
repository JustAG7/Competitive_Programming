#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 1e5 + 7;
int n, cnt;
string s;
vector<string> a;


void indef(){
    freopen("permutation.inp", "r", stdin);
    freopen("permutation.out", "w", stdout);
}
bool check(string inp)
{
    int len = inp.length();
    // cout << len;
    if (len & 1)
        return 0;
    ll sumL = 0, sumR = 0;
    for (int i = 0; i < len / 2; i++)
    {
        sumL += char(inp[i]);
    }
    for (int i = len / 2; i < len; i++)
    {
        sumR += char(inp[i]);
    }
    return sumL == sumR;
}

void sub1()
{
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a.push_back(s);
    }
    int sz = a.size();
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            s = a[i] + a[j];
            // cout << s << " " << check(s) << endl;
            cnt += check(s);
        }
    }
    cout << cnt;
}

int main()
{
    indef();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    // if (n <= 1000)
        sub1();
    return 0;
}