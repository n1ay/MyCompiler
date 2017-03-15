/*
 * AppMain.cpp
 *
 *  Created on: 15.03.2017
 *      Author: kamil
 */

#include <iostream>
#include "shuntingyard.hpp"

int main() {

	std::string expression = "1-2-3";

	std::cout<<toPostfix(expression)<<std::endl;
	std::cout<<calculate(toPostfix(expression))<<std::endl;
	return 0;
}


