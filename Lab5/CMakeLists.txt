cmake_minimum_required(VERSION 3.0.0)
project(SD VERSION 0.1.0)
include_directories(Model)
include_directories(Stack)
include_directories(Services)

set(VALIDATOR Services/Validator.cpp Services/Validator.h)
set(MENU Menu/MenuBinaryTree.cpp Menu/MenuBinaryTree.h Menu/MenuTreap.cpp Menu/MenuTreap.h)
set(TREAP Model/Treap/Treap.h Model/Treap/Treap.cpp Model/Treap/TreapNode.h)
set(BINARYTREE Model/BinaryTree/BinaryTree.cpp Model/BinaryTree/BinaryTree.h Model/BinaryTree/BinaryTreeNode.h)

add_executable(Lab5 main.cpp ${VALIDATOR} ${MENU} ${TREAP} ${BINARYTREE})

set(CMAKE_CXX_STANDARD 17)

