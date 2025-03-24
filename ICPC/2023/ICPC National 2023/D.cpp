#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int,int> mp;
        long long ans = 0;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int l=0,r=0;r<n;r++){
            mp[a[r]]++;
            while(mp[a[r]]>1){
                mp[a[l]]--;
                l++;
            }
        
            ans += r - l + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
