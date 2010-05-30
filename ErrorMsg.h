/*
 * ErrorMsg.h
 *
 *  Created on: 29. Mai 2010, 13:31
 *      Author: fullPath
 */

#ifndef _ERRORMSG_H
#define	_ERRORMSG_H

#include <string>

class ErrorMsg {
public:
    ErrorMsg();
    static void print(const std::string& msg);
    virtual ~ErrorMsg();
};

#endif	/* _ERRORMSG_H */

