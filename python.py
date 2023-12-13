import graphviz

# class TreeNode:
#     def __init__(self, value):
#         self.value = value
#         self.left = None
#         self.right = None

# def generate_dot(tree_node, dot, parent_id=None, index=None):
#     if tree_node is not None:
#         node_id = f"node_{tree_node.value}_{index}"
#         dot.node(node_id, str(tree_node.value))

#         if parent_id is not None:
#             dot.edge(parent_id, node_id)

#         generate_dot(tree_node.left, dot, node_id, "L")
#         generate_dot(tree_node.right, dot, node_id, "R")

# def visualize_binary_tree(root):
#     dot = graphviz.Digraph(comment='Binary Tree')
#     generate_dot(root, dot)
#     dot.render('tree', format='png', cleanup=True)

# # Example Usage:
# # Construct a sample binary tree
# #        1
# #       / \
# #      2   3
# #     / \
# #    4   5
# root = TreeNode(1)
# root.left = TreeNode(2)
# root.right = TreeNode(3)
# root.left.left = TreeNode(4)
# root.left.right = TreeNode(5)

# # Visualize the initial state of the binary tree
# visualize_binary_tree(root)

def visualize_binary_tree(root):
    dot = graphviz.Digraph(comment='Binary Tree', executable='path/to/dot')
    generate_dot(root, dot)
    dot.render('tree', format='png', cleanup=True)
