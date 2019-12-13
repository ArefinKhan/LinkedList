# LinkedList


This repository will contain interesting problems and C++ solutions related to LinkedList. 

weave.cpp
Given two linked lists, merge the two linked list into one list so that the relative ordering of each elements in their original list remain intact. 
For example, list1 => {1->2}, list2=> {3,4}
After merging list1 and list 2, we have 6 possibilities:
1. {1->2->3->4}
2. {1->3->2->4}
3. {1->3->4->2}
4. {3->4->1->2}
5. {3->1->4->2}
6. {3->1->2->4}

Note: We just print the values from each list, instead of constructing an actual linked list. However, we can easily construct one since we store all the nodes in a deque.
