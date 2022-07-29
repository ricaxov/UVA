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

ii ans;
int bs(int l, int r, int *vet, int valor){
    if(l>=r) return 0;
    if(vet[l]+vet[r]<valor) return bs(l+1,r,vet,valor);
    if(vet[l]+vet[r]>valor) return bs(l,r-1,vet,valor);
    ans={vet[l],vet[r]};
    return bs(l+1,r-1,vet,valor);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    while(cin>>n){
        int vet[n];
        for(int i=0; i<n; i++){
            cin>>vet[i];
        }
        sort(vet, vet+n);
        cin>>m;
        bs(0,n-1,vet,m);
        cout<<"Peter should buy books whose prices are "<<ans.f<<" and "<<ans.s<<"."<<endl<<endl;
    }
}
