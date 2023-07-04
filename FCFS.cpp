#include<iostream>
using namespace std;
using namespace std;
int main()
{
    int n;
    cout<<"Enter the jobs you want to perform : ";
    cin>>n;
    int a_time[n],b_time[n],i;
    for(i=0;i<n;i++)
    {
        cout<<"Enter Arrival Time for job "<<i+1<<"  : ";
        cin>>a_time[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<"Enter Burst Time for job "<<i+1<<"  : ";
        cin>>b_time[i];
    }
    int Sum=0,S[n];
    int w_time[n],t_time[n];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        if(a_time[i]>a_time[j])
        {
            swap(a_time[i],a_time[j]);
            swap(b_time[i],b_time[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        Sum=Sum+b_time[i];
        S[i]=Sum;
    }
    float total=0;
    for(int i=0;i<n;i++)
    {
        t_time[i] = S[i]- a_time[i];
        total=total+t_time[i];
    }
    cout<<"AVERAGE TURN AROUND TIME WILL BE : "<<(total/n)<<endl;

    float total1=0;
    for(int i=0;i<n;i++)
    {
        w_time[i] = t_time[i]-b_time[i];
        total1=total1+w_time[i];
    }
    cout<<"AVERAGE WAITING TIME WILL BE : "<<(total1/n)<<endl;

}

