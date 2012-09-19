////////////////////////////////////////////////////////////////////////////////
// TreeSort.cpp
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include "TreeSort.hpp"
#include <memory>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// Represent a single node. Each node has three children:
// Left:   Contain smaller values 
// Middle: Contain equal values
// Right:  Contain larger values
////////////////////////////////////////////////////////////////////////////////
struct Node
{

	////////////////////////////////////////////////////////////////////////////////
	// Construct a new node
	////////////////////////////////////////////////////////////////////////////////
	Node(int value, std::shared_ptr<Node> lhs, std::shared_ptr<Node> mhs, std::shared_ptr<Node> rhs) :
		m_value (value),
		m_lhs   (lhs),
		m_mhs   (mhs),
		m_rhs   (rhs)
	{
	}
	
	////////////////////////////////////////////////////////////////////////////////
	// Public member data
	////////////////////////////////////////////////////////////////////////////////
	int m_value;
	std::shared_ptr<Node> m_lhs;
	std::shared_ptr<Node> m_mhs;
	std::shared_ptr<Node> m_rhs;
};

////////////////////////////////////////////////////////////////////////////////
// Build the vector from the tree (sorted)
////////////////////////////////////////////////////////////////////////////////
static void build(std::vector<int>& v, const std::shared_ptr<Node>& node)
{
	// Make sure we have a valid node
	if(!node) return;

	build(v, node->m_lhs);
	v.push_back(node->m_value);
	build(v, node->m_mhs);
	build(v, node->m_rhs);
}

////////////////////////////////////////////////////////////////////////////////
// Find the node that should contain the new value and return it
////////////////////////////////////////////////////////////////////////////////
static std::shared_ptr<Node>& findNode(std::shared_ptr<Node>& node, int value)
{
	// If the node is invalid then the correct node has been found
	if(!node) return node;

	// Return the correct child depending on if it's larger or smaller
	if(value < node->m_value) 
		return findNode(node->m_lhs, value);
	else if(value == node->m_value)
		return findNode(node->m_mhs, value);
	else
		return findNode(node->m_rhs, value);
}

////////////////////////////////////////////////////////////////////////////////
void treeSort(std::vector<int>& v)
{
	std::shared_ptr<Node> root;

	// Build up the tree
	for(std::size_t i = 0; i < v.size(); ++i)
	{
		// If the tree doesn't have a valid root then create it
		if(!root)
		{
			root = std::shared_ptr<Node>(new Node(v[0], nullptr, nullptr, nullptr));
		}
		else
		{
			// Otherwise find the correct node and create it
			std::shared_ptr<Node>& node = findNode(root, v[i]);
			node = std::shared_ptr<Node>(new Node(v[i], nullptr, nullptr, nullptr));
		}
	}

	v.clear();
	build(v, root);
}