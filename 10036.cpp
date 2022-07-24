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

int nums[10000], dp[10000][100];
bool f(int n, int x, int k, int resto){
    if(n==x){
        if(resto==0){
            return true;
        }
        return false;
    }
    if(dp[x][resto]!=-1) return dp[x][resto];
    int soma=f(n,x+1,k,(nums[x]+resto)%k);
    int subtracao=f(n,x+1,k,(nums[x]-resto)%k);
    if(soma!=0 || subtracao!=0){
        return dp[x][resto]=true;
    }
    return dp[x][resto]=false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,x,k; cin>>t;
    while(t--){
        cin>>x>>k;
        for(int i=0; i<x; i++){
            cin>>nums[i];
        }
        for(int i=0; i<10000; i++){
            for(int j=0; j<100; j++){
                dp[i][j]=-1;
            }
        }
        cout<<(f(x,1,k,nums[0]%k) ? "Divisible" : "Not divisible")<<endl;
    }
}
