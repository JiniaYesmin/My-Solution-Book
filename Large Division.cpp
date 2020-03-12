#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=1;
    cin>>t;
    while(t--)
    {
        string str;
        long long int m,a;
        cin>>str>>m;

        if(str[0]=='-')
        {
            a=1;
        }
        else
        {
            a=0;
        }
        if(m<0)
        {
            m*=-1;
        }
        long long int len=str.size(),res=0;
        for(int i=a;i<len;i++)
        {
            res=((res*10)+(str[i]-'0'))%m;
        }


        if(res)
        {
            cout<< "Case " <<c<< ": " << "not divisible"<<endl;
        }
        else
        {
            cout<<"Case " <<c<< ": " << "divisible"<<endl;
        }
        c++;
    }
    return 0;
}
