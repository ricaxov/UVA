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

int knapsack(int elementos, int *lucro, int *peso, int maximo){
    int ks[elementos+1][maximo+1];
    for(int i=0; i<=elementos; i++){
        for(int j=0; j<=maximo; j++){
            if(i==0 || j==0){
                ks[i][j]=0;
            }
            else{
                if(peso[i]<=j){
                    ks[i][j]=max(lucro[i]+ks[i-1][j-peso[i]], ks[i-1][j]);
                }
                else{
                    ks[i][j]=ks[i-1][j];
                }
            }
        }
    }
    return ks[elementos][maximo];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,x,v,c; cin>>t;
    while(t--){
        cin>>x;
        int lucro[x+1],peso[x+1],res=0;
        lucro[0]=peso[0]=0;
        for(int i=1; i<=x; i++){
            cin>>lucro[i]>>peso[i];
        }
        cin>>v;
        for(int i=0; i<v; i++){
            cin>>c;
            res+=knapsack(x,lucro, peso, c);
        }
        cout<<res<<endl;
    }
}
