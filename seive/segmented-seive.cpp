#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 32000
vector <int> primes;
void seive()
{
    ll i,j;
    bool a[max+1] = {0};

    for(i=3;i<=max;i+=2){
        if(a[i]==0)
        for(j=i*i;j<=max;j+=2*i){
            a[j] = 1;
        }
    }
    primes.push_back(2);
    for(i=3;i<=max;i+=2){
        if(!a[i])
            primes.push_back(i);
    }
}
void segseive(ll l, ll r)
{
    seive();
    ll i,j,x,y;
    bool a[r-l+1] = {0};
    y = sqrt(r);
    for(i=0;i<primes.size();i++){
        if(primes[i]>y) break;
        x = (l/primes[i]) * primes[i];
        if(l%primes[i]!=0) x += primes[i];
        for(j=x;j<=r;j+=primes[i]){
            a[j-l] = 1;
        }
        if(l==1) primes[0] = 1;
        if(x==primes[i]) a[x-l] = 0;
    }
    for(i=0;i<(r-l+1);i++){
        if(!a[i]) cout<<l+i<<" ";
    }
}
int main()
{
    ll l,r;

    cin>>l>>r;
    segseive(l,r);
}
