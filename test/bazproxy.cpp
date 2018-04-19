// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#include "test/bazproxy.hpp"

bool Baz::is_quux()
{
	return static_cast<BazProxy*>(this)->m.is_quux();
}

int Baz::get()
{
	return static_cast<BazProxy*>(this)->m.get();
}
