1-04_Function Macros
--------------------

기존 C프로그래머들은 정말 짧은 컴퓨팅을 위해서는 매크로를 쓰는 경향이 있다. (``getchar``\, ``isdigit``)

   그것은 함수 호출에 대한 오버헤드를 줄일 수 있기 때문이고, 과거의 컴퓨터 자원은 비쌌기 때문에 이에대해 논쟁은 필요 없었다.
   그러나 지금 시대의 컴퓨터, 컴파일러에 있어서는 관련없는 얘기이고, 그들에서 오는 이득은 그들이 주는 약점에 비해 초라하다.

1. Avoid function macros.

   - macro의 parameter 평가방식은 에러를 일으키기 쉽다.
   - 평가의 중복은 결과 값의 에러보다 퍼포먼스 문제를 주로 야기한다.

#. Parenthesize the macro body and arguments.

   - 매크로는 함수의 call-ret방식이 아닌, text substitution방식으로 동작한다.

      .. code-block:: c

         #define square(x) (x) * (x)
         
         1 / squre(x);

      위 경우, ``1 / (x * x)`` 로 평가되지 않고,
      ``1 / (x) * (x)``\로 expand된다.
      따라서, 아래와 같이 수정되어야 한다.

      ``#define square(x) ((x) * (x))``

   - C++의 inline함수들은 macro가 주는 이점은 주면서도, 의미적인 문제는 피한다. 그들은 하나의 값을 가져오는 동작의 짧은 함수들에 적합하다.

Exercise
^^^^^^^^

1. Exercise-1-9_\: Identify the problems with this macro definition.

.. _Exercise-1-9: ./srcs/ex-1-9-find_problems_in_macro.h
