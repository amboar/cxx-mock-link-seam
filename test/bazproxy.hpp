// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#include <gmock/gmock.h>

#include "baz.hpp"

class BazMock
{
	public:
		MOCK_METHOD0(is_quux, bool());
		MOCK_METHOD0(get, int());
		MOCK_METHOD0(square, int());
};

class BazProxy: public Baz
{
	public:
		BazProxy(BazMock& m) : Baz(0), m(m) { }
		virtual inline int square() { return m.square(); }

		BazMock& m;
};
