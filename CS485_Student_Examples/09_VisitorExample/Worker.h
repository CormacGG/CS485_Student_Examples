//***************************************************************************
// File name:  Worker.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once
#include "Employee.h"

class Worker : public Employee
{
public:
  Worker () {};

  Worker (std::string fname, std::string lname, unsigned long long salary)
    : Employee(fname, lname, salary)
  {}

  virtual void accept (IEmployeeVisitor *pcVisitor);
  friend std::ostream& operator<<(std::ostream & rcOut, const Worker &rcWorker);

private:

};