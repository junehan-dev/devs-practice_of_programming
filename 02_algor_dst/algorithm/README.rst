Algorithms
==========

2-01_Searching
--------------

Array
   Nothing better than array for storing static tabular data.
   Compile-time initialization makes it cheap and easy to construct such arrays.
   (In java, initialization occurs at run-time, but this is an unimportant implementation detail *unless the arrays are large.* )

Linear search
^^^^^^^^^^^^^

Search routine need to know how many elems are in the array.
One way to tell is to pass length as an arg or place NULL marker at the end of the array
link to 2-1_arr_seq_search_srccode_.

.. _2-1_arr_seq_search_srccode: src/2-1_array_sequential_search.c

A paramter that is an array of string declaration::

   - ``char *array[]``
   - ``char **array``

   Although this forms are equ, the first makes it clearer how the params will be used.

This search algorithm is called *sequential search* .
Standard library subroutines to do ``seq_search`` .

   - ``strchr``
   - ``strstr``
   - ...

These functions's runtime is linear to datasize, so this method is also known as *linear search.*

Excerpt from an array of more realistic size from program
that parses HTML, which defines textual names for well over a
hundred individual characters.
link to 2-1_realistic_size_of_arr_srccode_.

.. _2-1_realistic_size_of_arr_srccode: src/2-1_realistic_size_of_arr.c

For a larger array like this, it's more efficient to use *binary search.*

Binary search
^^^^^^^^^^^^^

Binary Search Algrorithm
   is an orderly version of the way we look up words in a dictionary.
   Checks the middle element, If that value is bigger than looking for,
   look in the first half.

*``Binary`` DO divide, eliminates for half units of things.*
   *``log2n: Nitems -> 2^times = N``*

link to 2-1_binsearch_.

.. _2-1_binsearch: src/2-1_binsearch.c

2-02_Sorting
------------

If data set is known in advance,
It can be sorted when the program is written and built using compile-time initialization.
If not, it must be sorted when the program is run.

Quick sort
^^^^^^^^^^

Quicksort
   **One of the best all-round sorting algorithms is quicksort.**
   Was invented in 1960 by C. A. R. Hoare.
   Quicksort is fine example of how to avoid extra computing.
   Works by *partitioning an array into little and big elems*::

      1. ``pivot``: pick one elem of array.
      #. partition the other elements into 2 groups::
         - *little ones,* that are less than pivot value,
         - *big ones,* that are greater than or equal to ``pivot`` value.

      #. recursively sort each group.

.. code-block:: c

   void quicksort(int arr[], int len);
   /*
    * 1. pick one randomly using rand() and store as pivot
    * 2. arr[0] = pivot; last = 0;
    * 3. for (i = 1; i < len; i++)
    *   3-1. if (pivot > arr[i])
    *       3-1-1. swap(arr, ++last, i)
    * 4. swap(arr, 0, last); // this point last is lower value index.
    * 5. quicksort(arr, last); // recurse for lower ~ pivot
    * 6. quicksort((arr + (last + 1)), len - last - 1) // recur for larger[after pivot] ~ end[len]
    */

   void swap(int v[], int i, int j);
   /*
    * 1. store v[j] to temp
    * 2. swap each value in address i, j
    */

