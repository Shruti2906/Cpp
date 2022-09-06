#include <iostream>

//public inheritance
using namespace std;

class A{
	private:
		int x = 10;
	public:
		int y = 20;
	public:
		int z = 30;

};

class B:public A{
	//as B is publically inheriting A, protected members of A become protected in B,
	//and public members of A become also protected in B,
	public:
		void display(){
			cout<<"\nin B, y : "<<y;
			cout<<"\nin B, z : "<<z;
		}
}; 
class C:public B{
	
	public:
		void display(){
			B::display();
		//y and z are now protected and public in B res.	
			
			cout<<"\nin C, y : "<<y;
			cout<<"\nin C, z : "<<z;
		}	
};

//NOTE : above concepts applies to class B and its subclasses( or any class related to B) 
		//as B is publically inheriting A, but does not affect anywhere else e.g below class.
		
class D:public A{
	
	public:
		void display(){
			
			cout<<"\nin D, y : "<<y;
			cout<<"\nin D, z : "<<z;
		}
};
int main() {
	
	C c;
	c.display();

//	bolow statement is invalid
//	cout<<"c.y : "<<c.y;
	cout<<"\nin Main c.y : "<<c.z;//this is valid
	
	D d;
	d.display();
	
	return 0;
}
