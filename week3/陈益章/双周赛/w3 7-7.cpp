 #include<iostream>
using namespace std;
long long n,a[1000000],b[1000000];
long long  cnt=0;
void f(int L,int R)
{
    if(L==R) return;
    int m=(L+R)/2;
    int k1=L,k2=m+1,k=L;
    f(L,m);
    f(m+1,R);
    while(k1<=m&&k2<=R)
    {
        if(a[k1]<=a[k2])
        {
            b[k]=a[k1];
            k++,k1++;
        }
        else{
            b[k]=a[k2];
            k++,k2++;
            cnt=cnt+m-k1+1;
        }
    }
    while(k1<=m)
    {
         b[k]=a[k1];
         k++,k1++;
    }
    while(k2<=R)
    {
         b[k]=a[k2];
         k++,k2++;
    }
    for(int i=L;i<=R;i++)
        a[i]=b[i];
}
int main()
{
    int i ;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    f(1,n);
    cout<<cnt;
}
