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

int dist[50][50];
void floydWarshall(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,c=1; cin>>n>>e;
    while(n!=0 || e!=0){
        set<string>s;
        int v=0,ans=0;
        map<string,int>x;
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                dist[i][j]=(i==j ? 0 : inf);
            }
        }
        for(int i=0; i<e; i++){
            string a,b; cin>>a>>b;
            if(s.find(a)==s.end()){
                x[a]=v++;
                s.insert(a);
            }
            if(s.find(b)==s.end()){
                x[b]=v++;
                s.insert(b);
            }
            dist[x[a]][x[b]]=dist[x[b]][x[a]]=1;
        }
        floydWarshall(50);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans=max(ans,dist[i][j]);
            }
        }
        cout<<"Network "<<c++<<": ";
        if(ans==inf){
            cout<<"DISCONNECTED"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
        cout<<endl;
        cin>>n>>e;
    }
}
