**Based on Brian W.kernighan - The-Practice-of-Programming**
*https://www.cs.princeton.edu/~bwk/tpop.webpage/*

Preface
-------

Was it fun to make programs?

Our approach in this book is based on these underlying,
interrelated principles, which apply at all levels of computing.
These includes::

   *simplicity*
      Keeps program short and manageable.

   *clarity*
      Makes sure they are easy to understand for people and machine.

   *generality*
      Means they work well in broad range of situations and
      adapt well as new situations arise

   *automation*
      Lets the machine do the owrk for us, freeing us from
      mundane tasks.

By looking computer programming in a variety  of languages,
from algorithms and data structure through design, debugging,
testing, and performance improvement, we can illustrate
universal engineering concepts that are independent of 
language, os or programming paradigm.

ch01-programming_style
^^^^^^^^^^^^^^^^^^^^^^

   Well-written programs have fewer errors and easier to debug and to modify.
   so it is important to think about style from the beginning.
   also introduces and important theme in good programming,
   the use of idioms appropriate to the language being used.

ch02-algorithms_and_data_structures
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   The core of the computer science curriculum and major part of programming courses.
   It's a brief review of the handful of algor and dst that show up in almost every programs.
   More complex algorithms and data structures usually evolve from theses building blocks,
   so one should master the basic.

ch03-design_and_implementation_program
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   A small program that illustrates algor and dst issues in realistic setting.
   The program is implemented in 5 languages.
   Interfaces between users, programs and parts of programs are fundamental in programming
   and much of the success of software is determined by
   how well interfaces are designed and implemented.

ch04-show_evolution_of_small_library
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   It illustrates manu of the concerns of interface design::

      - abstraction
      - information hiding
      - resource management
      - error handling

   first time to write programs correctly, time, bugs, debugging are inevitable.

ch05-strategies_and_tactics_for_systematic_and_effective_debugging
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   Common bugs and the importance of *numerology,*
   where patterns in debugging output often indicate where a problem lies.

   Testing is an attempt to develop a reasonable assurance that
   program is working correctly and that is stays correct as it evolves.

ch06-systematic_testing_by_hand_and_machine
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   Boundary condition test probe at potential weak spots.
   Mechanization and test scaffolds make it easy to do
   extensive testing with modest effort.
   Stress tests provide a different kind of testing than
   typical users do and ferret out a different class of bugs.

ch07-orderly_way_to_approach_the_task_of_making_program_use_resources_efficiently
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   programs remains correct and sound as it is made more efficient.

ch08-covers_portability
^^^^^^^^^^^^^^^^^^^^^^^

   Successful programs live long enough that
   their envronment(hardware, contries...) changes.
   The goal of portability is to reduce the maintenance of a program
   by minimizing amount of change necessary to adapt it to a new env.

ch09-importance_of_notation_in_computing
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   examples shows how we can use notation to simplify programs,
   to guide implementations, and even to
   help us write programs that write programs.
