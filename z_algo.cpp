#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,n) for(int i=n-1;i>=0;i--)
#define rep3(i,n) for(int i=n;i>1;i--)

#define fi first
#define se second
#define pb(x) push_back(x)
#define po(x) pop_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(x) ((int) (x).size())
#define MAX 1000010
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pair<int,int>> vii;

vi z_function(const string &s) {
    int n = sz(s);
    vi z(n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }
    return z;
}
