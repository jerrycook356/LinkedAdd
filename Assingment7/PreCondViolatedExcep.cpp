/**@file PreCondViolatedExcep.cpp*/

#include "PreCondViolatedExcep.h"

PreCondViolatedExcep::PreCondViolatedExcep(const string& message) :
	logic_error("Precondition value exception:" + message)
{

}//end constructor