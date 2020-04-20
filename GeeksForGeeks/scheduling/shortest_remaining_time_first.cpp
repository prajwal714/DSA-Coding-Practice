#include<bits/stdc++.h>
using namespace std;

class task{
	public:
	int id,bt,at,rbt,ct;
	bool isScheduled;
	
	task(int id,int at,int bt)
	{
		
		this->id=id;
		this->bt=bt;
		this->at=at;
		this->rbt=bt;
		this->isScheduled=false;
		this->ct=0;
	}
	
};

class compare{
	public:
	bool operator()(task t1,task t2)
	{
		return t1.rbt>t2.rbt;
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
	int time=0;
	
	priority_queue<task, vector<task>, compare>pq;
	
	//push the initial elements with arrival time 0
	for(i=0;i<n;i++)
	{
		cout<<"id: "<<t[i].id<<endl;
		if(t[i].at==0)
		{
			t[i].isScheduled=true;
			pq.push(t[i]);	
		}

	}
	

	while(!pq.empty())
	{
		time++;
		
		//pop the task with shortest remaining time
		task curr=pq.top();
		pq.pop();
		//reduce its remaining burst time by 1
		curr.rbt--;
		cout<<"Id: "<<curr.id<<" Remaining time: "<<curr.rbt<<endl;
		
		//if curr job is done, assign completion time to it and print job done.
		if(curr.rbt==0)
		{
			t[curr.id].ct=time;
			cout<<t[curr.id].id<<" job done"<<endl;
		}
		else
		{
			//else push back the curr job with reduced remaining burst time
			pq.push(curr);
		}
		
		//push more jobs if arrival time < curr time
		for(i=0;i<t.size();i++)
		{
			if(t[i].at<=time&&t[i].isScheduled==false)
			{
				t[i].isScheduled=true;
				pq.push(t[i]);		
			}
		}
		
		
	}
	double avgWaiting=0.0;
	for(i=0;i<n;i++)
	{
		avgWaiting+=t[i].ct-t[i].at-t[i].bt;
		cout<<"\t"<<i<<"|\t"<<t[i].at<<"\t|\t"<<t[i].bt<<"\t|\t"<<t[i].ct<<"\t|\t"<<t[i].ct-t[i].at<<"\t|\t"<<t[i].ct-t[i].at-t[i].bt<<endl;
	}
	
	cout<<"Avg waiting time : "<<avgWaiting/n;
	return 0;
}
