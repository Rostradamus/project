Contents
========

1. Licensing note
2. What are the tests actually doing?
3. How to run the tests

Licensing note
--------------

catch.hpp is licensed under the Boost Software License 1.0 by Phil Nash

What are the tests actually doing?
----------------------------------

Since these tests were not really meant for student consumption, I (ab)used
various advanced C++ features to make writing them easier for me. I understand this
may give some readers headaches.

To give a basic idea of what's going on, here is a case by case breakdown of
  roughly what each test does:

max_heap_insert:
- doing nothing should do nothing
- inserting the same element twice should throw a logic_error
- inserting one element updates the top properly
- inserting all permutations of 5 elements results in a correct top at every stage

max_heap_delete:
- doing nothing should do nothing
- inserting one element then deleting max returns that element
- inserting all permutations of 5 elements then emptying the heap with delete_max returns
  all the elements in sorted order

max_heap_swap_down:
  Since I can't call swap_down directly (it's private), I use specific patterns
  of inserts that should in principle cause the desired swap_down. I use this to test
  left and right swaps.

max_heap_swap_up:
  Since I can't call swap_up directly (it's private), I use specific patterns of
  inserts that should in principle cause the desired swap_up. I use this to test
  left and right swaps.

test_bst_many:
- all (relevant) frequencies start at 0
- inserting all permutations of 5 elements results in the correct frequencies being
  read each time

How to run the tests
======================

Paste testing.cpp and catch.hpp into your project folder.

In your project folder, run this to compile the tests (this is a rough
  paraphrasing of what the autograder script does before it starts grading you,
  if one of these fails you might have a problem):
make all
g++ -c --std=c++11 testing.cpp
g++ testing.o max_heap.o text_item.o util.o string_bst.o -o testing

To run the tests themselves, run this:
./testing

The actual grading script runs each test case separately to avoid a segfault/hang/etc
  breaking your entire testing run. To run tests separately, try some of these:
./testing max_heap_insert
./testing max_heap_delete
./testing test_bst_many
./testing max_heap_swap_down
./testing max_heap_swap_up
valgrind ./testing
