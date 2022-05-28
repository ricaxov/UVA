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

vector<int>dp(1000001);
int f(int x){
    if(x==0) return 1;
    if(dp[x]!=0) return dp[x];
    return dp[x]=(f(x-sqrt(x))+f(log(x))+f(x*sin(x)*sin(x)))%1000000;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int x; cin>>x;
    while(x!=-1){
        cout<<f(x)<<endl;
        cin>>x;
    }
}
