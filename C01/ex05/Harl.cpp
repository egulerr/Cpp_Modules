#include "Harl.hpp"

void Harl::debug() {
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n";
}

void Harl::info() {
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error() {
	cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level){
	void	(Harl::*p[4]) () = {&Harl::debug, &Harl::info,
								&Harl::warning, &Harl::error };
	(level == "debug") ? (this->*p[0])(): (void)p[0];
	(level == "info") ? (this->*p[1])(): (void)p[1];
	(level == "warning") ? (this->*p[2])(): (void)p[2];
	(level == "error") ? (this->*p[3])(): (void)p[3];
}