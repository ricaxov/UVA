#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define ll long long
#define ii pair<int,int>

using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},cont;
char matrix[101][101];
void floodfill(int x, int y, int m){
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax>=0 && ax<m && ay>=0 && ay<m && (matrix[ax][ay]=='x' || matrix[ax][ay]=='@')){
			matrix[ax][ay]='.';
			floodfill(ax,ay,m);
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,x;cin>>n;
    for(int i=0; i<n; i++){
    	cin>>x;
    	cont=0;
    	for(int j=0; j<x; j++){
    		for(int k=0; k<x; k++){
    			cin>>matrix[j][k];
			}
		}
		for(int j=0; j<x; j++){
    		for(int k=0; k<x; k++){
    			if(matrix[j][k]=='x'){
    				floodfill(j,k,x);
    				cont++;
				}
			}
		}
		cout<<"Case "<<i+1<<": "<<cont<<endl;
	}
}
