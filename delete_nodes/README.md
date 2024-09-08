## ✨ Solution: Delete Nodes From Linked List Present in Array ✨
---
<br>

**Approach 🤔💭:**

Hash Table for Efficient Lookups
In this problem, we are tasked with removing all nodes from a linked list whose values exist in a given array (nums). To solve this efficiently, we can make use of a hash table to track the presence of the values in nums, ensuring O(1) time complexity for checking if a value needs to be removed.

**Key Idea 💡 :**
We first create a hash table (boolean array) where each index represents a possible node value, and the value at that index is either true (if the number is present in nums) or false (if it's not in nums).
We then traverse the linked list and for each node:
Check if the node’s value exists in the hash table.
Remove the node by skipping it if it exists.
Otherwise, retain the node.

**Steps :**

1. *Hash Table Construction* 🗂️ :

We initialize a boolean hash table of size 100001 (since values in the linked list and nums are constrained between 1 and 100000). This hash table allows constant-time lookups to efficiently check whether a node’s value is present in nums.

2. *Dummy Node* 🛠️ :

A dummy node is used to handle cases where the first node of the list needs to be removed, avoiding edge-case issues when removing the head node.

3. *List Traversal* 🚶‍♂️:

We traverse the list and for each node:

If its value exists in the hash table, we adjust the pointers to skip and remove the node.
If it doesn’t exist, we retain the node and move forward without removing it.
This efficient approach ensures that we only pass through the list once, maintaining optimal time complexity while minimizing edge cases through the use of the dummy node.

---

👇 Check out the full code and more solutions on my

# 🐈‍⬛ Github ▸ [My_leetcode_repo](https://github.com/yaasinslami/leetcode)