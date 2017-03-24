#include "PrintSalaryVisitor.h"



PrintSalaryVisitor::PrintSalaryVisitor(std::ostream &rcOut) : mrcOutputStream (rcOut)
{
}


PrintSalaryVisitor::~PrintSalaryVisitor()
{
}


void PrintSalaryVisitor::visit(Worker &rcWorker)
{
	if (rcWorker.getSalary() % 2 != 0)
	{
		mrcOutputStream << rcWorker << std::endl;
	}
}

void PrintSalaryVisitor::visit(Manager &rcTheMan)
{
	if (rcTheMan.getSalary() % 2 == 0)
	{
		mrcOutputStream << rcTheMan << std::endl;
	}
}