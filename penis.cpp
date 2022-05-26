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

char matrix[101][101];
int dx[8]={0,1,0,-1,1,-1,1,-1}, dy[8]={1,0,-1,0,-1,1,1,-1};
int bfs(int startX, int startY, int finishX, int finishY, int maxX, int maxY){
	matrix[startX][startY]='X';
	queue<pair<int, ii>>q;
	q.push({startX,{startY,0}});
	while(!q.empty()){
		pair<int,ii> u=q.front(); q.pop();
		if(u.f==finishX && u.s.f==finishY){
			return u.s.s;
		}
		for(int i=0; i<8; i++){
			int ax=u.f+dx[i];
			int ay=u.s.f+dy[i];
			if(ax>=0 && ax<maxX && ay>=0 && ay<maxY && matrix[ax][ay]!='X'){
				matrix[ax][ay]='X';
				q.push({ax,{ay,u.s.s+1}});
			}
		}
	}
	return -1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t,n,m,cavX[8]={-1,-2,-2,-1,1,2,2,1},cavY[8]={-2,-1,1,2,-2,-1,1,2}; cin>>t;
	while(t--){
		cin>>n>>m;
		ii start, finish;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>matrix[i][j];
				if(matrix[i][j]=='A'){
					start={i,j};
				}
				else{
					if(matrix[i][j]=='B'){
						finish={i,j};
					}
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(matrix[i][j]=='Z'){
					matrix[i][j]='X';
					for(int k=0; k<8; k++){
						int ax=i+cavX[k];
						int ay=j+cavY[k];
						if(ax>=0 && ax<n && ay>=0 && ay<m && matrix[ax][ay]=='.'){
							matrix[ax][ay]='X';
						}
					}
				}
			}
		}
		/*for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) cout<<matrix[i][j]<<" ";
			cout<<endl;
		}*/
		//cout<<"start: "<<start.f<<" "<<start.s<<" "<<" finish: "<<finish.f<<" "<<finish.s<<"\n"<<n<<" "<<m<<endl;
		int ans=bfs(start.f,start.s,finish.f,finish.s,n,m);
		if(ans==-1){
			cout<<"King Peter, you can't go now!"<<endl;
		}
		else{
			cout<<"Minimal possible length of a trip is "<<ans<<endl;
		}
	}
}
