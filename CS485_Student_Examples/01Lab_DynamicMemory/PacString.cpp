#include "PacString.h"
#include <iostream>
#include <utility>

using namespace std;
using std::swap;

PacString::PacString ()
{

}
PacString::PacString (const char *pszString)
{
	strcpy (mpszData, pszString);
}
PacString::PacString (const PacString &rcData)
{
	strcpy (mpszData, rcData.mpszData);
}
PacString::~PacString ()
{
	delete mpszData;
}
PacString& PacString::operator=(PacString rcData)
{
	swap (mpszData, rcData.mpszData);
}
std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}
