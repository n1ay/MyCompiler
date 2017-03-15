/*
 * shuntingyard.hpp
 *
 *  Created on: 15.03.2017
 *      Author: kamil
 */

#ifndef SHUNTINGYARD_HPP_
#define SHUNTINGYARD_HPP_

#include <stack>
#include <ctype.h>
#include <iostream>

std::string toPostfix(std::string infix);
double calculate(std::string postfix);


#endif /* SHUNTINGYARD_HPP_ */
