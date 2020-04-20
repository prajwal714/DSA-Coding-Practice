#include<bits/stdc++.h>
using namespace std;

class A{
	public:
		static int x;
		
		A()
		{
			cout<<"Constructor"<<endl;
		}
		~A()
		{
			cout<<"Destructor"<<endl;
		}
		
		void* operator new(size_t sz)
		{
			x++;
		}
		
		void operator delete(void*)
		{
			x--;
		}
		
};

int A::x=0;

int main()
{
	A a,b,c;
	A *d=new A;
	A *e=new A;
	delete d;
	cout<<A::x<<endl;
	return 0;
}
