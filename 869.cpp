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

bool dist1[26][26], dist2[26][26];
void floydWarshall(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist1[i][k] && dist1[k][j]) dist1[i][j]=true;
                if(dist2[i][k] && dist2[k][j]) dist2[i][j]=true;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,m; cin>>t;
    while(t--){
        bool ver=true;
        string fds; getline(cin,fds);
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                dist1[i][j]=dist2[i][j]=false;
            }
        }
        cin>>n;
        for(int i=0; i<n; i++){
            char a,b; cin>>a>>b;
            dist1[a-65][b-65]=true;
        }
        cin>>m;
        for(int i=0; i<m; i++){
            char a,b; cin>>a>>b;
            dist2[a-65][b-65]=true;
        }
        floydWarshall(26);
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(dist1[i][j]!=dist2[i][j]){
                    ver=false;
                }
            }
        }
        cout<<(ver ? "YES" : "NO")<<endl;
        if(t>0){
            cout<<endl;
        }
    }
}
