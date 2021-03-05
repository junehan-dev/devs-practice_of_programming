Elements_of_programming_style_
=============================

.. _Elements_of_programming_style: https://www.youtube.com/watch?v=8SUkrR7ZfTA


1. Dont be too clever
---------------------

.. code-block:: c

   if (Armed ? vcnt >= Threshold : vcnt <= Threshold)
       // chk if exceed threshold.

- Comment sucks.

.. code-block:: c

   if (Armed && (vcnt >= Threshold) || !Armed && (vcnt <= Threshold))


#. Dont be dumb either
----------------------

.. code-block:: c

   char blank[] = " ";

   if (strncmp(str, blank, 1) != 0) {
       if((strcmp(str, "0") >= 0 && (strcmp(str, "9")) {
           (void) strncpy(str1, str, 1);
       };
   };

.. code-block:: c

   if (str[0] != ' ') {
       if (isdigit(str[0])) {
           str1[0] = str[0];
       };
   };


#. Keep it Simple
-----------------

.. code-block:: c

   char *remove_all_spaces(char *data) {
       char *ptr;
       int	length = strlen(data);

       ptr = data;
       while ((ptr = strpbrk(data, " ")) {
           memmove(ptr, ptr + 1, strlen(ptr) + 1);
           length--;
       }
       // Terminate at new str length.
       data[length] = '\0';
       return (data);
   }
  
.. code-block:: c

   char *remove_all_spaces(char *data) {
       char *in, *out;

       out = data;
       in = out;
       while (*in != '\0') {
           if (*in != ' ')
               *out++ = *in;
           in++;
       };

       *out = '\0';
       return (data);
   }
 
#. Know Your language
---------------------

.. code-block:: c

   if (i == 0) c = '0';
   if (i == 1) c = '1';
   if (i == 2) c = '2';

.. code-block:: c

   if (i >= 0 && i <= 2)
       c = i + '0';
       
#. Avoid macros in C and Cpp
----------------------------

It can evalutated twice, depends on expression.

#. Dont sacrifice clarity for efficiency
----------------------------------------

#. Use the idioms of your language
----------------------------------

Why Idioms matter_1
^^^^^^^^^^^^^^^^^^^

.. code-block:: c

   int *array = calloc(n, sizeof(int));
   for (i = 0; i <= n; i++)
       array[i] = i;

.. code-block:: c

   int *array = calloc(n, sizeof(int));
   for (i = 0; i < n; i++)
       array[i] = i;

Why Idioms matter_2
^^^^^^^^^^^^^^^^^^^

.. code-block:: c

   p = malloc(strlen(s));
   strcpy(p, s);

.. code-block:: c

   p = malloc(strlen(s) + 1);
   strcpy(p, s);


#. Test Programs at their boundaries
------------------------------------

.. code-block:: c

   char *remove_trailing_asterisk(char *data) {
       int i;

       /* should it be i >= 0? */
       for (i = (strlen(data) - 1); i > 0; i--) {
           if (data[i] == '*')
               data[i] = '\0';
       }
       return (data);
   }

#. Program defensively: Check parameters
----------------------------------------

.. code-block:: c

   /* if buf is NULL it would be disaster */
   float st_stdev(float *buf, int M)
   {
       double stdev = 0;
       int m;
       float mean = st_mean(buf, M);


       for (m = 0; m < M; m++)
           stdev += (buf[m] - mean) * (buf[m])
       return sqrt(stdev / (M - 1));
   }

#. Program defensively: don't trust input
-----------------------------------------

Buffer over-run
^^^^^^^^^^^^^^^

.. code-block:: c

   #define SIZE 10

   main() {
       static char number[SIZE];

       puts("enter an integer, please.");
       gets(number);
       if (number[SIZE - 1] != '\0') {
           puts("Too many digits, you wiped me out.");
           exit(1);
       }
       /* ... */
   }

*Observation, [Writing_secure_code]_ by Howard and Blanc*

.. [Writing_secure_code] "Always validate all your inputs -- the world outside your function should be
   treated as hostile(=warlike) and bent upon your destruction."

#. Put regularity in control flow, irregularity in data

.. code-block:: c

   static int xy[] = {
       50, 5,
       50, 10,
       1, 1,
       98, 1,
       1, 10,
       25, 1,
       25, 1,
       25, 1,
       25, 1,
       1, 10,
       -1, -1,
   };
   /* ... */
   for (i = 0; xy[i] != -1; i += 2)
       if ((new = append_char(ch++, xy[i], xy[i + 1]))
           return (false);
   return (true);

**Clean Separation between the data and the code.**
This is general principle.
Data could be dirty, code should be clean.
