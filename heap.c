#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    if (pq->size==0)
      return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    heapElem *aux=(heapElem*)malloc(sizeof(heapElem));
    if (pq->size==pq->capac){
        pq->heapArray=realloc(pq->heapArray,pq->capac*2+1 *sizeof(heapElem));
        pq->capac=pq->capac*2+1;
    }
    pq->heapArray[pq->size].data=data;
    pq->heapArray[pq->size].priority=priority;
    pq->size++;
    int pos=pq->size-1;
    while (1){
      if (pq->heapArray[(pos-1)/2].priority<pq->heapArray[pos].priority){
        aux[0]=pq->heapArray[(pos-1)/2];
        pq->heapArray[(pos-1)/2]=pq->heapArray[pos];
        pq->heapArray[pos]=aux[0];
        pos=(pos-1)/2;
      }
      else
        break;
    }
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *crear=(Heap*)malloc(sizeof(Heap));
  crear->heapArray=(heapElem*)calloc(3,sizeof(heapElem));
  crear->size=0;
  crear->capac=3; 
  return crear;
}
