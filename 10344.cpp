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

bool ver;
vector<int>vec(5),tryAll;
vector<bool>vis(5);
void f(int soma, int x, vector<int>&tryAll){
    if(x==5){
        if(soma==23){
            ver=true;
        }
        return;
    }
    f(soma+tryAll[x], x+1, tryAll);
    f(soma-tryAll[x], x+1, tryAll);
    f(soma*tryAll[x], x+1, tryAll);
}
void permutacao(int n, int x){
    if(n==x){
        f(tryAll[0], 1, tryAll);
        return;
    }
    for(int i=0; i<5; i++){
        if(!vis[i]){
            vis[i]=true;
            tryAll.pb(vec[i]);
            permutacao(n,x+1);
            tryAll.pop_back();
            vis[i]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>vec[0]>>vec[1]>>vec[2]>>vec[3]>>vec[4];
    while(vec[0]!=0 || vec[1]!=0 || vec[2]!=0 || vec[3]!=0 || vec[4]!=0){
        permutacao(5,0);
        cout<<(ver ? "Possible" : "Impossible")<<endl;
        ver=false;
        cin>>vec[0]>>vec[1]>>vec[2]>>vec[3]>>vec[4];
    }
}
