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

vector<int>vec(100005),seg(4*100005);
void build(int l, int r, int i){
    if(l==r){
        seg[i]=vec[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*i+1);
    build(mid+1,r,2*i+2);
    seg[i]=seg[2*i+1]*seg[2*i+2];
}
void update(int l, int r, int pos, int valor, int i){
    if(r<pos || pos<l) return;
    if(l==r){
        seg[i]=valor;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,pos,valor,2*i+1);
    update(mid+1,r,pos,valor,2*i+2);
    seg[i]=seg[2*i+1]*seg[2*i+2];
}
int query(int l, int r, int ql, int qr, int i){
    if(l>qr || r<ql) return 1;
    if(ql<=l && r<=qr) return seg[i];  
    int mid=(l+r)/2;
    int qL=query(l,mid,ql,qr,2*i+1);
    int qR=query(mid+1,r,ql,qr,2*i+2);
    return qL*qR;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,q;
    while(cin>>n>>q){
        for(int i=0; i<n; i++){
            int v; cin>>v;
            if(v>0){
                vec[i]=1;
            }
            else{
                if(v<0){
                    vec[i]=-1;
                }
                else{
                    vec[i]=0;
                }
            }
        }
        build(0,n-1,0);
        string ans="";
        for(int i=0; i<q; i++){
            char o; cin>>o;
            if(o=='C'){
                int index,valor; cin>>index>>valor;
                if(valor>0){
                    valor=1;
                }
                else{
                    if(valor<0){
                        valor=-1;
                    }
                    else{
                        valor=0;
                    }
                }
                update(0,n-1,index-1,valor,0);
            }
            else{
                int ql,qr; cin>>ql>>qr;
                int resultado=query(0,n-1,ql-1,qr-1,0);
                if(resultado>0){
                    ans+='+';
                }
                else{
                    if(resultado<0){
                        ans+='-';
                    }
                    else{
                        ans+='0';
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
