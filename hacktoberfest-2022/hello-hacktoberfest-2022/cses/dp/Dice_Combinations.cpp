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
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
                dp[i]=dp[i]%mod;
            }
        }
    }
    cout<<dp[n]<<endl;
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