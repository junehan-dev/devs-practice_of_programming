1-02_Expressions and statements
-------------------------------

(가독성을 올리기 위해 이름을 고르는,)논리적 유추에 의해서 표현과 구문들을 의미가 투명하게 전달되도록 작성해야한다.

   - 이름을 잘 지어도, implementation 쪽에서 operations가 조잡하다면 생기는 문제.
   - 특정 목적을 도달하는 가장 명료한 방식을 선택해야한다.
   - operator는 grouping을 위해 space를 취해 가독성을 올린다.

   *"당신이 물건을 쉽게 찾을 수 있도록, 책상을 깔끔하게 정리하는 것이다. 하지만 책상과 다르게, 그 프로그램은 다른사람에 의해 사용되는 것이다."*

Indent to show structure
^^^^^^^^^^^^^^^^^^^^^^^^
   *"꾸준한 indent 스타일은 프로그램의 구조를 스스로 증명할 수 있는 방법중 가장 에너지 소모가 적은 방법이다."*

- Bad-formatted:

   .. code-block:: c

      for(n++;n<100;field[n++]='\0');
      *i = '\0'; return('\n');

- Improved:


   .. code-block:: c

      for (n++; n < 100; field[n++] = '\0')
      	;
      *i = '\0';
      return ('\n');

   더 나은 방법은, 할당operator를 for statement의 body에 넣어 increment와 분리하는 것이다.

      이로 인해, loop는 더욱 conventional form을 취하게 되어 조작하기 쉬워진다.

- Better:

   .. code-block:: c

      for (n++; n < 100; n++)
      	field[n] = '\0';

   때로 영리한 trick을 우리는 사용하지만, 그것이 접근성을 줄인다고 생각될 가능성이 있으며 trick이 불가피한 것이 아니라면 좀 더 정직한 방식을 선택하는 것.

Use the natural form for expressions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   *"당신이 그들을 크게 소리내 읽는 것과 동일한 행동으로 간주하고, 표현을 작성하라."*

- hard to understand:

   ``if (!(block-id < actblks) || !(block-id >= unblocks))``

      Test들은 부정형으로 진술되어 있다.

         이들은 불필요한데도 둘다 그렇게 되어있다.

- Better:

   ``if ((block-id >= actblks) || (block-id < unblocks))``

      이제 자연스러운 방식으로 읽혀질 것이다.

Parenthesize to resolve ambiguaty
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

비록 praentheses가 필수적이지 않더라도, 처음 봤을 때 연산 순서를 쉽게 구별할 수 있도록 도와준다.

- Hard to group:

   ``leap-year = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;``

- easier to group:

   ``leap_year = ((y%4 == 0) && (y%100 != 0) || (y%400 = 0))'``

   - 일부 space를 지웠는데, 이것 또한 group의 일환으로 higher precedence를 표현하는 방식이다.

Break up complex expressions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   C, C++, Java는 풍부한 표현 구문과 연산자를 가지고 있으며, one-construction으로 밀어넣을 수(cramming) 있다.

- compact but packs too many operations in single statement:

   ``*x += (*xp=(2*k < (n-m) ? c[k+1] : d[k--]));``

- Easier to grasp when broken into several pieces:

   .. code-block:: c

      if (2*k < n-m)
      	*xp = c[k+1];
      else
      	*xp = d[k--];
      *x += *xp;

Be clear
^^^^^^^^
   *"영리한 코드가 아니라, 명료한 코드를."*

가끔 우리는 문제를 해결하기 위해, 세련된 방식이나 영리한 방식을 선택하기도 한다.

   그러나 이러한 스킬이 때로는 나쁘게 적용되기도 한다.

이 조잡한 계산은 무엇을 하는가?

   1. ``subkey = subkey >> (bitoff - ((bitoff >> 3) << 3));``

      첫 버전은 파악하는데 조금 시간이 걸린다.
   #. ``subkey >> (bitoff & 0b111)``

      두 번째 버전은 더욱 짧고 분명해졌다.
   #. ``subkey >>= bitoff & 0x7;``

      경험있는 프로그래머는 이것을 더욱 짧게 만든다.

   - ``child=(!LC&&!RC)?0:(!LC?RC:LC);``

      이것이 무엇을 하는지 맞추는 것은 거의 불가능하다.
      아래의 형태는 더욱 길어졌지만, 훨씬 추적하기 쉽다. 분기를 명시적으로 표기하기 때문이다.

         .. code-block:: c

            if (!LC && !RC)
            	child = 0;
            else if (!LC)
            	child = RC;
            else
            	child = LC;

      Ternary operator는 4-줄의 if-else구문을 한줄의 짧은 표현으로 대체하기에는 괜찮다.
      *(위의 구문은*\ ``if-elseif-else``\* 최소 6줄의 구문.)*

Clarity는 Brevity와 다르다. 때로, 깔끔한 코드는 더욱 짧기도 하지만, 또한 더 길어질 수 도 있다.
적절한 기준은 쉬운 이해에 달려있다.

Be careful with side effects
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Operator like ``++`` have side effects.

   side effects는 때로 심각하게 편리하지만, 그들은 때로 문제를 일으키는데, 값을 추적하는 시점과, 값을 수정하는 시점이 다르기도 하고, 프로그래머의 예상을 벗어나기도 하기 때문이다.

   - ``str[i++] = str[i++] = ' ';``

      when really i++ updated? 2개의 statement로 나누자.

      - ``str[i++] = ' '; str[i++] = ' ';``

   - ``array[i++] = i;``

      이것에는 오직 하나의 후위증가 연산이 있지만, 이 할당은 다양한 결과를 줄 수 있다.
      만약 i가 기본적으로 3이었다면, 이 값은 3 또는 4가 할당될 것이다.

증감연산만이 side effect를 가진 것은 아니다.
I/O는 또다른 behind-the-scenes action이다.

   - ``scanf("%d %d", &yr, &profit[yr]);``

      이것은 yr이 사용중인 와중에 yr을 수정하기 때문에, 망가진 표현이다.

         - 오직 ``yr``\의 새로운 값이, 기존의 값과 같을 때에만 ``&profit[yr]``\이 올바른 정보가 될 것이다.
         - 가장 큰 문제는 scanf에 대한 모든 argument는 routine이 호출되기 이전에 평가된다는 것이다. 따라서, ``&profit[yr]``\은 항상 ``scanf``\이전의 ``yr``\을 사용할 것이다.
         - 이 오류의 해결책은 여전히 표현을 분산하는 것이다.

   - ``scanf("%d", &yr); scanf("%d", &profit[yr]);``

Exercise
^^^^^^^^

1. Exercise-1-4_\: Improve each of these fragments.
#. Exercise-1-5_\: What is worng with the excerpt?
#. Exercise-1-6_\: List all the diffenet outputs this could produce with various order of evaluation.

.. _Exercise-1-4: ./srcs/ex04.c
.. _Exercise-1-5: ./srcs/ex05.c
.. _Exercise-1-6: ./srcs/ex06.c

