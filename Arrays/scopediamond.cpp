#include<iostream>
using namespace std;

class A
{	
public:
	void AA()
	{
		cout<<"hello";
	}
};

class B:public A
{	
public:
	void BB()
	{
		cout<<"hi";
	}
};

class C:public B
{
	public:
	void BB()
	{
		cout<<"hey";
	}
};

class D: public B, public C
{
public:  // Must be public to access DD() from main
	void DD()
	{
		cout<<"yo";
	}
};

int main()
{
	D d1;
	
	// ORIGINAL LINE THAT CAUSES ERROR:
	// d1.AA();  // ERROR! Ambiguous - compiler doesn't know which A::AA() to use
	
	// SOLUTION 1: Use scope resolution to specify the path
	cout << "Using scope resolution:" << endl;
	d1.B::AA();  // Call AA() through B's path (prints "hello")
	cout << endl;
	d1.C::AA();  // Call AA() through C's path (C->B->A) (prints "hello") 
	cout << endl;
	
	// SOLUTION 2: Access other methods without ambiguity
	d1.B::BB();  // Call B's BB() (prints "hi")
	cout << endl;
	d1.C::BB();  // Call C's BB() (prints "hey")  
	cout << endl;
	d1.DD();     // Call D's DD() (prints "yo")
	cout << endl;
	
	return 0;
}

/*
ERROR EXPLANATION:
==================

Your compiler errors mean:

1. "[Warning] direct base 'B' inaccessible in 'D' due to ambiguity"
   - D inherits B directly AND through C (C inherits from B)
   - This creates ambiguity about which B to use

2. "[Error] 'B' is an ambiguous base of 'D'" 
   - Same issue - two paths to reach class B

3. The line d1.AA() fails because:
   - There are TWO copies of class A in object d1
   - One from D->B->A  
   - One from D->C->B->A
   - Compiler can't decide which one to use

SOLUTION:
=========
Use scope resolution (::) to tell compiler exactly which path to take:
- d1.B::AA() means "use A's AA() method via the B path"
- d1.C::AA() means "use A's AA() method via the C->B path"

This resolves the ambiguity and your code will compile and run!
*/
