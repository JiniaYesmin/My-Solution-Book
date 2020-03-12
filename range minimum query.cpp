#include <bits/stdc++.h>

using namespace std;
int blk;

struct Query
{
    int L,R,idx,ans;
};

bool comp(Query a, Query b)
{
    if(a.L/blk != b.L/blk)
        return a.L<b.L;
    else
        return a.R < b.R;
}
bool comp2(Query a, Query b)
{
    return a.idx<b.idx;
}

int main()
{
    int n,q;
    cin>>n;
    set <int> st;
    blk = (int)sqrt(n);
    vector <int> v(n);

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    cin>>q;
    vector <Query> qq(q);
    for(int i=0; i<q; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        qq[i].L = x;
        qq[i].R = y;
        qq[i].idx = i;
    }
    sort(qq.begin(), qq.end(), comp);
    map <int,int> freq;
    int cL = 0, cR = 0, L = 0, R = 0;
    for(int i=0; i<q; i++)
    {
        L = qq[i].L;
        R = qq[i].R;
 //       cout<<L<<" "<<R<<endl;
        while(cL<L)
        {
            //if(freq[v[cL]]>0)
                freq[v[cL]]--;
            if(freq[v[cL]]<=0)
                st.erase(v[cL]);
            cL++;
        }
        while(cL>L)
        {
            //if(freq[v[cL]]>=0)
                freq[v[cL]]++;
            if(freq[v[cL]]>0)
                st.insert(v[cL]);
            cL--;
        }
        while(cR-1>R)
        {
            //if(freq[v[cR]]>0)
                freq[v[cR]]--;
            if(freq[v[cR]]<=0)
                st.erase(v[cR]);
            cR--;
        }
        while(cR<=R)
        {
            //if(freq[v[cR]]>=0)
                freq[v[cR]]++;
            if(freq[v[cR]]>0)
                st.insert(v[cR]);
            cR++;
        }
        qq[i].ans = *st.begin();

    }
    sort(qq.begin(),qq.end(),comp2);
    for(int i=0; i<q; i++)
    {
        cout<<qq[i].ans<<endl;
    }


}
