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

int bs(int l, int r, int *vet, int valor){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(vet[mid]>=valor) return bs(l,mid,vet,valor);
    return bs(mid+1,r,vet,valor);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,q,x,v=1; cin>>n>>q;
    while(n!=0 || q!=0){
        int vet[n];
        for(int i=0; i<n; i++){
            cin>>vet[i];
        }
        sort(vet,vet+n);
        cout<<"CASE# "<<v++<<":"<<endl;
        for(int i=0; i<q; i++){
            cin>>x;
            int index=bs(0,n-1,vet,x);
            if(vet[index]!=x){
                cout<<x<<" not found"<<endl;
            }
            else{
                cout<<x<<" found at "<<index+1<<endl;  
            }
        }
        cin>>n>>q;
    }
}
