#ifndef LAYERTOKENIZER_H
#define LAYERTOKENIZER_H

#include "tokenizer.h"

class TokenLayer;

#include <boost/scoped_ptr.hpp>

class LayerTokenizer : public Tokenizer
{
public:
	/**
	 * Constructor.
	 *
	 * The configuration is processed for [layer:ID] sections that define
	 * layers and a [layers] section with one or more layer=ID entries that
	 * define which layers to actually use and in what order. Each layer=ID
	 * should have a corresponding [layer:ID] section, but not all [layer:ID]
	 * sections need to be used. The IDs should be unique across a config.
	 *
	 * The subkeys of each [layer:ID] are passed to the appropriate layer's
	 * constructor, the layer class to use being determined by the class subkey.
	 *
	 * The initial tokenization using whitespace characters is confiugurable by
	 * the [input] section, the contents are passed to the WhitespaceTokenizer.
	 * @see WhitespaceTokenizer
	 *
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given UnicodeSource, and take
	 * ownership
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(UnicodeSource* input, const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given UnicodeSource as a shared
	 * pointer.
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(boost::shared_ptr<UnicodeSource> input, const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given std::istream. Note no
	 * ownership is taken and the stream must live long enough.
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(std::istream& is, const Config::Node& cfg = Config::Default());

	/**
	 * Constructor shorthand -- start with the given UnicodeString, which is
	 * copied.
	 * @see Tokenizer::Tokenizer
	 */
	LayerTokenizer(const UnicodeString& s, const Config::Node& cfg = Config::Default());

	/**
	 * Destructor
	 */
	~LayerTokenizer();

	/// TokenSource override
	void newInputSource();

	/// TokenSource override
	void reset();

	/// TokenSource override
	Token* getNextToken();

	/// Output a human-readable synopsis of the loaded layers
	std::string layers_info() const;

	std::string layers_long_info(const std::string& sep) const;

private:
	/**
	 * Apply configuraton
	 */
	void apply_configuration(const Config::Node& cfg);

	/// The underlying input token source for the first layer
	boost::scoped_ptr<Tokenizer> input_tokenizer_;

	/// The token procesing layers
	std::vector<TokenLayer*> layers_;
};

#endif // LAYERTOKENIZER_H
