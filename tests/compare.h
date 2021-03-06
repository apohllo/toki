/*
    Copyright (C) 2010 Tomasz Śniatowski, Adam Radziszewski
    Part of the libtoki project

    This program is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by the Free
Software Foundation; either version 3 of the License, or (at your option)
any later version.

    This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. 

    See the LICENSE, COPYING.LESSER and COPYING files for more details.
*/

#ifndef LIBTOKI_COMPARE_H
#define LIBTOKI_COMPARE_H


#include <boost/test/unit_test.hpp>

void init_compare_suite(boost::unit_test::test_suite* ts, const std::string& path);

#endif // LIBTOKI_COMPARE_H
