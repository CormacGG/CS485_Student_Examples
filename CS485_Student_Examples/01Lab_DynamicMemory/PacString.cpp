#include "PacString.h"
#include <iostream>
#include <utility>

using namespace std;
using std::swap;

void copyString(char *dest, const char *src);
void catString(char *dest, const char *src);

PacString::PacString ()
{

}
PacString::PacString (const char *pszString)
{
	mpszData = new char[strlen(pszString) + 1];
	copyString (mpszData, pszString);
}
PacString::PacString (const PacString &rcData)
{
	mpszData = new char[strlen(rcData.mpszData) + 1];
	
	copyString (mpszData, rcData.mpszData);
}
PacString::~PacString ()
{
	delete mpszData;
}

PacString& PacString::operator=(const PacString &rcData)
{
	if (mpszData)
	{
		delete mpszData;
	}

	mpszData = new char[strlen(rcData.mpszData) + 1];

	copyString (mpszData, rcData.mpszData);

	return *this;
}

/*PacString& PacString::operator=(PacString rcData)
{
	swap (mpszData, rcData.mpszData);

	return *this;
}*/
std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}
PacString& PacString::operator+=(const PacString &rcData)
{
	char *temp = new char[strlen(mpszData) + strlen(rcData.mpszData) + 1];

	copyString(temp, mpszData);
	catString (temp, rcData.mpszData);

	//delete mpszData;

	//mpszData = new char[strlen(mpszData) + strlen(rcData.mpszData)];

	swap(temp, mpszData);

	delete temp;

	return *this;
}
PacString PacString::operator+(const PacString &rcData) const
{
	PacString *pNewString = new PacString ();
	char * temp = mpszData;

	pNewString->mpszData = new char[strlen(mpszData) + strlen(rcData.mpszData) + 1];

	copyString (pNewString->mpszData, mpszData);
	catString (pNewString->mpszData, rcData.mpszData);
	

	return *pNewString;
}

void copyString (char *dest, const char *src)
{
	char ch;

	ch = src[0];

	for (int i = 0; NULL != ch; i++)
	{
		ch = src[i];
		dest[i] = ch;
	}
}

void catString(char *dest, const char *src)
{
	char ch = 'a';

	for (int i = strlen(dest), j = 0; NULL != ch; i++, j++)
	{
		ch = src[j];
		dest[i] = ch;
	}
}