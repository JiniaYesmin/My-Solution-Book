#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,cnt=1;
    cin>>n>>x;
    long long int f=0,l=n,m;
    while(f<=l)
    {
            m=(f+l)/2;
        if(m==x)
        {
            cout<<cnt<<endl;
            break;
        }
        else if(m<x)
        {
            f=m+1;
            cnt++;
        }
        else
        {
            l=m-1;
            cnt++;
        }
    }
    return 0;
}
