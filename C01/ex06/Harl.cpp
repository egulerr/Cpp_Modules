#include "Harl.hpp"

void Harl::debug() {
	cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\nI really do!\n\n";
}

void Harl::info() {
	cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning() {
	cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error() {
	cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level){
	void	(Harl::*p[4]) () = {&Harl::debug, &Harl::info,
								&Harl::warning, &Harl::error };
	(level == "DEBUG") ? (this->*p[0])(): (void)p[0];
	(level == "INFO") ? (this->*p[1])(): (void)p[1];
	(level == "WARNING") ? (this->*p[2])(): (void)p[2];
	(level == "ERROR") ? (this->*p[3])(): (void)p[3];
}