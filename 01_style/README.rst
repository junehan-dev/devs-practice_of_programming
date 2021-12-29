Style
=====

.. code-block:: c

   if ( (country == SING ) || (country == BRNI) ||
       (country == POL) || (country == ITALY) )
   {
   /*
    * if country is ..
    * Reset answer time and set day of week.
    */
   }

- The principles of programming style are based on common sense guided by experience not on arbitray rules.
- Code should be clear and simple, 
   - Straightforward logic, natural expression, conventional language use, meaningful names, neat formatting, helpful comments
   - 영리한 tricks와 흔치 않은 설계방식을 피해야 한다.
- style의 세부사항은 local conventions, management 규약 또는 프로그램에 의해 부과되는 것일 수 있다.
   - 세부사항 정의가 부족하다면 넓게 공유된 규약을 따르는 것이 최선이다.

1-01_Names
----------

이름에는 무엇이 담겨야 하는가?

   variable 이나 function 이름은 특정한 객체에 표시를 하는 것이고, 그 객체의 목적을 전달한다.
   *informative, concise, memorable, pronounceable*\의 조건을 갖춘다면 최상일 것이다.

**Use descriptive names for globals, short names for locals.**

   - descriptive in globals

      global variables는 정의상, 프로그램의 어디에서나 활용될 수 있기 때문에 하단의 두 조건을 충족할 필요가 있다.

         - long enough : ``int npanding``
         - descriptive enough ``<varname> // current length of input queue``
   - short for locals

      대조적으로, local object들은 짧은 이름으로 충분할 것이다.

         ``int n, npoints, numberOfPoints;// 'numberOfPoints' is overkill.``
      프로그래머들은 때로 컨텍스트와 무관하게 긴 이름을 사용하도록 재촉되는 경우가 있는데, 그것은 실수이다.

         *clarity*\는 때로 용기를 내야 얻을 수 있다.

Naming conventions
^^^^^^^^^^^^^^^^^^

*Naming conventions*\는 그들의 코드를 이해하기 쉽도록 한다.
그들은 특정 디자인이나 목적을 공유하기 때문에, 코드가 작성되면서 새로운 이름을 붙이는 것도 어렵지 않도록 한다.

프로그램이 긴 코드를 가질수록, 좋은 것을 선택하는 것이 더욱 중요해진다.
descriptive, systematic names(설명이 충분하고, 시스템에 적합한)이 그러하다.

1. 일관성을 유지하라.

   연관된 대상에게는 연관된 이름을 주고, 그들의 관계와 차이를 드러내야 한다.
   아래의 경우는 이름이 너무 긴 것에 비해, 클래스 멤버들의 이름이 일관적이지 않다.

   .. code-block:: java

      /**
      * duplicate descriptives by their name.
      */
      class UserQueue {
      	int noOfItemsInQ, frontOfTheQueue, queueCapacity;
      	public int noOfUsesInQueue() {
      		return 0;
      	}
      }

   - "queue"라는 단어는 ``Q, Queue, queue`` 로 전부 등장한다.
   - queues의 데이터는 오직 ``UserQueue``\타입의 변수를 통해서만 접근할 수 있기 때문에, 멤버 이름에서 사실 "queue"라는 의미는 굳이 언급할 필요가 없다.

   .. code-block:: java

      class UserQueue {
      	int nitems, front, capacity;
      	public int nusers() {
      		return 0;
      	}
      }

      queue = UserQueue();
      queue.capacity++;
      n = queue.nusers();

   - 명확성은 전혀 사라지지 않았다.
   - 그러나, ``items``\와 ``users``\는 동일한 것이기 때문에 더 작업이 필요하다.
2. 함수명에는 active names를 사용하자.

   a

1-02_Expressions and statements
-------------------------------

- *Use the natural form for expressions*::

   ``if (!(block-id < actblks) || !(block-id >= unblocks))``
   to,
   ``if ((block-id >= actblks) || (block-id < unblocks))``

- *Parenthesize to resolbe ambiguaty*
- *Clarity is not brevity.*
   Often is will be shorter, but also can be longer.

- *Be careful with side effects.*
   Operator like ``++`` have side effects.
   ``str[i++] = str[i++] = ' ';//   ?``
   not only increments, I/O is another source of behind-the-scene action.
   ``scanf("%d %d", &yr, &profit[yr]);//    ?``

1-03_Consistency and idioms
---------------------------

- *follow the legacy codes rule when to fix other's.*
- *structure code with brackets to make people more efficient.*

1-04_Function_Macros
--------------------

- *Macro avoids the overhead of function call*
   - today it is irrelevant, modern machine runs much fater.

- *Avoid function macros*
   - C++, inline functions render tunction macros unnecessary.
   - Java, there are no macros.
   - C, They cause more problems than they solve.

One of the most problem with function macro is,
that a paramater that appear more than once in the definition
might be evaluated more than once.::

   .. code-block:: c

      #define isupper(c) ((c) >= 'A' && (c) <= 'Z')
      while (isupper(getchar());

   **If the argument in the call includes an expression
   with side effects, the result is the subtle bug.**

   1. ``c`` is grater than 'A' == True.
   2. re-evaluate ``c`` and cmp.

Sometimes multiple evaluation causes a performance problem rather than an outright error.::

   .. code-block:: c

      #define ROUND_TO_INT(x) ((int) ((x) + (((x) > 0) ? 0.5 : -0.5)))
      //...
      size = ROUNT_TO_INT(sqrt(dx*dx + dy*dy));

- *Parantheses are neccessary.*

   - Even paranthesizing the macro properly does not address the multiple evaluation problem.
   - If operation is expensive or common enough to be wrapped up. use function.

