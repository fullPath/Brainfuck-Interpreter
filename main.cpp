/*
 * Brainfuck Interpreter
 *
 * main.cpp
 *
 *  Created on: 29. Mai 2010, 11:30
 *      Author: fullPath
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include "BrainfuckInterpreter.h"
#include "ErrorMsg.h"
#include <vector>
/*
 * main of the interpreter
 */
int main(int argc, char** argv)
{
    if(argc<2)
    {
        ErrorMsg::print("There was no input file specified!\nUsage: bf <input file>");
        return (EXIT_FAILURE);
    }
    BrainfuckInterpreter bfi;
    if(!bfi.parseFile(std::string(argv[1])) || !bfi.execute()) return (EXIT_FAILURE); 
    return (EXIT_SUCCESS);
}

