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

vector<int>dist(200);
vector<pair<int,ii>>adj;
void bellmanFord(int n, int e){
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
            dist[b]=-inf;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,a,b,q,x,v=1;
    while(cin>>n){
        vector<int>values(n), ans;
        for(int i=0; i<n; i++){
            cin>>values[i];
        }
        cin>>e;
        for(int i=0; i<e; i++){
            cin>>a>>b;
            a--;b--;
            adj.pb({a,{b,pow(values[b]-values[a],3)}});
        }
        cin>>q;
        bellmanFord(n,e);
        cout<<"Set #"<<v++<<endl; 
        for(int i=0; i<q; i++){
            cin>>x;
            if(dist[x-1]<3 || dist[x-1]==inf){
                cout<<"?"<<endl;
            }
            else{
                cout<<dist[x-1]<<endl;
            }
        }
        adj.clear();
    }
}
