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
