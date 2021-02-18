Data Structure
==============

2.7-Growing_arrays
------------------

To minimize the cost of allocation, the array should be resized in chunks.
And for cleanliness the array should be gathered together with the information necessary to maintain it.

The following code defines a growable array of ``Nameval`` items.::

   - ``Nameval`` : new items are added at the end of the array, which is grown as necessary to make room.

SRC_FOR_GROWING_ARRAY_

.. _SRC_FOR_GROWING_ARRAY: ./src/2-6_growing_array.c

2.7-Lists
---------

lists are the most common data structure in typical programs.

List
   Always exact the size to hold its contents,
   +(plus), some per-item storage overhead to hold the each pointer.
   
      - Can also be rearranged by exchanging few pointers.
         - Cheaper for using computer resources.

Array
   Fixed size of bytes array. just like string.

      - Rearrange ususally take many exchanges of byte blocks.

single-linked list
^^^^^^^^^^^^^^^^^^


