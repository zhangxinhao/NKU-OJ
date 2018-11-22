#include<iostream>
#include<iomanip>
using namespace std;
int sum=0;
int k,t=0,j=0,i;
int main()
{
    int ss[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    cin>>k;
    for(i=0;i<=11;i++)
        sum=sum+ss[i];
    while(sum!=0)
    {
        do
        {
            if(ss[j]!=0)t++;
            if(t==k)ss[j]=0;
            j++;
            if(j!=11)
                j=(j+1)%12-1;
        }
        while(t<k);
        t=0;
        sum=0;
        for(i=0;i<=11;i++)
            sum=sum+ss[i];
        if(sum!=0)
        {
            for(i=0;i<=11;i++)
            {
                cout<<setw(3)<<ss[i];
            }
            cout<<endl;
            
        }
        
    }
    if(j==0)j=12;
    cout<<setw(3)<<j;
    return 0;
    
    
    
}