#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
using namespace std;


// empty_impl
TEST (empty)
{
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());

    tree.insert(5);
    ASSERT_FALSE(tree.empty());
}


// size_impl
TEST(size)
{
    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.size(), 0);

    tree.insert(5);
    ASSERT_EQUAL(tree.size(), 1);

    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    tree.insert(10);

    ASSERT_EQUAL(tree.size(), 6);
}


// height_impl
TEST(height)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    ASSERT_EQUAL(tree.height(), 1);
    tree.insert(1);
    ASSERT_EQUAL(tree.height(), 2);
    tree.insert(3);
    ASSERT_EQUAL(tree.height(), 3);
    tree.insert(6);
    ASSERT_EQUAL(tree.height(), 3);
    tree.insert(8);
    ASSERT_EQUAL(tree.height(), 3);
    tree.insert(10);
    ASSERT_EQUAL(tree.height(), 4);
    tree.insert(2);
    ASSERT_EQUAL(tree.height(), 4);
    tree.insert(4);
    ASSERT_EQUAL(tree.height(), 4);
    tree.insert(7);
    ASSERT_EQUAL(tree.height(), 4);
    tree.insert(9);
    ASSERT_EQUAL(tree.height(), 5);
}


// copy_nodes_impl
TEST(copy_nodes)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    tree.insert(10);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);

    ostringstream oss_preorder_og;
    tree.traverse_preorder(oss_preorder_og);

    ostringstream oss_preorder_copy;
    BinarySearchTree<int> tree_copy(tree);
    tree.traverse_preorder(oss_preorder_copy);

    ASSERT_EQUAL(oss_preorder_og.str(), oss_preorder_copy.str());
}


// destroy_nodes_impl


// find_impl
TEST(find)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    ASSERT_EQUAL(tree.find(4), tree.end());
    tree.insert(10);
    tree.insert(2);
    ASSERT_EQUAL(tree.find(4), tree.end());
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);

    ASSERT_EQUAL(*tree.find(5), 5);
    ASSERT_EQUAL(*tree.find(6), 6);
    ASSERT_EQUAL(*tree.find(7), 7);
    ASSERT_EQUAL(*tree.find(8), 8);
    ASSERT_EQUAL(*tree.find(9), 9);
    ASSERT_EQUAL(tree.find(11), tree.end());
    ASSERT_EQUAL(tree.find(50), tree.end());
}


// insert_impl


// min_element_impl
TEST(min_element)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    ASSERT_EQUAL(*tree.min_element(), 5);

    tree.insert(6);
    ASSERT_EQUAL(*tree.min_element(), 5);

    tree.insert(8);
    ASSERT_EQUAL(*tree.min_element(), 5);

    tree.insert(10);
    ASSERT_EQUAL(*tree.min_element(), 5);

    tree.insert(4);
    ASSERT_EQUAL(*tree.min_element(), 4);

    tree.insert(3);
    ASSERT_EQUAL(*tree.min_element(), 3);

    tree.insert(2);
    ASSERT_EQUAL(*tree.min_element(), 2);

    tree.insert(1);
    ASSERT_EQUAL(*tree.min_element(), 1);
}


// max_element_impl
TEST(max_element)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    ASSERT_EQUAL(*tree.max_element(), 5);

    tree.insert(1);
    ASSERT_EQUAL(*tree.max_element(), 5);

    tree.insert(3);
    ASSERT_EQUAL(*tree.max_element(), 5);

    tree.insert(6);
    ASSERT_EQUAL(*tree.max_element(), 6);

    tree.insert(7);
    ASSERT_EQUAL(*tree.max_element(), 7);
    
    tree.insert(8);
    ASSERT_EQUAL(*tree.max_element(), 8);

    tree.insert(9);
    ASSERT_EQUAL(*tree.max_element(), 9);

    tree.insert(10);
    ASSERT_EQUAL(*tree.max_element(), 10);
}

// check_sorting_invariant_impl
TEST(check_sorting_invariant)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    tree.insert(10);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);
    ASSERT_TRUE(tree.check_sorting_invariant());
}

  

// traverse_inorder_impl
TEST(traverse_inorder)
{
    ostringstream oss_inorder;
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "5 ");
    oss_inorder.str("");

    tree.insert(1);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 5 ");
    oss_inorder.str("");

    tree.insert(3);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 3 5 ");
    oss_inorder.str("");

    tree.insert(6);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 3 5 6 ");
    oss_inorder.str("");

    tree.insert(8);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 3 5 6 8 ");
    oss_inorder.str("");

    tree.insert(10);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 3 5 6 8 10 ");
    oss_inorder.str("");

    tree.insert(2);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 2 3 5 6 8 10 ");
    oss_inorder.str("");

    tree.insert(4);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 2 3 4 5 6 8 10 ");
    oss_inorder.str("");

    tree.insert(7);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 2 3 4 5 6 7 8 10 ");
    oss_inorder.str("");

    tree.insert(9);
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "1 2 3 4 5 6 7 8 9 10 ");
    oss_inorder.str("");
}


// traverse_preorder_impl
TEST(traverse_preorder)
{
    ostringstream oss_preorder;
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 ");
    oss_preorder.str("");

    tree.insert(1);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 ");
    oss_preorder.str("");

    tree.insert(3);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 ");
    oss_preorder.str("");

    tree.insert(6);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 6 ");
    oss_preorder.str("");

    tree.insert(8);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 6 8 ");
    oss_preorder.str("");

    tree.insert(10);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 6 8 10 ");
    oss_preorder.str("");

    tree.insert(2);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 2 6 8 10 ");
    oss_preorder.str("");

    tree.insert(4);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 2 4 6 8 10 ");
    oss_preorder.str("");

    tree.insert(7);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 2 4 6 8 7 10 ");
    oss_preorder.str("");

    tree.insert(9);
    tree.traverse_preorder(oss_preorder);
    ASSERT_TRUE(oss_preorder.str() == "5 1 3 2 4 6 8 7 10 9 ");
    oss_preorder.str("");
}


// min_greater_than_impl
TEST(min_greater_than)
{
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(1);
    ASSERT_EQUAL(*tree.min_greater_than(1), 5);
    ASSERT_EQUAL(tree.min_greater_than(5), tree.end());

    tree.insert(3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 5);
    ASSERT_EQUAL(*tree.min_greater_than(1), 3);
    ASSERT_EQUAL(tree.min_greater_than(5), tree.end());

    tree.insert(6);
    ASSERT_EQUAL(*tree.min_greater_than(1), 3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 5);
    ASSERT_EQUAL(*tree.min_greater_than(5), 6);
    ASSERT_EQUAL(tree.min_greater_than(6), tree.end());

    tree.insert(8);
    ASSERT_EQUAL(*tree.min_greater_than(1), 3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 5);
    ASSERT_EQUAL(*tree.min_greater_than(5), 6);
    ASSERT_EQUAL(*tree.min_greater_than(6), 8);
    ASSERT_EQUAL(tree.min_greater_than(8), tree.end());

    tree.insert(10);
    ASSERT_EQUAL(*tree.min_greater_than(1), 3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 5);
    ASSERT_EQUAL(*tree.min_greater_than(5), 6);
    ASSERT_EQUAL(*tree.min_greater_than(6), 8);
    ASSERT_EQUAL(*tree.min_greater_than(8), 10);
    ASSERT_EQUAL(tree.min_greater_than(10), tree.end());

    tree.insert(2);
    ASSERT_EQUAL(*tree.min_greater_than(1), 2);
    ASSERT_EQUAL(*tree.min_greater_than(2), 3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 5);
    ASSERT_EQUAL(*tree.min_greater_than(5), 6);
    ASSERT_EQUAL(*tree.min_greater_than(6), 8);
    ASSERT_EQUAL(*tree.min_greater_than(8), 10);
    ASSERT_EQUAL(tree.min_greater_than(10), tree.end());

    tree.insert(4);
    ASSERT_EQUAL(*tree.min_greater_than(1), 2);
    ASSERT_EQUAL(*tree.min_greater_than(2), 3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 4);
    ASSERT_EQUAL(*tree.min_greater_than(4), 5);
    ASSERT_EQUAL(*tree.min_greater_than(5), 6);
    ASSERT_EQUAL(*tree.min_greater_than(6), 8);
    ASSERT_EQUAL(*tree.min_greater_than(8), 10);
    ASSERT_EQUAL(tree.min_greater_than(10), tree.end());

    tree.insert(7);
    ASSERT_EQUAL(*tree.min_greater_than(1), 2);
    ASSERT_EQUAL(*tree.min_greater_than(2), 3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 4);
    ASSERT_EQUAL(*tree.min_greater_than(4), 5);
    ASSERT_EQUAL(*tree.min_greater_than(5), 6);
    ASSERT_EQUAL(*tree.min_greater_than(6), 7);
    ASSERT_EQUAL(*tree.min_greater_than(7), 8);
    ASSERT_EQUAL(*tree.min_greater_than(8), 10);
    ASSERT_EQUAL(tree.min_greater_than(10), tree.end());

    tree.insert(9);
    ASSERT_EQUAL(*tree.min_greater_than(1), 2);
    ASSERT_EQUAL(*tree.min_greater_than(2), 3);
    ASSERT_EQUAL(*tree.min_greater_than(3), 4);
    ASSERT_EQUAL(*tree.min_greater_than(4), 5);
    ASSERT_EQUAL(*tree.min_greater_than(5), 6);
    ASSERT_EQUAL(*tree.min_greater_than(6), 7);
    ASSERT_EQUAL(*tree.min_greater_than(7), 8);
    ASSERT_EQUAL(*tree.min_greater_than(8), 9);
    ASSERT_EQUAL(*tree.min_greater_than(9), 10);
    ASSERT_EQUAL(tree.min_greater_than(10), tree.end());
}

TEST_MAIN()
