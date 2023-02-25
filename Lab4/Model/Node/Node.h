#pragma once
#include <string>

//TODO: DONE

/**
 * @brief Реализует представление элемента.
 * 
 */
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