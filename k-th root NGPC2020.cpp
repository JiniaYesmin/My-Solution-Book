#include<bits/stdc++.h>
using namespace std;
int num = 1009;
bool check[1009];
vector <int> v;

void sieve()
{
    v.push_back(2);

    int i,j;

    check[0] = check[1] = true;

    for (i=4; i<=num; i+=2)
        check[i] = true;

    for (i=3; i*i<=num; i+=2)
        if (check[i] == false)
            for (j=i*i; j<num; j+=2*i)
                check[j] = true;

    for (i=3; i<num; i+=2)
        if (check[i] == false)
            v.push_back(i);
}

long long generatePrimeFactors(int N)
{
    long long gc = 0;
	int i,cnt=0;
	for(i=0;i<v.size();i++)
    {
        while(N%v[i]==0)
        {
            //cout<<N<<endl;
            N/=v[i];
            cnt++;
        }
        if(cnt)
        {
            gc = __gcd(gc,(long long)cnt);
        }

        cnt = 0;
    }
    if(N>1)
        return 1;
    else
    return gc;
}
int main()
{
    sieve();
    int t,c=1,kase;
    scanf("%d", &t);
    for(kase=1;kase<=t; kase++)
    {
        long long a,b,gc=0,ans=0;
        scanf("%lld %lld", &a, &b);
        gc = generatePrimeFactors(a);

        printf("Case #%d: %lld\n",kase,gc*b);

    }

	return 0;
}
