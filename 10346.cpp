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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k;
    while(cin>>n>>k){
        int aux,cigs,ans=n;
        while(n>=k){
            cigs=n/k;
            aux=n%k;
            ans+=cigs;
            n=cigs+aux;
        }
        cout<<ans<<endl;
    }
}
