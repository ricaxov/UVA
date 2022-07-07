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

vector<int>dist(100);
vector<ii>adj[100],father(1000);
int find(int d){
    int resp=-1;
    if(dist[d]==inf){
        return -1;
    }
    while(father[d].s!=d){
        resp=max(resp,father[d].f);
        d=father[d].s;
    }
    return resp;
}
struct UF{
    vector<int> pai,r;
    UF(int n){
        pai.resize(n);
        r.resize(n);
        for(int i=0;i<n;i++){
            pai[i]=i;
            r[i]=1;            
        }
    }
    UF(){}
    int acha(int x){
        if(pai[x]==x) 
            return x;
        return pai[x]=acha(pai[x]);
    }
    void unir(int x, int y){
        x=acha(x);
        y=acha(y);
        if(r[x]>r[y]){
            pai[y]=x;
            r[x]+=r[y];
        }
        else{
            pai[x]=y;
            r[y]+=r[x];
        }
    }
    bool mesmoConjunto(int x,int y){
        return acha(x)==acha(y);
    }
};
void dijkstra(int o, int d){
    priority_queue<ii, vector<ii>, greater<ii> >pq;
    pq.push({0,o});
    dist[o]=0;
    father[o]={0,o};
    while(!pq.empty()){
        ii u=pq.top(); pq.pop();
        for(ii i : adj[u.s]){
            int peso=i.s;
            int destino=i.f;
            if(dist[destino]>dist[u.s]+peso){
                dist[destino]=dist[u.s]+peso;
                father[destino]={peso,u.s};
                pq.push({dist[destino],destino});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    bool ver=false;
    int n,e,q,a,b,p,o,d,v=1; cin>>n>>e>>q;
    while(n!=0 || e!=0 || q!=0){
        if(ver){
            cout<<endl;
        }
        vector<pair<int,ii>>mst;
        for(int i=0; i<e; i++){
            cin>>a>>b>>p;
            a--;b--;
            mst.pb({p,{a,b}});
        }
        UF grafo(n+1);
        sort(mst.begin(), mst.end());
        for(int i=0; i<e; i++){
            int peso=mst[i].f, x=mst[i].s.f, y=mst[i].s.s;
            if(!grafo.mesmoConjunto(x,y)){
                grafo.unir(x,y);
                adj[x].pb({y,peso});
                adj[y].pb({x,peso});
            }
        }
        cout<<"Case #"<<v++<<endl;
        for(int i=0; i<q; i++){
            for(int i=0; i<100; i++){
                dist[i]=inf;
            }
            cin>>o>>d;
            o--;d--;
            dijkstra(o,d);
            int ans=find(d);
            if(ans==-1){
                cout<<"no path"<<endl;
            }
            else{
                cout<<ans<<endl;
            }
        }
        ver=true;
        father.clear();
        for(int i=0; i<100; i++){
            adj[i].clear();
        }
        cin>>n>>e>>q;
    }
}
