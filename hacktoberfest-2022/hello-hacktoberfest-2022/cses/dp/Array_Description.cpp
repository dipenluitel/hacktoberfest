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
ll hell=1e9+7;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<ll>> dp(n,vector<ll>(m+1,0));
    
    //base case
    if(arr[0]==0){
        for(ll i=1;i<=m;i++){
            dp[0][i]=1;
        }
    }
    else {
        for(ll i=1;i<=m;i++){
            if(i==arr[0]){
                dp[0][i]=1;
            }
            else {
                dp[0][i]=0;
            }
        }
    }

    // transition 
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=m;j++){
            if(arr[i]==0){
                if(j==m){
                    dp[i][j]=(dp[i-1][j-1])%hell+(dp[i-1][j])%hell;
                    dp[i][j]%=hell;
                }
                else {
                    dp[i][j]=(dp[i-1][j-1])%hell+(dp[i-1][j])%hell+(dp[i-1][j+1])%hell;
                    dp[i][j]%=hell;
                }
            }
            else {
                if(j==arr[i]){
                    dp[i][j]=(dp[i-1][j-1])%hell+(dp[i-1][j])%hell+(((j+1)<=m)*(dp[i-1][j+1]))%hell;
                    dp[i][j]%=hell;
                }
            }
        }
    }

    ll ans=0;
    for(ll i=1;i<=m;i++){
        ans+=dp[n-1][i]%hell;
    }
    ans%=hell;
    cout<<ans<<endl;
    return 0;
}