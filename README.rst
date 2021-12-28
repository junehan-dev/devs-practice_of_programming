**Based on Brian W.kernighan - The-Practice-of-Programming**
*https://www.cs.princeton.edu/~bwk/tpop.webpage/*

Preface
-------

Have you ever...::

   - wasted a lot of time coding the wrong algorithm?
   - used a dst that was much too complicated?
   - tested a program but missed an obvious problem?
   - spent a day looking for a bug you should have found in five minuted?
   - needed to make a program run three time faster and use less memory?
   - struggled to move a program from a workstation to PC or vice versa?
   - tried to make a modest change in someone else's program?
   - rewritten a program because you couldn't understand it?

위의 경험들이 재미있었나요?::

   아마 이것들을 다루는 것은 때로는 버겁게 느껴졌을것이다.
   위에 등장하는 공학적인(excepts those engineering parts,) 부분을 제외하고, **style(practice of programming)**\은 CS나 교육에서 집중하는 요소가 아니기 때문이다.
   대부분 프로그래머들은, 이를 경험에서, 혹은 전혀 습득하지 못하기도 한다.

이 분야는 거대하며, 내용이 과도한 인터페이스이며, 지속적으로 변화하는 도구들과 시스템을 지니고 있다, 또한, 가차업는 압력이 모든 것에 적용하며, 우리는 기본 원칙*(simplicity, clarity, generality)*\을 놓칠 수 있다.

   basic principles는 좋은 소프트웨어의 기반이 된다.

      - tools의 가치를 반영하여 엿볼 수 있도록 한다.
      - 소프트웨어 창조의 일부를 기계화하는 언급이 되어, **컴퓨터를 프로그래밍 안으로 끌어들인다.**

Our approach in this book is based on these underlying,
interrelated principles, which apply at all levels of computing.
These includes::

   Simplicity
      Keeps program short and manageable.

   Clarity
      Makes sure they are easy to understand for people and machine.

   Generality
      Means they work well in broad range of situations and adapt well as new situations arise.

   Automation
      Lets the machine do the owrk for us, freeing us from
      mundane tasks.

By looking computer programming in a variety of languages,
from algorithms and data structure through design, debugging, testing, and performance improvement, 
we can **illustrate universal engineering concepts that are independent of language, os or programming paradigm.**

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
