// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#include "config.h"

#include <iostream>

#include "foo.hpp"

int main(void)
{
	Baz baz(5);
	Foo foo(baz);

	std::cout << "bar: " << foo.bar() << "\n";

	return 0;
}
