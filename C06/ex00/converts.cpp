#include "converts.hpp"

void all_converts(float input) {
	{ //char convert
		if (input >= 0 && input < 32)
			cout << "char: " << "Non displayable" << endl;
		else if (input < 0 || input > 126 || isnan(input))
			cout << "char: " << "impossible" << endl;
		else {
			char c;
			c = static_cast<char>(input);
			cout << "char: " << c << endl;
		}
	}
	{//int convert
		if (input < -2147483648 || input > 2147483647 || isnan(input))
			cout << "int: impossible" << endl;
		else {
			int num;
			num = static_cast<int>(input);
			cout << "int: " << num << endl;
		}
	}
	{//float convert
		cout << std::fixed;
		cout << "float: " << std::setprecision(1) << input << "f" << endl;
	}
	{//double convert
		double num;
		num = static_cast<double>(input);
		cout << "double: " << num << endl;
	}
}