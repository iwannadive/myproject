#ifndef SNAKE_QUEUE_
#define SNAKE_QUEUE_

typedef struct headPosType {
    int xpos;
    int ypos;
    struct headPosType* pLink;
} headPos;

typedef struct LinkedQueueType{
    int currentElementCount;
    headPos* pFrontNode;
    headPos* pRearNode;
} LinkedQueue;

LinkedQueue* createLinkedQueue();
int enqueueLQ(LinkedQueue* pQueue, headPos element);
headPos* dequeueLQ(LinkedQueue* pQueue);
headPos* peekLQ(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);
void displayLinkedQueue(LinkedQueue* pQueue);
#endif // LINKEDQ_

#ifndef COMMON_TF
#define COMMON_TF

#define TRUE 1
#define FALSE 0

#endif // COMMON_TF
