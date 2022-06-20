#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 1000000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<pair<int,ii>>adj;
bool bellmanFord(int n, int e){
    vector<int>dist(n);
    for(int i=0; i<n; i++){
        dist[i]=inf;
    }
    dist[0]=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<e; j++){
            int a=adj[j].f, b=adj[j].s.f, peso=adj[j].s.s;
            if(dist[a]!=inf && dist[b]>dist[a]+peso){
                dist[b]=dist[a]+peso;
            }
        }
    }
    for(int i=0; i<e; i++){
        int a=adj[i].f, b=adj[i].s.f, peso=adj[i].s.s;
        if(dist[a]!=inf && dist[b]>dist[a]+peso){
            return true;
        } 
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,e,a,b,p; cin>>t;
    while(t--){
        cin>>n>>e;
        for(int i=0; i<e; i++){
            cin>>a>>b>>p;
            adj.pb({a,{b,p}});
        }
        cout<<(bellmanFord(n,e) ? "possible" : "not possible")<<endl;
        adj.clear();
    }
}
