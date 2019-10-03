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

// generate lps(longest prefix which is also a suffix) array
// prefix function
vi prefix(const string &s){
    int n = sz(s);
    vi p(n);

    int j=0, i=1;
    while(i<n){
        if(s[i]==s[j]) p[i++]=++j;
        else{
            if(j!=0) j = p[j-1];
            else p[i++] = 0;
        }
    }
    return p;
}

void KMP(string pat, string txt){
    int M = sz(pat);
    int N = sz(txt);
    vi lps = prefix(pat);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N){
        if (pat[j] == txt[i]) j++, i++;

        if (j == M){
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]){
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}
