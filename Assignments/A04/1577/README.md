## 1577 - Falling Leaves

#### A binary tree of letters may be one of two things:
1. It may be empty.
2. It may have a root node. A node has a letter as data and refers to a left and 
a right subtree. The left and right subtrees are also binary trees of letters.

#### In the graphical representation of a binary tree of letters:
1. Empty trees are omitted completely.
2. Each node is indicated by
   - Its letter data,
   - A line segment down to the left to the left subtree, if the left subtree is nonempty,
   - A line segment down to the right to the right subtree, if the right subtree is nonempty.

#### The preorder traversal of a tree of letters satisfies the defining properties:
- If the tree is empty, then the preorder traversal is empty.
- If the tree is not empty, then the preorder traversal consists of the following, in order
- The data from the root node,
- The preorder traversal of the root's left subtree,
- The preorder traversal of the root's right subtree.

#### A binary search tree of letters is a binary tree of letters in which each node satisfies:
- The root's data comes later in the alphabet than all the data in the nodes in the left subtree.
- The root's data comes earlier in the alphabet than all the data in the nodes in the right subtree.

##### Input

The input will contain one or more data sets. Each data set is a sequence of one or more lines of 
capital letters. The lines contain the leaves removed from a binary search tree in the stages described 
above. The letters on a line will be listed in increasing alphabetical order. Data sets are separated 
by a line containing only an asterisk ('*'). The last data set is followed by a line containing only 
a dollar sign ('$'). There are no blanks or empty lines in the input.

##### Output

For each input data set, there is a unique binary search tree that would produce the sequence of 
leaves. The output is a line containing only the preorder traversal of that tree, with no blanks.

##### Sample Input

BDHPY
CM
GQ
K
*
AC
B
$

##### Sample Output

KGCBDHQMPY
BAC

