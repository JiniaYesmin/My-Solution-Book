#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    vector <long long> a(n),b(n),d(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
        d[i] = a[i]-b[i];
    }

    sort(d.begin(), d.end());
    long long x = 0;
    long long c=0;
    for(int i=0; i<n; i++)
    {
        if(d[i]>0)
            c++;
        else
        {
            int pos=upper_bound(d.begin(), d.end(), abs(d[i]))-d.begin();
            x+=(n-pos);
        }
    }
    x+=((c*(c-1))/2);
    cout<<x<<endl;


    return 0;
}
