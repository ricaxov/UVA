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

int matrix[1000][1000], dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
int dijkstra(int maxX, int maxY){
    priority_queue<pair<int,ii>, vector<pair<int,ii>>, greater<pair<int,ii>>>pq;
    int dist[maxX][maxY];
    for(int i=0; i<maxX; i++){
        for(int j=0; j<maxY; j++){
            dist[i][j]=inf;
        }
    }
    dist[0][0]=matrix[0][0];
    pq.push({0,{0,0}});
    while(!pq.empty()){
        pair<int,ii>u=pq.top(); pq.pop();
        for(int i=0; i<4; i++){
            int ax=u.s.f+dx[i];
            int ay=u.s.s+dy[i];
            if(ax>=0 && ax<maxX && ay>=0 && ay<maxY && dist[ax][ay]>dist[u.s.f][u.s.s]+matrix[ax][ay]){
                dist[ax][ay]=dist[u.s.f][u.s.s]+matrix[ax][ay];
                pq.push({dist[ax][ay],{ax,ay}});
            }
        }
    }
    return dist[maxX-1][maxY-1];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,m; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
            }
        }
        int ans=dijkstra(n,m);
        cout<<ans<<endl;
    }
}
