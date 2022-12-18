#include "serialization.hpp"

uintptr_t serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(){
	Data *data = new Data;
	Data *x = new Data;
	uintptr_t num;

	data->raw = 5;
	data->data = 'a';

	num = serialize(data);
	x = deserialize(num);

	cout << x->raw << endl;
	cout << x->data << endl;
}