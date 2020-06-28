#include<bits/stdc++.h>
using namespace std;
void sieve(int n)
{
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    prime[2]=true;
    for(int i=3;i*i<=n;i += 2)
    {
        if(prime[i]==true)
        {
            for( int j=i*i ; j<= n;j += i)
            {
                prime[j] =false;
            }
        }
    }
    cout<<2<<endl;
    for(int i=3;i<=n;i+=2)
    {
        if(prime[i]==true)
        {
            cout<<i<<endl;
        }
    }

}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    cin>>n;
    sieve(100);


}
