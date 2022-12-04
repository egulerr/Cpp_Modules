#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat eyup("eyup", 12);
		std::cout << eyup << std::endl;
	} catch (const std::exception &a){
		std::cout << a.what() << std::endl;
	}
	//Bureaucrat eyup("eyup", 151);


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
		Bureaucrat eyup("eyup", 2);
		std::cout << eyup << std::endl;
	} catch (const std::exception &a){
		std::cout << a.what() << std::endl;
	}
}