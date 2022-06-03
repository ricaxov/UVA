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
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,x,y,p; cin>>n>>e;
    while(n!=0 || e!=0){
        vector<int>vec;
        vector<pair<int,ii>>adj;
        for(int i=0; i<e; i++){
            cin>>x>>y>>p;
            adj.pb({p,{x,y}});
        }
        sort(adj.begin(), adj.end());
        UF grafo(n+1);
        for(int i=0; i<e; i++){
            int peso=adj[i].f, x=adj[i].s.f, y=adj[i].s.s;
            if(!grafo.mesmoConjunto(x,y)){
                grafo.unir(x,y);
            }
            else{
                vec.pb(peso);
            }
        }
        if(vec.size()==0){
            cout<<"forest"<<endl;
        }
        else{
            for(int i=0; i<vec.size(); i++){
                cout<<vec[i];
                if(i<vec.size()-1){
                    cout<<' ';
                }
            }
            cout<<endl;
        }
        cin>>n>>e;
    }
}
