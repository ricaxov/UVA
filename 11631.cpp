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
    UF(int m){
        pai.resize(m);
        r.resize(m);
        for(int i=0;i<m;i++){
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    while(m!=0 || n!=0){
    	int soma=0;
	    vector<pair<int,pair<int,int> > >arestas;
	    for(int i=0;i<n;i++){
	        int a,b,p;
	        cin>>a>>b>>p;
	        arestas.push_back(make_pair(p,make_pair(a,b)));
	    }
	    sort(arestas.begin(),arestas.end());
	    UF estrada(m+1);
	    int ans=0;
	    for(int i=0;i<arestas.size();i++){
	        int peso=arestas[i].first;
	        soma+=peso;
	        int a=arestas[i].second.first;
	        int b=arestas[i].second.second;
	        if(!estrada.mesmoConjunto(a,b)){
	            estrada.unir(a,b);
	            ans+=peso;
	        }
	    }
	    cout<<soma-ans<<endl;
	    cin>>m>>n;
	}
}
