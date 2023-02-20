 #pragma once
#include "TreapNode.h"

/**
 * @brief Структура декартового дерева.
 */
struct Treap
{
	/**
	 * @brief Максимальный приоритет.
	 */
	const int MaxPriority = 100;

	/**
	 * @brief Корень дерева.
	 */
	TreapNode* Root = nullptr;
};

/**
 * @brief Разбивает дерево на два.
 */
void Split(TreapNode* tree, int key, TreapNode*& left, TreapNode*& right);

/**
 * Сливает два дерева.
 */
TreapNode* Merge(TreapNode* left, TreapNode* right);

/**
 * @brief Оптимизированно добавляет элемент в дерево.
 */
void AddOptimized(TreapNode*& root, int data, int priority);

/**
 * @brief Не оптимизированно добавляет элемент в дерево.
 */
void AddNotOptimized(TreapNode*& root, int data, int priority);

/**
 * @brief Удаляет не оптимизированный элемент из дерева.
 */
TreapNode* RemoveNotOptimized(TreapNode*& root, int data);

/**
 * @brief Удаляет оптимизированный элемент из дерева.
 */
bool RemoveOptimized(TreapNode*& root, int data);

/**
 * @brief Удаляет дерево.
 */
void DeleteTreap(TreapNode*& node);

/**
 * @brief Поиск элемента в дереве.
 */
TreapNode* FindElement(TreapNode* node, int data);