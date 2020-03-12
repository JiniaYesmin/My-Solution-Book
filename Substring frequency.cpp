#include<bits/stdc++.h>
using namespace std;
int Z[2000006];
void getZarr(string str);
int search(string text, string pattern)
{
    string concat = pattern + "$" + text;
    int l = concat.length();

    int c=0;
    getZarr(concat);
    for (int i = 0; i < l; ++i)
    {
        if (Z[i] == pattern.length())
            c++;
    }
    return c;
}
void getZarr(string str)
{
    int n = str.length();
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}
int main()
{
    int t,c=1;
    cin>>t;
    string text,pattern;
    while(t--)
    {
        memset(Z,0,sizeof(Z));
        int cnt=0;
        cin>>text>>pattern;
        if(pattern.size()==1)
        {
            for(int i=0;i<text.size();i++)
            {
                if(text[i]==pattern[0])
                {
                    cnt++;
                }
            }
            cout<<"Case "<<c<< ": " <<cnt<<endl;
        }
        else
        cout<<"Case "<<c<< ": " <<search(text, pattern)<<endl;
        c++;
    }

    return 0;
}
