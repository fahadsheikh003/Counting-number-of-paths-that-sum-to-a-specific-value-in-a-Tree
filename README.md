# Counting-number-of-paths-that-sum-to-a-specific-value-in-a-Tree

# Problem:
You are given a binary tree in which each node contains an integer value (which might be positive or negative). Write a function to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes). The tree and value are passed as an argument to the function. The path count is returned by the function. Sum of a path is the sum of all node values in that path.

EXAMPLE Input:
Tree =
![image](https://user-images.githubusercontent.com/87650614/151612052-f7a38720-fa61-4e3f-b327-976babd6176c.png)
Value = 9
Output: 2 path

# Explanation of Implementation:
In this problem, I have applied the divide & conquer technique. Firstly, I made a recursive function named “pathcheck” to count number of paths of nodes from the specified node that sum to a specified value. I calculated the sum that is passed into the function by adding the value of the current node and checked if it is equal to specified value, if it then increments the path variable and repeats the process above for left and right subtrees. I called above function for all the nodes of the Tree to get all the number of paths in the Tree that sums to a specified value.
