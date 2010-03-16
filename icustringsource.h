#ifndef ICUSTRINGSOURCE_H
#define ICUSTRINGSOURCE_H
#include <unicode/unistr.h>
#include <unicode/schriter.h>

#include "unicodesource.h"

/**
 * A thin wrapper around UnicodeString (using aStringCharacterIterator) to adapt
 * it to the UnicodeSource interface.
 */
class IcuStringSource : public UnicodeSource
{
public:
	/**
	 * The constructor.
	 *
	 * @param u The Unicode string to wrap. The string is copied.
	 */
	IcuStringSource(const UnicodeString& u);

	/// The destructor
	~IcuStringSource();

	/// Override from UnicodeSource
	UChar peekNextChar();

	/// Override from UnicodeSource
	UChar getNextChar();

	/// Override from UnicodeSource
	bool hasMoreChars();

private:
	/// The internal StringCharacterIterator object
	StringCharacterIterator iter_;
};

#endif // ICUSTRINGSOURCE_H
