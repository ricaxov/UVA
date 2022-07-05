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

int dist[26][26], prox[26][26];
void floydWarshall(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    prox[i][j]=prox[i][k];
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,p,q; cin>>n>>e;
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            dist[i][j]=(i==j ? 0 : inf);
        }
    }
    for(int i=0; i<e; i++){
        char a,b; cin>>a>>b>>p;
        dist[a-65][b-65]=dist[b-65][a-65]=p;
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            prox[i][j]=(dist[i][j]==inf ? -1 : j);
        }
    }
    floydWarshall(26);
    cin>>q;
    for(int i=0; i<q; i++){
        char a,b; cin>>a>>b;
        cout<<a;
        while(a!=b){
            cout<<' ';
            cout<<char(prox[a-65][b-65]+65);
            a=prox[a-65][b-65]+65;
        }
        cout<<endl;
    }
}
