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


