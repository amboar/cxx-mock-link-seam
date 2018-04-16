Using link seams with mocking
=============================

A demonstration of something fairly ugly.

We can use link seams with mocks, but there is a compromise of a fair bit of
duplication. Maybe that's not so bad as gmock forces this anyway, but we can't
use inheritance to solve the problem as we need to use the same type names.

Anyway, without further ado, the situation is:

1. We have a class Foo with a method bar() that we'd like to test
2. Foo depends on class Baz, which has is\_quux() and get() methods that are
   not virtual
3. We would like to unit test Foo by injecting a mocked Baz

This is achieved by using a link seam and reimplementing Baz to provide the
indirection otherwise provided by virtual methods by having it delegate to a
mock declaring the same methods as Baz. This means we have effectively three
separate definitions of Baz:

1. The original Baz declaration as used by the non-test code
2. A gmock declaration of a class with the same methods as Baz
3. A link seam declaration of a class with the same methods as Baz

Point 3. is required as we need to define a constructor taking our mock object,
which obviously shouldn't be included in the non-test definition of the Baz
class.
