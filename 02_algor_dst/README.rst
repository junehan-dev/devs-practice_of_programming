Algorithms and Data Structures
==============================

주로 정렬과 검색에서 모든 프로그램에 등장하는 소수의 기본적인 알고리즘이 있고, 그들은 라이브러리에 포함되기도 한다.
비슷한 맥락으로, 대부분의 자료구조는 기초적인 몆가지에 기반한다.

우리는 논쟁을 확고히 하기 위하여 작업용 버전을 작성했다. 그리고 이것을 문자그대로 옮겨도 좋다.(만약 필요하다면) 
하지만 프로그래밍 언어와 그의 라이브러리가 무엇을 제공하는지 확인한 이후에만 그리 해달라.

2-01_Searching
--------------

Array
   Nothing better than array for stroing static tabular data.
   Compile-time initialization makes it cheap and easy to construct such arrays.
   (In java, initialization occurs at run-time, but this is an unimportant implementation detail *unless the arrays are large.* )

Linear search
^^^^^^^^^^^^^

Search routine need to know how many elems are in the array.
One way to tell is to pass length as an arg or place NULL marker at the end of the array
link to 2-1_arr_seq_search_srccode_.

.. _2-1_arr_seq_search_srccode:: src/2-1_array_sequential_search.c

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

.. _2-1_realistic_size_of_arr_srccode:: src/2-1_realistic_size_of_arr.c

For a larger array like this, it's more efficient to use *binary search.*

Binary search
^^^^^^^^^^^^^

Binary Search Algrorithm
   is an orderly version of the way we look up words in a dictionary.
   Checks the middle element, If that value is bigger than looking for,
   look in the first half.

*``Binary`` DO divide, eliminates for half units of things.*
   *``log2n: Nitems -> 2^times = N``*

2-02_Sorting
------------

