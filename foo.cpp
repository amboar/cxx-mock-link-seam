// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#include "foo.hpp"

Foo::Foo(Baz& baz) : baz(baz)
{
}

int Foo::bar()
{
	if (baz.is_quux())
		return baz.get() * baz.get();

	return 0;
}
