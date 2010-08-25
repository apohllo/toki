#ifndef LIBTOKI_SENTENCE_H
#define LIBTOKI_SENTENCE_H

#include <libtoki/token.h>

#include <libtoki/util/foreach.h>

#include <boost/range.hpp>

#include <vector>

namespace Toki {

	/**
	 * A simple sentence wrapper template, a template not a plain class since
	 * it is intended for use with various types of tokens.
	 *
	 * A sentence owns its Tokens.
	 */
	template<typename TT>
	class SentenceTemplate : private boost::noncopyable
	{
	public:
		/// Empty constructor
		SentenceTemplate()
			: tokens_()
		{
		}

		/// Range constructor
		template <typename T>
		explicit SentenceTemplate(const T& range)
			: tokens_()
		{
			std::copy(range.begin(), range.end(), std::back_inserter(tokens_));
		}

		/// Destructor
		~SentenceTemplate()
		{
			foreach (TT* t, tokens_) {
				delete t;
			}
		}

		bool empty() const {
			return tokens_.empty();
		}

		/// Size accesor
		size_t size() const {
			return tokens_.size();
		}

		/// Token accesor
		TT* operator[](size_t idx) {
			return tokens_[idx];
		}

		/// Token accesor, const
		const TT* operator[](size_t idx) const {
			return tokens_[idx];
		}

		/// Underlying vector accesor, const
		const std::vector<TT*>& tokens() const {
			return tokens_;
		}

		/// Underlying vector accesor
		std::vector<TT*>& tokens() {
			return tokens_;
		}

		/// Helper function for appending tokens
		void append(TT* t) {
			tokens_.push_back(t);
		}

	private:
		/// The tokens this sentence contains and owns
		std::vector<TT*> tokens_;
	};

	/// typedef for a sentence of Toki tokens
	typedef SentenceTemplate<Token> Sentence;

} /* end ns Toki */

#endif // LIBTOKI_SENTENCE_H
