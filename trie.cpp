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

const int k = 26;

struct Trie{
    struct Trie *children[k];
    bool is_end;
};

struct Trie *getNode(void){
    struct Trie *pNode = new Trie;
    pNode->is_end = 0;

    rep(i, k)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct Trie *root, string s){
    struct Trie *temp = root;

    rep(i, sz(s)){
        int x = s[i]-'a';
        if(!temp->children[x])
            temp->children[x] = getNode();
        temp = temp->children[x];
    }

    temp->is_end = 1;
}

bool search(struct Trie *root, string s){
    struct Trie *temp = root;

    rep(i, sz(s)){
        int x = s[i]-'a';
        if(!temp->children[x])
            return 0;
        temp = temp->children[x];
    }

    return (temp and temp->is_end);
}

int main(){
    _
    int t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n;
        struct Trie *root = getNode();
        while(n--){
            cin >> s;
            insert(root, s);
        }

        cin >> s;
        if(search(root, s)) cout << 1<<'\n';
        else    cout << 0 << '\n';
        delete root;
    }
    return 0;
}
