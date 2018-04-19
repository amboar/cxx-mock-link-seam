// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#include <gmock/gmock.h>

#include "baz.hpp"

class BazMock
{
	public:
		MOCK_METHOD0(is_quux, bool());
		MOCK_METHOD0(get, int());
};

class BazProxy: public Baz
{
	public:
		BazProxy(BazMock& m) : Baz(0), m(m) { };
		BazMock& m;
};
