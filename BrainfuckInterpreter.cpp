/*
 * BrainfuckInterpreter.cpp
 *
 *  Created on: 29. Mai 2010, 12:12
 *      Author: fullPath
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "BrainfuckInterpreter.h"
#include "ErrorMsg.h"

BrainfuckInterpreter::BrainfuckInterpreter()
{
}

BrainfuckInterpreter::~BrainfuckInterpreter()
{
}

bool BrainfuckInterpreter::parseFile(std::string input_file)
{
    code_tape.clear();

    char c;
    unsigned open_clip = 0;
    long counter = 0;
    std::ifstream in(input_file.c_str());
    if(!in)
    {
        ErrorMsg::print("Can't read input file <"+ input_file + ">!");
        return false;
    }
    else
    {
        while(in.get(c))
        {
            ++counter;
            if(c == '>' || c == '<' || c == '.' || c == ',' || c == '-' || c == '+')
                code_tape.push_back(c);
            else if(c == '[')
            {
                ++open_clip;
                code_tape.push_back(c);
            }
            else if(c == ']')
            {
                if(open_clip == 0)
                {
                    std::stringstream msg;
                    msg << "Mismatched parenthesis: ] at character " << counter << "!";
                    ErrorMsg::print(msg.str());
                    return false;
                }
                --open_clip;
                code_tape.push_back(c);
            }
        }
        if(open_clip != 0)
        {
            ErrorMsg::print("Mismatched parenthesis: a [ was never closed!");
            return false;
        }
    }
    return true;
}

bool BrainfuckInterpreter::execute()
{
    bool exec = true;
    unsigned open_clip = 0;
    ptr = 0;
    data_tape = std::vector<char>(30000,0);
    unsigned long int i = 0, end = (unsigned long int)code_tape.size();
    std::vector<unsigned long int> jump_point;

    while(i<end)
    {
        bool next = true;
        if(exec)
        {
            if(code_tape[i] == '>')
            {
                ++ptr;
                if(ptr+10>(unsigned long int)data_tape.size()) data_tape.resize((unsigned long int)data_tape.size()+1000,0);
            }
            else if(code_tape[i] == '<')
            {
                if(--ptr<0) ptr=0;
            }
            else if(code_tape[i] == '+')
            {
                ++data_tape[ptr];
            }
            else if(code_tape[i] == '-')
            {
                --data_tape[ptr];
            }
            else if(code_tape[i] == '.')
            {
                std::cout << data_tape[ptr];
            }
            else if(code_tape[i] == ',')
            {
               data_tape[ptr] = getch();
            }
            else if(code_tape[i] == '[')
            {
                if(data_tape[ptr] == 0)
                    exec = false;
                else
                    jump_point.push_back(i);
            }
            else if(code_tape[i] == ']')
            {
                i = jump_point[jump_point.size()-1];
                jump_point.pop_back();
                next = false;
            }
        }
        else
        {
            if(code_tape[i] == '[')
                ++open_clip;
            else if(code_tape[i] == ']')
            {
                if(open_clip == 0)
                    exec = true;
                else
                    --open_clip;
            }
        }
        if(next) ++i;
    }
    return true;
}

char BrainfuckInterpreter::getch()
{
    system("stty raw");
    char c = getchar();
    system("stty cooked");
    return c;
}