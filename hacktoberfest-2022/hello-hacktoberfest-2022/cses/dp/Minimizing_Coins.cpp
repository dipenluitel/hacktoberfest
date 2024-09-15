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

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> coins(n),dp(k+1,0);
    dp[0]=0;
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }

    for(ll i=1;i<=k;i++){
        ll key=mod;
        for(ll j=0;j<n;j++){
            if(i-coins[j]>=0){
                key=min(key,dp[i-coins[j]]);
            }
        }
        dp[i]=key+1;
        // cout<<"i "<<i<<" ";
        // debug(dp[i]);
    }
    
    if(dp[k]==mod+1){
        cout<<"-1"<<endl;
        return ;
    }
    else {
        cout<<dp[k]<<endl;
    }
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