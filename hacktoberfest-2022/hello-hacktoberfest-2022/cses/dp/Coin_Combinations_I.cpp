/* ____                       _  __                     _       _       _       
  |  _ \ _ __ ___ _ __ ___   | |/ /__ _ _ __ ___   __ _| |     | | __ _(_)_ __  
  | |_) | '__/ _ \ '_ ` _ \  | ' // _` | '_ ` _ \ / _` | |  _  | |/ _` | | '_ \ 
  |  __/| | |  __/ | | | | | | . \ (_| | | | | | | (_| | | | |_| | (_| | | | | |
  |_|   |_|  \___|_| |_| |_| |_|\_\__,_|_| |_| |_|\__,_|_|  \___/ \__,_|_|_| |_|
*/                                                                            

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(x); cout<<#x<<" "<<x<<endl;
ll mod=1e9+7;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> dp(k+1,0);
    dp[0]=1;
    for(ll i=1;i<=k;i++){
        for(ll j=0;j<n;j++){
            if(i>=v[j]){
                dp[i]+=dp[i-v[j]];
                dp[i]=dp[i]%int(1e9+7);
            }
        }
    }
    cout<<dp[k]<<endl;
    return ;
}

int main()
{
    int t;
    t=1;
    while(t--)
        solve();
    return 0;
}