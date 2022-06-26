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

int dist[101][101];
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
    int x,y,v=1,soma,cont; cin>>x>>y;
    while(x!=0 && y!=0){
        soma=cont=0;
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                dist[i][j]=(i==j ? 0 : inf);
            }
        }
        while(x!=0 && y!=0){
            dist[x][y]=1;
            cin>>x>>y;
        }
        floydWarshall(101);
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                if(dist[i][j]!=inf && i!=j){
                    soma+=dist[i][j];
                    cont++;
                }
            }
        }
        cout<<fixed<<setprecision(3);
        cout<<"Case "<<v++<<": average length between pages = "<<(float(soma))/cont<<" clicks"<<endl;
        cin>>x>>y;
    }
}
