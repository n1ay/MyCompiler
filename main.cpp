/*
 * AppMain.cpp
 *
 *  Created on: 15.03.2017
 *      Author: kamil
 */

#include <iostream>
#include "shuntingyard.hpp"

int main() {

	std::string expression = "(21-20)*2";

	std::cout<<toPostfix(expression)<<std::endl;
	std::cout<<calculate(toPostfix(expression))<<std::endl;
	return 0;
}


