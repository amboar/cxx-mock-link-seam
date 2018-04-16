// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#ifndef _FOO_HPP
#define _FOO_HPP
#include "baz.hpp"

class Foo
{
	public:
		Foo(Baz& baz);
		int bar();
	private:
		Baz& baz;
};

#endif
