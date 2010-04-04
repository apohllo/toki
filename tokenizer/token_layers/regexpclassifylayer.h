#ifndef REGEXPCLASSIFYLAYER_H
#define REGEXPCLASSIFYLAYER_H

#include "tokenlayer.h"
#include <unicode/regex.h>

/**
 * Classification layer that changes a token type if the orth matches one of
 * the regular expressions given.
 *
 * Each regexp has a type attached to it that will be set in the token. Rules
 * are matched in order, the first matching rule taking effect. If a token does
 * not match any of the regexps, its type is not modified.
 */
class RegexpClassifyLayer : public TokenLayer
{
public:
	/**
	 * Constructor.
	 *
	 * Keys recognized in the configuration are of a pattern ``type:TYPE''
	 * TYPE indicates the type to set, the value of the config variable is the
	 * regular expression to use.
	 */
	RegexpClassifyLayer(TokenSource* input, const Config::Node& props);

	/// Destrctor
	~RegexpClassifyLayer();

	/// TokenLayer override
	Token* processToken(Token *t);

private:
	/// token type + regexp vector
	std::vector< std::pair<std::string, RegexMatcher*> > classifiers_;
};

#endif // REGEXPCLASSIFYLAYER_H
