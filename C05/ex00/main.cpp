#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat eyup("eyup", 12);
		std::cout << eyup << std::endl;
		eyup.increment();
		cout <<"grade: "<< eyup.getGrade() << endl;
	} catch (const std::exception &a){
		std::cout << a.what() << std::endl;
	}
	try{
		Bureaucrat eyup("eyup", 1);
		std::cout << eyup << std::endl;
	} catch (const std::exception &a){
		std::cout << a.what() << std::endl;
	}
	try{
		Bureaucrat eyup("eyup", -151);
		std::cout << eyup << std::endl;
	} catch (const std::exception &a){
		std::cout << a.what() << std::endl;
	}
	try{
		Bureaucrat eyup("eyup", 999);
		std::cout << eyup << std::endl;
	} catch (const std::exception &a){
		std::cout << a.what() << std::endl;
	}
	try{
		Bureaucrat eyup("eyup", 150);
		std::cout << eyup << std::endl;
	} catch (const std::exception &a){
		std::cout << a.what() << std::endl;
	}
}