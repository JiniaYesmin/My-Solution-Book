#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            if(a[i]%2==0)
            {
                a[i]=a[i]/2;
            }
            else
            a[i]=(a[i]/2)-1;
        }
        else
        {
            if(a[i]%2!=0)
            {
                a[i]=(a[i]/2)+1;
            }

            else
            {
                a[i]=a[i]/2;
            }
        }
        s+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

