Data Structure
==============

2.8 Trees
---------

Intro
^^^^^

A tree is hierarchical data structure that stores a set of items in which each item has value
   - May point to zero or more others.
   - Is pointed to by exactly one other.
   - The root of the tree is the sole exception: no item points to it

We will illustrate the principles with,

*binary search trees* 
^^^^^^^^^^^^^^^^^^^^^

**Which have two links at each node.**
   They are easiest to implement, and demonstrate the essential properties of trees.
   A node in a binary search tree has value and two pointers, ``left`` and ``right`` that point to its children.

Charateristics::

   - The child pointers may be null if the node has fewer than two children.
   - In a binary search tree, the values at the nodes define the tree.
   - all children to the left of a particular node have lower values, all children to the right have higher values.

.. code-block:: c

   typedef struct Node Node;
   struct Node {
   	char	*name;
   	int		value;
   	Node	*left;
   	Node	*right;
   };

This version of ``insert`` complains about attempts to insert duplicate entries (cmp == 0) in the tree.

1. ft_btree_insert.c_: Insert node (bin search)
   Insert routine didn't complain because that would require searching the list, making insertion *O(n)* rather than *O(1).*
   However With trees, the test is essentially free,
   and the properties of the data structure are not as clearly defined if there are not as clearly defined if there are duplicates.
   (In other applications, though, it might be necessary to accept duplicates, or it might be reasonable to ignore them completely.)

2. ft_btree_lookup.c_: Balanced Tree ( bin search, *tail recursion* )
   **If Items are inserted into a tree as they arrive,**
   The Tree might not be balanced.
   In fact, it might be badly unbalanced.

   **If the elements arrive already sorted,**
   *(The code will always descend down one branch of the tree,)*
   producing in effect a list down the right links, with all performance problems of a list.

   It is complicated to implement trees *that are guaranteed to be balanced.*
   (:This is one reason there are many kinds of trees.)
   For out purpose, we'll just sidestep the ussue and assume that incoming data is sufficiently random to keep the tree balanced enough.

.. _ft_btree_insert.c: srcs/ft_btree_insert.c
.. _ft_btree_lookup.c: srcs/ft_btree_lookup.c

.. note::

   If They are rewritten as iterative algorithms,
   they will be even more similar to binary search.

3. ft_btree_nrlookup.c_: non recursive version lookup
   lookup can be converted to iteration by patching up the arguments and restarting the routine.
   The most direct method is to use ``goto`` statement,
   but while loop is cleaner.

