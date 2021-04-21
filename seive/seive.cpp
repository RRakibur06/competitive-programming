
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,i,x,j;

    cin>>n;
    bool a[n+1] = {0};
    x = sqrt(n);
    for(i=3;i<=x;i+=2){
      if(a[i]==0)
        for(j=i*i;j<=n;j+=2*i){
                a[j] = 1;
        }
    }
    cout<<"2 ";
    for(i=3;i<=n;i+=2){
        if(a[i]==0)
            cout<<i<<" ";
    }

}

