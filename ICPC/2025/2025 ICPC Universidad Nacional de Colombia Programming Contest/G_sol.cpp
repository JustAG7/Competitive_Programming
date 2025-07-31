#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

typedef pair<int,int> pii;

priority_queue <pii, vector<pii>, greater<pii>> int_time;

const int N = 300'005;

//DSU
int par[N], center[N], radius[N], nxt_n[N], lst_n[N];
int last_time[N];

int root ( int node ) {
    if ( par[node] )
        return par[node] = root ( par[node] );
    return node;
}

bool join ( int n_A, int n_B ) {
    n_A = root ( n_A ), n_B = root ( n_B );
    if ( n_A == 0 or n_B == 0 ) return false;
    if ( n_A == n_B ) return false;
    if ( radius[n_A] < radius[n_B] ) swap ( n_A, n_B );
    radius[n_A] += radius[n_B];
    nxt_n[n_A] = max (nxt_n[n_B], nxt_n[n_A]);
    lst_n[n_A] = min (lst_n[n_B], lst_n[n_A]);
    par[n_B] = n_A;
    return true;
}

void upd_new_time ( int ind ) {
    ind = root ( ind );
    if ( lst_n[ind] < 1 ) return;
    int l_ind = root ( lst_n[ind] );
    int this_time = ((center[ind] - radius[ind]) - 
                        (center[l_ind] + radius[l_ind])) / 2;
    int_time.push ( {this_time, ind} );
    last_time[ind] = this_time;
}

int main () {

    int n;
    scanf ( "%d", &n );

    for ( int i = 1; i <= n; ++i ) {
        scanf ( "%d%d", &center[i], &radius[i] );
        center[i] *= 2, radius[i] *= 2;
        if ( i < n ) nxt_n[i] = i+1;
        if ( i > 1 ) lst_n[i] = i-1, upd_new_time ( i );
    }

    vector <int> merge_times;

    while ( !int_time.empty() ) {
        auto [c_time, ind] = int_time.top ();
        int_time.pop ();
        if ( last_time[ind] != c_time ) continue;
        if ( join ( lst_n[ind], ind ) ) {
            merge_times.push_back ( c_time );
            int n_ind = root ( ind );
            upd_new_time ( n_ind );
            upd_new_time ( nxt_n[n_ind] );
        }
    }

    sort ( merge_times.begin(), merge_times.end() );
    assert ( merge_times.size() == n-1 );

    int q;
    scanf ( "%d", &q );
    while ( q-- ) {
        int c_q;
        scanf ( "%d", &c_q );
        c_q *= 2;
        int n_merges = upper_bound ( merge_times.begin(), merge_times.end(), c_q ) -
                        merge_times.begin();
        printf ( "%d\n", n - n_merges );
    }


    return 0;
}