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
#define MAX 100007
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

bool cmp(const pair<lli, lli> &a,const pair<lli, lli> &b){
    return a.se < b.se;
}

int main(){
    _
    lli n, r, avg;
    cin >> n >> r >>avg;
    lli tSum = avg*n, pSum=0, res=0;
    vector<pair<lli, lli>> arr;
    rep(i,n){
        lli a,b;
        cin >> a >> b;
        arr.pb(mp(a,b));
        pSum += a;
    }
    sort(arr.begin(), arr.end(), cmp);
    // cout << pSum << ' ' << tSum << endl;
    if(pSum>=tSum)  cout << 0;
    else{
        tSum -= pSum;
        for(int i=0; i<n && tSum>0; i++){
            lli x = r-arr[i].fi;
            if(x >= tSum){
                res += arr[i].se*tSum;
                tSum = 0;
                break;
            }
            else{
                tSum -= x;
                res += arr[i].se*x;
            }
        }
        cout << res;
    }
    
    return 0;
}