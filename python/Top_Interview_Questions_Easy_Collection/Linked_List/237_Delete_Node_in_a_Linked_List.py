"""
Question:
	Delete Node in a Linked List
See:
	https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/
"""


class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None


class Solution:
	def deleteNode(self, node):
		"""
		:type node: ListNode
		:rtype: void Do not return anything, modify node in-place instead.
		"""

		node.val, node.next = node.next.val, node.next.next
