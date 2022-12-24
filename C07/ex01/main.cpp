#include "iter.hpp"

int main(){
	char a[] = "EYUP";
	::iter(a, strlen(a), fun);
	cout << a << endl;
	int b[] = {1, 2, 3};
	::iter(b, 3, fun);
	int i = 0;
	while (i < 3)
		cout << b[i++];
}