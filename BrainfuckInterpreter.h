/*
 * BrainfuckInterpreter.h
 *
 *  Created on: 29. Mai 2010, 12:12
 *      Author: fullPath
 */

#ifndef _BRAINFUCKINTERPRETER_H
#define	_BRAINFUCKINTERPRETER_H

#include <string>
#include <vector>

class BrainfuckInterpreter
{
public:
    BrainfuckInterpreter();
    bool parseFile(std::string input_file);
    bool execute();
    virtual ~BrainfuckInterpreter();
private:
    char getch();
    std::vector<char> data_tape;
    std::vector<char> code_tape;
    long ptr;
};

#endif	/* _BRAINFUCKINTERPRETER_H */

