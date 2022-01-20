1-03_Consistency and idioms
---------------------------

일관성은 더 나은 프로그램으로 이끈다.
변칙적인 것은 프로그램의 동작방식을 이해하기 어렵게 만든다.

Use a consistent indentation and brace style
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- 프로그램 레이아웃 중에 구조가 잘 보인다고 생각하는 것을 고르고 쭉 유지하고 논쟁에 시간낭비하지 말자.
- 경험있는 프로그래머들은 항상 brace를 사용하지만, single statment의 경우 생략한다.

   - Bad

      .. code-block:: c

         if (month == FEB) {
         	if (year%4 == 0)
         		if (day > 29)
         			legal = FALSE;
         	else
         		if (day > 28)
         			legal = FALSE;
         }

      들여쓰기가 잘못 되어있다. ``else``\는 ``if (day >29)``\에 적용되기 때문이다.
      코드 또한 오류가 있다. ``if``\뒤에 추가적인 연쇄동작이 있다면 항상 중괄호를 사용해야한다.

   - FIX#1

      .. code-block:: c

         if (month == FEB) {
         	if (year%4 == 0) {
         		if (day > 29)
         			legal = FALSE;
         	} else {
         		if (day > 28)
         			legal = FALSE;
         	}
         }

      Syntax-driven 편집기 도구는 이런 실수들을 덜 발생토록 한다.
      버그가 수정되었지만 여전히 코드는 이해하기 어렵다.
      우리가 days in FEB변수를 명시적으로 사용한다면 computation은 더욱 쉽게 보여질 것이다.

   - FIX#2

      .. code-block:: c

         if (month == FEB) {
         	int nday;

         	nday = 28;
         	if (year%4 == 0)
         		nday = 29;
         	if (day > nday)
         		legal = FALSE;
         }

      그래도 여전히 코드는 잘못 되었다.
      2000는 leap year이지만, 1900 2100은 아니다.
      하지만 이 구조는 실수를 수정하기에 더욱 쉬워졌다.

- 만약 내가 작성하지 않은 프로그램으로 작업할 때는 기존 스타일을 유지하자.

   - 프로그램의 일관성이 당신의 스타일보다 중요하다. 왜냐하면 이것을 따르는 사람들의 삶을 편하게 해줄 것이기 때문이다.

Use idioms for consistency
^^^^^^^^^^^^^^^^^^^^^^^^^^
   일반언어처럼, 프로그래밍 언어들도 관용구와 경험있는 프로그래머들이 사용하는 관습적인 방식이 있다.
   어떤 언어를 배우는 핵심적인 부분은 그것의 idioms를 사용하여 친밀함을 발전시키는 것이다.

- indentation 또한 idiomatic해야 할 것이다.
- 지속적으로 idioms를 사용하는 이점 중 하나는, 표준이 아닌 형태의 것을 눈에 띄게 한다는 것이다.

   .. code-block:: c

      int i, *iArray, nmemb;
      
      iArray = malloc(nmemb * sizeof(int));
      for (i = 0; i <= nmemb; i++)
      	iArray[i] = i;

   ``i <= nmemb``\이 ``iArray[nmemb - 1]``\를 벗어난 coredump segfault를 일으키게 될 것이다.
   불행하게도 이런 식의 오류는 동작오류가 발견되고 나서야 발견되기 쉽다.
- C 와C++은 문자열 메모리할당과 조작에 대한 idioms를 가지고 있고, 그것을 사용하지 않는 코드는 버그가능성이 높다.
   .. code-block:: c

      char *p, buf[256];
      
      gets(buf);
      p = malloc(strlen(buf));
      strcpy(p, buf);

   1. ``gets(stream_pt)``\를 사용하지 말것.

      - (입력제한을 둘 수 없기 때문에)
      - ``fgets(dest, size, stream_pt)``\를 사용하는게 항상 나은 선택임을 추후 Chapter6에서 다룬다.
   #. ``strlen``\은 null-termination을 포함하지 않고 ``strcpy``\는 그것을 포함한다.

      - idiom for malloc string in c. 

         .. code-block:: c

            p = malloc(strlen(buf) + 1);
            strcpy(p, buf);

      - ``strdup``\같은 lib func를 사용하면 쉽게 이런 버그를 피할 수 있다. (불행히도 ANSI C standard 함수가 아니다.)
   #. 그러나 위 어디서도 ``malloc``\유효성 체크를 하지 않았다. idiom에 집중하기 위해서 그 부분은 생략한다.

      (*하지만 실제 프로그램에서* ``malloc, relloc, strdup``\*등 mem allocation routine을 사용하면 반드시 체크되어야 한다.*)

Use else-ifs for multi-way decisions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- 연속적인 if-else의 중첩은 **때로는*** 괴랄한 코드에 대한 경보가 된다.

   .. code-block:: c

      if (argc == 3)
      	if ((fin = fopen(argv[1], "r")) != NULL)
      		if ((fout = fopen(argv[2], "w")) != NULL) {
      			while ((c = getc(fin)) != EOF)
      				putc(c, fout);
      			fclose(fin); fclose(fout);
      		} else
      			printf("Cant open output file\n");
      	else
      		printf("Cant opent input file\n");
      else
      	printf("Usage Error\n");

   - *ifs*\의 연속은 우리에게 정신적인 stack 유지를 요구한다.

- 결정들이 더 나은 버전으로 이어지도록 순서를 변경한다.

   .. code-block:: c

      if (argc != 3)
      	printf("Usage Error\n");
      else if ((fin = fopen(argv[1], "r")) == NULL)
      	printf("Cant opent input file\n");
      else if ((fin = fopen(argv[1], "r")) == NULL) {
      	printf("Cant open output file\n");
      	fclose(fin);
      } else {
      	while ((c = getc(fin)) != EOF)
      		putc(c, fout);
      	fclose(fin);
      	fclose(fout);
      }

   - 하나의 테스트와 부합하는 action로 연결되고 순차적인 Else를 진행한다.
   - 이 규칙은, 개별 결정을 관련된 행동으로 가능한 가깝게 연결하는 것이다.

Exercise
^^^^^^^^

1. Exercise-1-7_\: Rewrite these C/C++ excerpts more clearly.
#. Exercise-1-8_\: Identify the errors in this Java fragment and repair it by rewriting with ad idiomatic loop.

.. _Exercise-1-7: ./srcs/ex1-7-rewrite_to_clear.c
.. _Exercise-1-8: ./srcs/ex1-8-find_error_and_repair.java
