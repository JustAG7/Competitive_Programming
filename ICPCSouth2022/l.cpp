#include <bits/stdc++.h>
using namespace std;

int sum_(char a, char b)
{
    return ((a - 48) + (b - 48));
}

int main()
{
    int n;
    string a, b, c;
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        cin>>a>>b>>c;

        vector<int> kp(n, 0);
        vector<int> tp(n, 0);
        int keep, s;
        for (int i = n - 1; i >= 0; i--)
        {
            s = sum_(a[i], b[i]);
            if (s % 10 - (c[i] - 48) > 1)
            {
                kp[i] = 0;
                continue;
            }
            keep = 0;
            
            for (int j = n - 1; j > i; j--)
            {
                int tpj = sum_(a[j], b[j])/10;
                if (kp[j] > keep && ((s + tpj) % 10) == (c[i] - 48))
                {
                    keep = kp[j];
                    tp[i] = tpj;
                }
            }
            if (keep == 0) {
                tp[i] = s/10;
            }
            kp[i] = keep + 1;
        }

        // for(int i=0; i<n; i++) {
        //     cout<<kp[i]<<" ";
        // }
        // for(int i=0; i<n; i++) {
        //     cout<<tp[i]<<" ";
        // }

        int max_ = 0;
        for (int i=0; i<n; i++) {
            if (kp[i] > max_ && sum_(a[i], b[i]) + tp[i] == (c[i] - 48)) {
                max_ = kp[i];
            }
        }
        cout<<n-max_<<endl;
    }
    return 0;
}