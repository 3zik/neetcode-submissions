# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 1. if the current node is null, return null
        # 2. swap the nodes L and R ptrs
        # 3. Recursively call dfs on new L child
        # 4. Recursively call dfs on new R child
        # 5. return current node (now inverted)

        if not root:
            return None

        tmp = root.left
        root.left = root.right
        root.right = tmp

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root



