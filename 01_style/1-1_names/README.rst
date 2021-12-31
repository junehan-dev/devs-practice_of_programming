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

   - 함수명은 기본적으로 동사형을 취하며, 때로 특정 명사가 뒤에 따른다.

      ``now = date.getTime(); putchar('\n');``

   - boolean을 return하는 함수의 경우엔 그러함으로 이름지어, return value가 제한적이라는 것을 알려야한다.

      ``checkoctal(c) ? calcocatal(c) : calcoctal(tooctal(c))``

3. 명확히 하라.
   이름은 단순한 라벨들이 아니라, 정보의 전달이다. 잘못 지어진 이름은 서로의 의도를 misleading 하기 때문에, 잡아낼 수 없는 버그로 이어질 가능성을 높인다.

   - ``#define isoctal(c) ((c) >= '0' && (c) <= '8')``
      이 처럼, name의 정보는 맞으나 구현이 틀린 경우, name의 목적이 명확하기 때문에, 구현체에 오류가 있다는 것을 알아내기 쉽다.

   .. code-block:: java

      public boolean inTable(Object obj) {
      	int j = this.getIndex(obj);
      	return (j == nTable);
      }

Exercise
^^^^^^^^

1. Exercise-1-1_\: Comment on the choice of names and values in the following code.
#. Exercise-1-2_\: Improve this function.
#. Exercise-1-3_\: Read this code aloud.(?)

.. _Exercise-1-1: ./srcs/ex01.c
.. _Exercise-1-2: ./srcs/ex02.c
.. _Exercise-1-3: ./srcs/ex03.c

