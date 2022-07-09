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

vector<int>pai(1000000),r(1000000);
vector<pair<double,pair<double,double>>>adj;
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
double kruskal(int n){
    double ans=0;
    for(int i=0; i<n; i++){
        double peso=adj[i].f,a=adj[i].s.f,b=adj[i].s.s;
        if(!sameSet(a,b)){
            unite(a,b);
            ans+=peso;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n; cin>>t;
    string fds; getline(cin,fds);
    while(t--){
        cin>>n;
        makeSet(n);
        vector<double>x(n),y(n);
        for(int i=0; i<n; i++){
            cin>>x[i]>>y[i];
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double dist=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
                adj.pb({dist,{i,j}}); 
            }
        }
        sort(adj.begin(), adj.end());
        cout<<fixed<<setprecision(2);
        cout<<kruskal(adj.size())<<endl;
        if(t>0){
            cout<<endl;
        }
        adj.clear();
    }
}
