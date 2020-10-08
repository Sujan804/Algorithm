#include<bits/stdc++.h>
#define kaj_ses return 0
using namespace std;
void factors(long long int fact[],long long int n)
{
    long long int i,j=0;
    for(i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            fact[j++]=i;
            if(i!=sqrt(n))
                fact[j++]=n/i;
        }
    }
    sort(fact,fact+j);
    for(i=0;i<j;++i)
        cout<<fact[i]<<' ';
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n,array[1000];
    cin>>n;
    factors(array,n);
}
