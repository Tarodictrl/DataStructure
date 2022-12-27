#include "StackQueue.h"
#include "../Model/Stack/Stack.h"

StackQueue* InitStackQueue(int size)
{
	StackQueue* queue = new StackQueue();

    queue->InputStack = InitStack(size);
    queue->OutputStack = InitStack(size);

	return queue;
}

void Enqueue(StackQueue* queue, int data)
{
	Push(queue->InputStack, data);
}

int Dequeue(StackQueue* queue)
{
	if (IsEmptyStack(queue->OutputStack))
	{
		while (!IsEmptyStack(queue->InputStack))
		{
			int data = Pop(queue->InputStack);
			Push(queue->OutputStack, data);
		}
	}

	return Pop(queue->OutputStack);
}

int LengthStackQueue(StackQueue* queue)
{
	return (queue->InputStack->Top + 1) + (queue->OutputStack->Top + 1);
}

void DeleteStackQueue(StackQueue* queue)
{
	Delete(queue->InputStack);
	Delete(queue->OutputStack);
	delete queue->InputStack;
	delete queue->OutputStack;
}