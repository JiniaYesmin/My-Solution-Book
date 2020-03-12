#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,x,y,r;
    while(cin>>n>>q)
    {
        if(n==0 && q==0)
        {
            return 0;
        }
        vector<pair<int,int> >p;
        vector<double>v1;
        int m=n;

        while(m--)
        {
            cin>>x>>y;
            p.push_back(make_pair(x,y));
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                double a=((p[i].first-p[j].first)*(p[i].first-p[j].first))+((p[i].second-p[j].second)*(p[i].second-p[j].second));
                a=sqrt(a);
                v1.push_back(a);
            }
        }

        sort(v1.begin(),v1.end());


    //    for(int i=0;i<v1.size();i++)
    //    {
    //        cout<<v1[i]<< " ";
    //    }
    //    cout<<endl;

        while(q--)
        {
            vector<double>::iterator a;
            cin>>r;
            a=upper_bound(v1.begin(),v1.end(),r);
            int b=a-v1.begin();
            printf("%.2f\n",((double)b/(double)n));
        }
        cout<<endl;
    }
    return 0;
}
