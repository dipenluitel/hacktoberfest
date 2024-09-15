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
    ll n;
    cin>>n;
    vector<ll> dp(n+1,mod);
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        ll x=i;
        while(x!=0){
            ll a=x%10;
            x=x/10;
            dp[i]=min(dp[i],dp[i-a]+1);
        }
    }
    cout<<dp[n]<<endl;
    return ;
}

int main()
{
    solve();
    return 0;
}