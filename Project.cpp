#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int max_arrival=-1,min_arrival=INT_MAX;
struct Processes
{
    long pid=0;                                       
    long priority=0;                                  
    long arrival_time=0; 
    long remaining_time=0;                             
	long service_time=0;                                
    long completion_time=0;                                           
};
bool comparison_RemainingTime(Processes a,Processes b)
{
    return (a.remaining_time < b.remaining_time);
}
int EnterProcess(Processes p[],int n)
{
    cout<<"\n";
    int pid=1;
    for(int i=0;i<n;i++)
    {
        p[i].priority=0;
        cout<<"\tFOR PROCESS:"<<i+1<<endl;
        p[i].pid=pid;
        cout<<"\tEnter Arrival Time:";
        cin>>p[i].arrival_time;
        if(p[i].arrival_time<min_arrival)
        {
            min_arrival=p[i].arrival_time;
        }
        if(p[i].arrival_time>max_arrival)
        {
            max_arrival=p[i].arrival_time;          
        }
        cout<<"\tEnter Service Time:";
        cin>>p[i].service_time;
        p[i].remaining_time=p[i].service_time;
        cout<<endl;
        pid++;
    }
    return 0;
}
int ShowProcess(Processes p[],int n)
{
    cout<<"\nPID || Priority || Arrival Time || Service Time|| Completetion Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].priority<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].service_time<<"\t\t"<<p[i].completion_time<<"\n";
    }  
    return 0; 
}
int Scheduling(Processes p[],int n)
{
    vector<Processes> ready_queue;
    int time=min_arrival,flag=0,flag1=0;
    bool complete=false;
    while(complete==false)
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].remaining_time==0)
            {
                flag=0;
                continue;
            }
            else
            {
                flag=1;
                break;
            } 
        }
        if(flag==0)
        {
            complete==true;
            break;
        }
        sort(p,p+n,comparison_RemainingTime);
        flag1=0;
        for(int i=0;i<n;i++)
        {
            if(p[i].remaining_time<=time && p[i].remaining_time>0)
            {
                p[i].remaining_time--;
                time++;
                if(p[i].remaining_time==0)
                {
                    p[i].completion_time=time;
                }
                flag1=1;
            }
            time++;
            if(flag1==1)
            {
                p[i].priority++;
                break;
            }
        }
    }
    return 0;
}
int main()
{
    int n,time=0;
    cout<<"Enter No Of Processes:";
    cin>>n;
    Processes p[n];
    EnterProcess(p,n);
    Scheduling(p,n);
    ShowProcess(p,n);
    system("pause");
    return 0;
}