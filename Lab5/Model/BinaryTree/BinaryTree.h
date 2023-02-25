#pragma once
#include "BinaryTreeNode.h"

/**
 * @brief Бинарное дерево.
 * 
 */
struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;
};

/**
 * @brief Добавляет элемент в дерево.
 * 
 * @param tree Указатель на дерево.
 * @param data Значение.
 * @return true Успешно добавлено.
 * @return false Не удалось добавить.
 */
bool AddElement(BinaryTree* tree, int data);

/**
 * @brief Находит родительский узел.
 * 
 * @param node Узел.
 * @param data Значение.
 * @return BinaryTreeNode* Указатель на родительский узел. 
 */
BinaryTreeNode* FindParentNode(BinaryTreeNode* node, int data);

/**
 * @brief Удаляет элемент из дерева.
 * 
 * @param root Указатель на корень дерева.
 * @param data Значение.
 * @return true Успешно удалено.
 * @return false Не удалось удалить.
 */
bool RemoveElement(BinaryTreeNode*& root, int data);

/**
 * @brief Находит элемент в дереве.
 * 
 * @param node Узел.
 * @param data Значение.
 * @param parentNode Родительский узел.
 * @return BinaryTreeNode* Указатель на узел.
 */
BinaryTreeNode* FindElement(BinaryTreeNode* node, int data, BinaryTreeNode*& parentNode);

/**
 * @brief Находит минимальный элемент в дереве.
 * 
 * @param node Узел.
 * @param parentNode Родительский узел. 
 * @return BinaryTreeNode* Указатель на узел.
 */
BinaryTreeNode* FindMin(BinaryTreeNode* node, BinaryTreeNode*& parentNode);

/**
 * @brief Находит максимальный элемент в дереве.
 * 
 * @param node Узел.
 * @param parentNode Родительский узел. 
 * @return BinaryTreeNode* Указатель на узел.
 */
BinaryTreeNode* FindMax(BinaryTreeNode* node, BinaryTreeNode*& parentNode);

/**
 * @brief Удаляет дерево.
 * 
 * @param currentNode Узел.
 */
void DeleteBinaryTree(BinaryTreeNode* currentNode);