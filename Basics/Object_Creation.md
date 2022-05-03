# Object Creation

## Stack allocation

creates an object that will be allocated on the stack. The object will be cleaned up automatically at the end of the scope.

## Heap allocation

using a raw pointer puts the object on the heap (a.k.a. the free store). Foo\* foo = new Foo; creates a new instance of Foo and leaves open the question of who is in charge of cleaning up the object

## Unique pointer

can take a heap- allocated pointer and manage it so that it’s cleaned up automatically when there is no longer a reference to it.
you cannot make copies of it, and you cannot pass it into another function without losing control of the original.

## Shared pointer

takes a heap-allocated pointer and manages it, but allows the sharing of this pointer around in code. The owned pointer is only cleaned up when there are no components holding on to the pointer.

## Weak pointer

is a smart but nonowning pointer, holding a weak reference to an object managed by a shared_ptr. You need to convert it to a shared_ptr in order to be able to actually access the referenced object. One of its uses is to break circular references of shared_ptrs.
