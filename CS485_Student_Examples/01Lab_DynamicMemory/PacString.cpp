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
	mpszData = new char[strlen(pszString)];
	strcpy (mpszData, pszString);
}
PacString::PacString (const PacString &rcData)
{
	mpszData = new char[strlen(rcData.mpszData)];
	
	strcpy (mpszData, rcData.mpszData);
}
PacString::~PacString ()
{
	delete mpszData;
}
/*
PacString& PacString::operator=(const PacString &rcData)
{
	strcpy (mpszData, rcData.mpszData);
}
*/
PacString& PacString::operator=(PacString rcData)
{
	swap (mpszData, rcData.mpszData);

	return *this;
}
std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}
PacString& PacString::operator+=(const PacString &rcData)
{
	char * temp = rcData.mpszData;
	cout << "mpszData: " << strlen(mpszData) << " and rcData: " << strlen(rcData.mpszData);
	swap(mpszData, temp);

	return *this;
}
PacString PacString::operator+(const PacString &rcData) const
{
	PacString newString;
	char * temp = mpszData;

	newString.mpszData = new char[strlen(mpszData)];

	strcpy (newString.mpszData, mpszData);
	strcat (newString.mpszData, rcData.mpszData);
	

	return newString;
}
