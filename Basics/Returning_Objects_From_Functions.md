The first form to return object

```c++
Foo make_foo(int n) {
        return Foo{n};
        }
```

It may appear to you that, using the preceding, a full copy of Foo is being made, thereby wasting valuable resources. But it isn’t always so. Say you define Foo as:

```c++
struct Foo
{
    Foo(int n ){};
    Foo(const foo&){
        cout<< copy constructor << endl
        }
}
```

You will find that the copy constructor may be called anywhere from zero to two times: the exact number of calls depends on the compiler. Return Value Optimization (RVO) is a compiler feature that specifically prevents those extra copies being made

the second approch is to return a smart pointer such unique_ptr

```c++
unique_ptr<Foo>
make_foo(int n)
{
    return make_unique<Foo>(n);
}
```

This is very safe, but also opinionated: you’ve chosen the smart pointer for the user.

The third and final option is to use a raw pointer.
This way, you are not enforcing the clean-up of the allocated object, but you are sending a very clear message that it is the caller’s responsibility:

```c++
Foo*
make_foo(int n)
{
    return new <Foo>(n);
}
```
