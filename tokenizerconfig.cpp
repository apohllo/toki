#include "tokenizerconfig.h"

#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <boost/foreach.hpp>

TokenizerConfig::TokenizerConfig(const std::string &filename)
{
	boost::property_tree::ini_parser::read_ini(filename, props_);
}

TokenizerConfig::TokenizerConfig(std::istream &is)
{
	boost::property_tree::ini_parser::read_ini(is, props_);
}

namespace {
	using boost::property_tree::ptree;

	void merge_boost_ptrees(ptree& one, const ptree& other) {
		one.data() = other.data();
		BOOST_FOREACH( const ptree::value_type& in_other, other) {
			boost::optional< ptree& > in_one;
			if ((in_one = one.get_child_optional(in_other.first))) {
				merge_boost_ptrees(*in_one, in_other.second);
			} else {
				one.push_back(in_other);
			}
		}
	}
}

TokenizerConfig& TokenizerConfig::append(const TokenizerConfig &other)
{
	merge_boost_ptrees(props_, other.props_);
	return *this;
}
