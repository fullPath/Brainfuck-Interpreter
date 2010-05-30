/*
 * ErrorMsg.cpp
 *
 *  Created on: 29. Mai 2010, 13:31
 *      Author: fullPath
 */

#include <iostream>
#include "ErrorMsg.h"

ErrorMsg::ErrorMsg() {
}

ErrorMsg::~ErrorMsg() {
}

void ErrorMsg::print(const std::string& msg)
{
    std::cerr << "#####################################" << std::endl;
    std::cerr << "# Brainfuck Interpreter by fullPath #" << std::endl;
    std::cerr << "#####################################" << std::endl;
    std::cerr << "Error: " << msg << std::endl;
}