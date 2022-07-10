#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 100000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<pair<int,ii>>adj;
vector<int>pai(1000000),r(1000000);
void makeSet(int n){
    for(int i=0; i<n; i++){
        pai[i]=i;
        r[i]=1;
    }
}
int find(int x){
    if(pai[x]==x){
        return x;
    }
    return pai[x]=find(pai[x]);
}
bool sameSet(int x, int y){
    return find(x)==find(y);
}
void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(r[x]>r[y]){
        pai[y]=x;
        r[x]+=r[y];
    }
    else{
        pai[x]=y;
        r[y]+=r[x];
    }
}
int kruskal(int n){
    int ans=0;
    for(int i=0; i<n; i++){
        int peso=adj[i].f,a=adj[i].s.f,b=adj[i].s.s;
        if(!sameSet(a,b)){
            unite(a,b);
            ans+=peso;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,e,p; cin>>t;
    while(t--){
        int v=0;
        cin>>n>>e;
        makeSet(n);
        string a,b;
        set<string>s;
        map<string,int>x;
        for(int i=0; i<e; i++){
            cin>>a>>b>>p;
            if(s.find(a)==s.end()){
                x[a]=v++;
                s.insert(a);
            }
            if(s.find(b)==s.end()){
                x[b]=v++;
                s.insert(b);
            }
            adj.pb({p,{x[a],x[b]}});
        }
        sort(adj.begin(), adj.end());
        cout<<kruskal(adj.size())<<endl;
        if(t>0){
            cout<<endl;
        }
        adj.clear();
    }
}
