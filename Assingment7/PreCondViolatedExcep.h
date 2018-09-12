/**@file PreCondViolatedExcep*/
#pragma once
#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include<stdexcept>
#include<string>

using namespace std;
class PreCondViolatedExcep : public logic_error
{
public:
	PreCondViolatedExcep(const string& message = "");
};//end PreCondViolateExcep
#endif