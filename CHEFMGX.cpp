/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay
  
  
   Question link: https://www.codechef.com/START16B/problems/CHEFMGX
   Problem statement : Chef has a new customer and he wants to prepare his order as soon as possible. While preparing, he sees that the mint sauce is finished. He has to run upstairs to get it from other kitchen. Chef is currently on the Xth stair. He has to climb all the way up to the Yth stair in minimum number of steps. In one step, Chef can do one of the following things:

  Climb a single stair. ( i.e go from the Xth stair to the (X+1)th stair. )
  Climb two stairs only if the final stair falls at a prime number position. ( i.e. go from the Xth stair to the (X+2)th stair, only if (X+2) is a prime number)
  Help Chef reach the Yth stair from the Xth stair in minimum number of steps.
  
  Your input: 
  4
  2 10
  5 12
  34 43
  57 63
  Output: 
  6
  5
  6
  4
  Approach :
    Using seive of erotheses to store all the till the max number step.
    
*/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int>prm(10000001,1);
vector<int>f(10000001,0);

void sieve(){
    prm[0]=0;
    prm[1]=0;
    for(int i=2;i*i<=10000000;i++){
        if(prm[i]){
            for(int j=i*i;j<=10000000;j+=i){
                prm[j]=0;
            }
        }
    }
    for(int i=2;i<=10000000;i++){
        f[i]=f[i-1]+prm[i];
    }
}

void solve(){
    ll x,y;
    cin>>x>>y;
    if(x==1 && y==2){
        cout<<2<<"\n";
        return;
    }
    if(x==1 && y==3){
        cout<<2<<"\n";
        return;
    }
    if(x==2 && y==3){
        cout<<2<<"\n";
        return;
    }
    ll ans=y-x;
    ans = ans-(f[y]-f[x]);
    if(prm[x+1]){
        ans=ans+1;
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
