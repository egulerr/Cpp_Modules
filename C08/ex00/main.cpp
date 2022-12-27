#include "easyfind.hpp"

int main()
{
	int a[11] = {5,2,7,123,32,9,54,89,21,11,98};
	std::vector<int> b(a, a + 11);
	easyfind(b,11);
}