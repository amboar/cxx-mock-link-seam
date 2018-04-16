// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#ifndef _BAZ_HPP
#define _BAZ_HPP

#include <gmock/gmock.h>

class BazMock
{
	public:
		MOCK_METHOD0(is_quux, bool());
		MOCK_METHOD0(get, int());
};

class Baz
{
	public:
		Baz(BazMock& m) : m(m) { };

		bool is_quux();
		int get();

	private:
		BazMock& m;
};

#endif
