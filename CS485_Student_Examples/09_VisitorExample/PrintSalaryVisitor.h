#pragma once
#include "IEmployeeVisitor.h"
#include <iostream>

class PrintSalaryVisitor : public IEmployeeVisitor
{
	public:
		PrintSalaryVisitor (std::ostream &rcOut);
		~PrintSalaryVisitor ();
		virtual void visit (Worker &rcWorker);
		virtual void visit (Manager &rcTheMan);
	private:
		std::ostream &mrcOutputStream;
};

