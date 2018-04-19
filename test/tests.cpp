// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2018 IBM Corp.
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "test/bazproxy.hpp"

#include "foo.hpp"

TEST(TestFoo, quux_true)
{
	using ::testing::Return;

	constexpr auto val = 3;
	BazMock bazmock;
	BazProxy baz(bazmock);
	Foo foo(baz);

	EXPECT_CALL(bazmock, is_quux()).Times(1).WillOnce(Return(true));
	EXPECT_CALL(bazmock, square()).Times(1).WillRepeatedly(Return(val * val * val));

	ASSERT_EQ(val * val * val, foo.bar());
}

TEST(TestFoo, quux_false)
{
	using ::testing::Return;

	constexpr auto val = 3;
	BazMock bazmock;
	BazProxy baz(bazmock);
	Foo foo(baz);

	EXPECT_CALL(bazmock, is_quux()).Times(1).WillOnce(Return(false));
	EXPECT_CALL(bazmock, get()).Times(1).WillOnce(Return(val));

	ASSERT_EQ(val, foo.bar());
}
