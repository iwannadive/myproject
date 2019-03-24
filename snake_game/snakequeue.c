#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snakequeue.h"


LinkedQueue* createLinkedQueue(){
    LinkedQueue *pReturn = NULL;
    pReturn = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if(pReturn != NULL){
        memset(pReturn, 0, sizeof(LinkedQueue));
    } else {
        printf("Error! Memory allocation failed!\n");
        return NULL;
    }
    return pReturn;
}

int enqueueLQ(LinkedQueue* pQueue, headPos element){
    int ret = FALSE;
    headPos *pNode = NULL;
    if(pQueue != NULL){
        pNode = (headPos *)malloc(sizeof(headPos));
        if(pNode != NULL){
            *pNode = element;
            pNode->pLink = NULL;
            if(isLinkedQueueEmpty(pQueue) == TRUE){
                pQueue->pFrontNode = pNode;
                pQueue->pRearNode = pNode;
            } else {
                pQueue->pRearNode->pLink = pNode;
                pQueue->pRearNode = pNode;
            }
            pQueue->currentElementCount++;
            ret = TRUE;
        } else {
            printf("Error! Memory allocation failed!\n");
        }
    }
    return ret;
}

headPos* dequeueLQ(LinkedQueue* pQueue){
    headPos *pReturn = NULL;
    if(pQueue != NULL){
        if(isLinkedQueueEmpty(pQueue) == FALSE){
            pReturn = (headPos *)malloc(sizeof(headPos));        //MEMORY FREE NEEDED!
            if(pReturn != NULL){
                pReturn = pQueue->pFrontNode;
                pQueue->pFrontNode = pQueue->pFrontNode->pLink;
                pReturn->pLink = NULL;
                pQueue->currentElementCount--;
                if(isLinkedQueueEmpty(pQueue) == TRUE){
                    pQueue->pRearNode = NULL;
                }
            } else{
                printf("Error! Memory allocation failed!\n");
            }
        }
    }
    return pReturn;
}

headPos* peekLQ(LinkedQueue* pQueue){
    headPos *pReturn = NULL;
    if(pQueue != NULL){
        if(isLinkedQueueEmpty(pQueue) == FALSE){
            pReturn = pQueue->pFrontNode;
        }
    }
    return pReturn;
}

void deleteLinkedQueue(LinkedQueue* pQueue){
    headPos *pNode = NULL, *pDelNode = NULL;
    if(pQueue != NULL){
        pNode = pQueue->pFrontNode;
        while(pNode != NULL){
            pDelNode = pNode;
            pNode = pNode->pLink;
            free(pDelNode);
        }
        free(pQueue);
    }
}

int isLinkedQueueEmpty(LinkedQueue* pQueue){
    int ret = FALSE;
    if(pQueue != NULL){
        if(pQueue->currentElementCount == 0){
            ret = TRUE;
        }
    }
    return ret;
}
/*
void displayLinkedQueue(LinkedQueue* pQueue){
    headPos *pNode = NULL;
    int i = 0;
    if(pQueue != NULL){
        printf("Current Nodes Count : %d\n", pQueue->currentElementCount);
        pNode = pQueue->pFrontNode;
        while(pNode != NULL){
            printf("[%d] - [%c]\n", i, pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}
*/
