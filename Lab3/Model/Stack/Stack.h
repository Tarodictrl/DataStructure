
/**
 * @brief Хранит данные о стеке.
 * 
 */
struct Stack
{
    int* Buffer;
	int Top;
	int Capacity;
	const int GrowthFactor = 2;
};

/**
 * @brief Инициализирует стек.
 * 
 * @param size размер стека.
 * @return Stack* указатель на стек.
 */
Stack* InitStack(int size);

/**
 * @brief Проверяет необходимость изменения размера стека.
 * 
 * @param stack указатель на стек.
 */
void CheckResize(Stack* stack);

/**
 * @brief Изменяет размер стека.
 * 
 * @param stack указатель на стек.
 */
void Resize(Stack* stack);

/**
 * @brief Добавляет элемент в конец стека.
 * 
 * @param stack указатель на стек.
 * @param data данные, которые нужно добавить в стек.
 */
void Push(Stack* stack, int data);

/**
 * @brief Получить элемент из стека.
 * 
 * @param stack указатель на стек.
 * @return int элемент из стека.
 */
int Pop(Stack* stack);

/**
 * @brief Проверяет стек на пустоту.
 * 
 * @param stack указатель на стек.
 * @return true если стек пуст.
 * @return false если стек не пуст.
 */
bool IsEmptyStack(Stack* stack);

/**
 * @brief Удаляет стек.
 * 
 * @param stack указатель на стек.
 */
void Delete(Stack* stack);