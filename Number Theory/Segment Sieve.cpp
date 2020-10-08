#include<bits/stdc++.h>
#define kaj_ses return 0
using namespace std;
typedef long long ll;
#define MAX 32000
vector<int>primes;
void sieve()
{
    bool isPrime[MAX+1];
    for(int i=0;i<MAX;i++)
    isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=3;i<=MAX;i += 2)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*i;j<=MAX;j += i)
            {
                isPrime[j]=false;
            }
        }
    }

    primes.push_back(2);
    for( int i=3;i<=MAX;i += 2)
    {
        if(isPrime[i])
        {

            primes.push_back(i);
        }
    }
}
void segSieve(ll l ,ll r)
{
    bool isPrime1[r-l+1];
    for(int i = 0;i<r-l+1;i++)
        isPrime1[i]=true;
    for(int i = 0 ;primes[i]*primes[i]<=r;++i)
    {
        int currentPrime = primes[i];
        ll base = (l/currentPrime)*currentPrime;
        if(base<l)
        {
           base += currentPrime;
        }
        for(ll j=base;j<=r;j += currentPrime)
        {
            isPrime1[j-l] = false;
        }
        if(base==currentPrime)
            isPrime1[base-l]=true;
    }
    for(ll i=0;i<r-l+1;++i)
    {
        if(isPrime1[i])
            cout<<i+l<<' ';
    }
}



int main()
{
    int t;
    cout<<"Enter Time"<<endl;
    cin>>t;
     sieve();
    while(t--)
    {
        ll L,R;
        cout<<"Enter Range"<<endl;
        cin>>L>>R;
        segSieve(L,R);
    }
kaj_ses;




}
