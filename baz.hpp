// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#ifndef _BAZ_HPP
#define _BAZ_HPP

class Baz
{
	public:
		Baz(int val) : val(val)
		{
		};

		bool is_quux();
		int get();
		virtual inline int square() { return val * val; };

	private:
		int val;
};

#endif
