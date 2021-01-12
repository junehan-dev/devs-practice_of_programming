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

- The principles of programming style are based on
common sense guided by experience not on arbitray rules.
- Code should be clear and simple, 
   - straightforward logic, natural expression, conventional language use, meaningful names, neat formatting, helpful comments

1-01_Names
----------

- *Use descriptive names for globals, short names for locals.*

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

