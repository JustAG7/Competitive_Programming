#include <bits/stdc++.h>
using namespace std;
int MINN = 1, MAXN = 10000; // cac hang so
int n, m;
string NAME = "permutation"; // dat ten file o day


bool check(int n){
    while(n > 0){
        if(n % 10 == 0) return false;
        n /= 10;
    }
    return true;
}
int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= 100; iTest++)
    {
        ofstream inp(NAME + ".inp");
        if(iTest <= 30) MAXN = 100;
        else if(iTest <= 10) MINN = 1001, MAXN = 10000;
        else MINN = 10001, MAXN = 30000; 
        n = MINN + rand() % (MAXN - MINN + 1);
        for(int i=1;i<=n;i++){
            a[i] = MINN + rand() & (1e9 - MINN + 1);
        }
        inp << n << '\n';
        for(int i=1;i<=n;i++) inp << a[i] << ' ';
        for(int i=0;i<n;i++){
            m = MINN + rand() % (100000 - MINN + 1);
            while(!check(m)) {
                m = MINN + rand() % (100000 - MINN + 1);
            }
            inp << m << ' ';
        }
        // sinh test o day
        // cout << -> inp <<
        
        inp.close();
        
        auto start = chrono::high_resolution_clock::now(); // Start time
        system("./main");
        auto end = chrono::high_resolution_clock::now(); // End time

        double duration = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0; // Duration in seconds
        cout << "Test " << iTest << " time: " << duration << '\n';
        if (duration > 1.0) {
            cout << "Test " << iTest << ": TLE!\n";
            continue; // Skip checking the output and move to the next test
        }

        system("./sol");

        if(system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            // return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
