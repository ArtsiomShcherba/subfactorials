#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define int long long
#define vec vector
#define fir first
#define sec second
#define all(m) (m).begin(), (m).end()
#define forn(i,n) for(int i=0;i<n;i++)

typedef pair<int, int> pii;

int inf = 1e17;
int mod = 1e9+7;

vec<vec<int> > g;
vec<int> p;
vec<bool> used;

random_device rd;
mt19937 gr(rd());

bool dfs(int v){
    if(used[v])
        return false;
    used[v] = true;
    for(int u: g[v]){
        if(p[u]<0 || dfs(p[u])){
            p[u] = v;
            return true;
        }
    }
    return false;
}

void refill(int sz){
    used.clear();
    used.resize(sz,false);
}

void solve(){
    int n,m,k;
    cin>>n>>k;
    if (k<=0||k>n) {
        cout<<"No permutations";
        return;
    }
    m = n*n;

    p.resize(2*n,-1);
    g.resize(2*n);

    forn(i,n){
        forn(j,n) {
            g[i].push_back(n+j);
            g[n+i].push_back(j);
        }
        shuffle(all(g[i]),gr);
    }
    n*=2;

    forn(qq,k) {

        refill(n);
        forn(i,n){
            if(dfs(i))
                refill(n);
        }

        forn(i,n){
            if(i>=n/2 && p[i]>=0) {
                auto it = std::find(all(g[p[i]]), i);
                if (it != g[p[i]].end())
                    g[p[i]].erase(it);
                cout<<p[i]+1<<" ";
            }
        }
        cout<<"\n";
        p.assign(n,-1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}