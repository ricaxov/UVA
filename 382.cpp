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

int divs(int n){
    int sum=0;
    for(int i=1; i<=n/2; i++){
        if(n%i==0){
            sum+=i;
        }
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<int>vec;
    int n; scanf("%d", &n);
    while(n!=0){
        vec.pb(n);
        scanf("%d", &n);
    }
    printf("PERFECTION OUTPUT\n");
    for(int i=0; i<vec.size(); i++){
        printf("%5d  ", vec[i]);
        if(divs(vec[i])==vec[i]){
            printf("PERFECT\n");
        }
        else{
            if(divs(vec[i])>vec[i]){
                printf("ABUNDANT\n");
            }
            else{
                printf("DEFICIENT\n");
            }
        }
    }
    printf("END OF OUTPUT\n");
}
