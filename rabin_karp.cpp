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
#define MAX 1000001
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pair<int,int>> vii;

// s => substring, t => given string
vi rabin_karp(string const &s, string const &t){
    const int p = 31;
    const int m = 1e9+9;
    // lli mod = 22222223333355757ll;
    int S = sz(s), T = sz(t);

    vlli p_pow(max(S, T));
    p_pow[0] = 1;
    rep1(i, sz(p_pow)-1)
        p_pow[i] = (p_pow[i-1]*p)%m;

    vlli h(T+1, 0);
    rep(i, T)
        h[i+1] = (h[i] + (t[i]-'a'+1)*p_pow[i])%m;

    lli hs=0;
    rep(i, S)
        hs = (hs + (s[i]-'a'+1)*p_pow[i])%m;

    vi res;
    for(int i=0; i+S-1<T; i++){
        lli tmp = (h[i+S]+m-h[i])%m;
        if(tmp == (hs*p_pow[i])%m)
            res.pb(i);
    }
    return res;
}
