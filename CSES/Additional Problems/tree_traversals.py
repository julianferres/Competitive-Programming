import sys
sys.setrecursionlimit(10**6)
n = int(input())
preorder = [int(x) for x in input().split()]
inorder = [int(x) for x in input().split()]


class BinaryTreeNode:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def binary_tree_from_preorder_inorder(preorder, inorder):
    node_to_inorder_idx = {data: i for i, data in enumerate(inorder)}

    def helper(pre_s, pre_e, in_s, in_e):
        if pre_e <= pre_s or in_e <= in_s:
            return None

        root_inorder_idx = node_to_inorder_idx[preorder[pre_s]]
        left_subtree_size = root_inorder_idx - in_s

        left_child = helper(
            pre_s+1, pre_s+1+left_subtree_size, in_s, root_inorder_idx)
        right_child = helper(pre_s+1+left_subtree_size,
                             pre_e, root_inorder_idx+1, in_e)

        return BinaryTreeNode(preorder[pre_s], left_child, right_child)

    return helper(0, len(preorder), 0, len(inorder))


tree = binary_tree_from_preorder_inorder(preorder, inorder)
postorder = []

print(tree.data)


def post(node):
    if node.left:
        post(node.left)
    if node.right:
        post(node.right)
    postorder.append(node.data)


# post(tree)
# print(*postorder)
