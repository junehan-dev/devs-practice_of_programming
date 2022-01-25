1-05 Magic Numbers
------------------
   *Magic numbers*\는, 상수, 배열길이, 캐릭터 위치, 변환요소, 혹은 다른 문맥적인 숫자 값을 말한다.

Give names to magic number
^^^^^^^^^^^^^^^^^^^^^^^^^^

*alphabet histogram program*

   - histogram_\
      코드 상에, 20, 21, 22, 23, 27등의 숫자가 등장하고 그들은 분명하게 연관된, 연관되있나?
      사실, 이 프로그램에 중요한 숫자값은 3개이다.

         - 24: num of rows on the screen
         - 80: num of column count
         - 26: num of alphabet letter

      하지만 이 숫자는 코드상에 등장하지 않는다.

   주요한 역할을 하는 숫자에 적절한 이름을 주는 것으로,
   우리는 코드의 흐름을 더욱 분명하게 할 수 있다.
   예를 들어, 3은 (80 - 1)/26에서 오는데, 그 let은 27이 아닌 26을 가져야한다.
   (1 차이로 발생하는 에러는 아마도 0이 아닌 1-indexed된 스크린이 조정하면서 생기는 것일 것이다.)

   - better_histogram_\
      이제 메인루프에서 무엇을 하는지 더욱 분명히 알 수 있다.
      ``MAXROW, MINCOL``\같은 네이밍 덕에 어떤 동작을 하는 것인지
      분명하게 알 수 있게 됐다.

      가장 중요한 것으로는, 이제 이 프로그램을 다른 데이터의 길이에
      맞춰서 조정할 수 있게 되었다는 것이다.

.. _better_histogram: ./srcs/histogram_better.c
.. _histogram: ./srcs/histogram.c

Define numbers as constants, not macros
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   C프로그래머들은 전통적으로 ``#define``\을 사용하여 상수들을 정의해 왔다.
   C의 전처리기는 매우 강력한 도구이지만, 매크로들은 프로그램하기에 위험하다.
   왜냐하면, 그들은 프로그램의 단어적구조를 바꾸기 때문이다.

   언어가 적절히 일을 수행할 수 있도록 두어야 한다.
   C나 CPP에서 정수의 상수들은 ``enum``\statement을 통해서 정의될 수 있다.
   
Exercise
^^^^^^^^

1. Exercise-\:

.. _Exercise-:
