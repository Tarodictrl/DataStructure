cmake_minimum_required(VERSION 3.0.0)
project(SD VERSION 0.1.0)
include_directories(Model)
include_directories(Stack)
include_directories(Services)
include_directories(Menu)

set(STACK_MENU Menu/MenuStack.cpp Menu/MenuStack.h)
set(STACK Model/Stack/Stack.cpp Model/Stack/Stack.h)

set(RINGBUFFER_MENU Menu/MenuRingBuffer.cpp Menu/MenuRingBuffer.h)
set(RINGBUFFER Model/RingBuffer/RingBuffer.cpp Model/RingBuffer/RingBuffer.h)

set(QUEUE Model/Queue/RingBufferQueue.cpp Model/Queue/RingBufferQueue.h Model/Queue/StackQueue.cpp Model/Queue/StackQueue.h)
set(QUEUE_MENU Menu/MenuRingBufferQueue.cpp Menu/MenuRingBufferQueue.h Menu/MenuStackQueue.cpp Menu/MenuStackQueue.h)
set(VALIDATOR Services/Validator.cpp Services/Validator.h)

add_executable(Lab3 main.cpp ${STACK_ACTIONS} ${STACK} ${STACK_MENU} ${VALIDATOR} 
               ${RINGBUFFER_MENU} ${RINGBUFFER} ${QUEUE} ${QUEUE_MENU})
set(CMAKE_CXX_STANDARD 17)

