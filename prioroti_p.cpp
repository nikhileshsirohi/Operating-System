//alright

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef struct proccess
{
	int at,bt,ct,ta,wt,btt,pr;
	string pro_id;
}schedule;
bool compare(schedule a,schedule b)
{
	return a.at<b.at;
}

bool compare2(schedule a,schedule b)
{
	return a.pr>b.pr;
}
int main()
{
	schedule pro[10];
	int n,i,j,pcom;
	cout<<"Enter the number of process::";
	cin>>n;
	cout<<"Enter the Process id arrival time burst time and priority :::";
	for(i=0;i<n;i++)
	{
		cin>>pro[i].pro_id;
		cin>>pro[i].at;
		cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
		cin>>pro[i].pr;
	}
	sort(pro,pro+n,compare);
	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}
		sort(pro,pro+j,compare2);
		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)
			i+=pro[j].at-i;
			pro[j].ct=i+1;
			pro[j].bt--;
		}
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}
	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].btt;
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].btt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		cout<<endl;
	}
	float t=0,t1=0;
	for(i = 0;i<n;i++)
    {
        t=t+pro[i].ta;
        t1=t1+pro[i].wt;
    }
    cout<<"TOTAL AVERGE TURN AROUND TIME IS : "<< t/n <<endl;
    cout<<"TOTAL AVERGE WATING TIME IS : "<< t1/n <<endl;
	return 0;
}
