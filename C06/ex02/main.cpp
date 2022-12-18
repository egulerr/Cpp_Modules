#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int num;

	srand(time(0));
	num = rand() % 3;
	if (num == 0) {
		Base *base = new A;
		return (base);
	} else if (num == 1) {
		Base *base = new B;
		return (base);
	} else {
		Base *base = new C;
		return (base);
	}
}

void identify(Base *p){
	if(dynamic_cast<A*>(p))
		cout << "Type A with pointer" << endl;
	else if(dynamic_cast<B*>(p))
		cout << "Type B with pointer" << endl;
	else
		cout << "Type C with pointer" << endl;
}

void identify(Base &p){
	{//dynamic cast 'A'
		try{
			A x = dynamic_cast<A&>(p);
			cout << "Type A with ref" << endl;
		} catch (std::exception &ex){}
	}
	{//dynamic cast 'B'
		try{
			B x = dynamic_cast<B&>(p);
			cout << "Type B with ref" << endl;
		} catch (std::exception &ex){}
	}
	{//dynamic cast 'C'
		try{
			C x = dynamic_cast<C&>(p);
			cout << "Type C with ref" << endl;
		} catch (std::exception &ex){}
	}
}

int main(){
	Base *base;
	Base *b;

	base = generate();
	identify(base);

	b = generate();
	identify(*b);
}
