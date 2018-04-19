Using link seams with mocking
=============================

A demonstration of link seams and mocking with C++.

Link seams allow us to inject test code where we don't otherwise have an
avenue, for example if we have classes that define non-virtual methods
(something we can't override with inheritance). Typically the implementation
we link into the test might implement the desired mock behaviour directly,
however this has the downside of requiring one binary per mocked test case.

We can avoid the plethora of binaries by Yet Another Layer of Indirection: The
linked class implementation can delegate to a mock instance, giving us what
marking the methods as virtual would have in the first place.

If we are to do this, it's desirable that the implementation of the whole
sideshow doesn't create too much of a maintenance mess - we need the ability to
scale up to handling large numbers of classes that may need to be mocked for
testing purposes.

This repo's existence is to demonstrate techniques for achieving link seam
testing with mocks and the scalability of the approach.

Anyway, without further ado, the situation is:

1. We have a class Foo with a method bar() that we'd like to test
2. Foo depends on class Baz, which has is\_quux() and get() methods that are
   not virtual, and a square() method that is inline
3. We would like to unit test Foo by injecting a mocked Baz

This to achieve this we require:

1. The original Baz definition as used by the non-test code, as required by
   the actual problem we're trying to solve with software
2. All `inline` functions also be marked `virtual` (required in order to test
   the interfaces no matter what testing strategy we have)
3. A gmock definition of a class with the same methods as Baz (as required by
   gmock)
4. A link seam definition of a proxy class extending Baz (BazProxy)

Point 4. is required as we need to define a constructor taking our mock object,
and define the member to contain (a reference to) the mock object. By extending
Baz we avoid having to re-define it, minimising the effect of the mocking
strategy on scalability.

The only methods that must be defined on BazProxy are any `virtual inline` or
`virtual` methods, to override the implementations in the base class Baz and
delegate to the mock.

From this point we need to simply provide an alternative implementation of
Baz's (note, *not* BazProxy's) non-virtual methods to link into the test case.
These are implemented in terms of a static cast to BazProxy, and then calling
through BazProxy's mock member to the associated mocked function.

Note: The technique shown here is not required if all methods on a class are
virtual. However, methods on a class should not be made virtual purely to
satisfy testing requirements, as demonstrated by this repository.
