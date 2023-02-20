#pragma once

struct BinaryTreeNode
{
    /**
     * @brief Значение.
     * 
     */
    int Data = 0;

    /**
     * @brief Указатель на левый узел.
     * 
     */
    BinaryTreeNode* Left = nullptr;

    /**
     * @brief Указатель на правый узел.
     * 
     */
    BinaryTreeNode* Right = nullptr;
};