### binary search tree inorder traversal is always sorted

**inorder traversal**


Left->Root->Right

in Bst the search complexity is O(height)

if(skewed ) then the search is o(n) to find the node


in Bst inorder successor always have eiher 0 or 1 child why ?

In a BST, the inorder successor of a node is the smallest node greater than it.
That successor is always the leftmost node in the node’s right subtree (if it exists).
Being the leftmost means it cannot have a left child, but it may have a right child.
Therefore, the inorder successor has either 0 or 1 child, never 2.