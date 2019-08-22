#include<bits/stdc++.h>
using namespace std;

class task{
	public:
		int id,at,bt,rbt,ct;
		bool isScheduled;
		
		task(int id,int at,int bt,int ct=0,int isScheduled=false)
		{
			this->id=id;
			this->at=at;
			this->bt=bt;
			this->rbt=bt;
			
		}
};


int main()
{
	int n;
	cout<<"Enter number of tasks: "<<endl;
	cin>>n;
	
	vector<task> t;
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"Enter arrival time and burst time: "<<endl;
		int arrt,bst;
		cin>>arrt>>bst;
		t.push_back(task(i,arrt,bst));
		
	}
	
	int timeq;
	cout<<"Enter time quantum: "<<endl;
	cin>>timeq;
	int time=0;
	
	queue<task> q;
	
	for(i=0;i<n;i++)
	{
		cout<<"id: "<<t[i].id<<endl;
		if(t[i].at==0)
		{
			t[i].isScheduled=true;
			q.push(t[i]);	
		}

	}
	
	while(!q.empty())
	{
		task curr=q.front();
		q.pop();
		time+=min(curr.rbt,timeq);
		
		for(int j=0;j<t.size();j++)
		{
			if(t[j].at<=time&&t[j].isScheduled==false)
			{
				
				t[j].isScheduled=true;
				q.push(t[j]);
			}
		}
		
		
		if(curr.rbt<=timeq)
		{
//			if(curr.rbt==timeq)
//			{
//				time+=timeq;
//			}
//			else
//			time+=(curr.rbt);
			
			t[curr.id].ct=time;
			cout<<"task "<<curr.id<<" completed at "<<time<<endl;
		}
		else
		{
//			time+=timeq;
			curr.rbt-=timeq;
			q.push(curr);
		}
		
		
		
		
		
	}
	
	cout<<"ID\t|arrival time|Burst time|Completion Time|Turnaround time|Waiting time"<<endl;
	double avgWaiting=0.0;
	for(i=0;i<n;i++)
	{
		avgWaiting+=t[i].ct-t[i].at-t[i].bt;
		cout<<i<<"|\t"<<t[i].at<<"\t|\t"<<t[i].bt<<"\t|\t"<<t[i].ct<<"\t|\t"<<t[i].ct-t[i].at<<"\t|\t"<<t[i].ct-t[i].at-t[i].bt<<endl;
	}
	
	cout<<"Avg waiting time : "<<avgWaiting;
	
	return 0;
}
