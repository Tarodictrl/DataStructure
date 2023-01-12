#pragma once
#include <string>

struct Node 
{
    /**
     * @brief Указатель на следующий элемент.
     * 
     */
	Node* Next = nullptr;

    /**
     * @brief Значение.
     * 
     */
	std::string Value;

    /**
     * @brief Ключ.
     * 
     */
	std::string Key;
};