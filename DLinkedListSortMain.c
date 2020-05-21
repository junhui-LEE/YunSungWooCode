#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;		// d1이 정렬 순서상 앞선다. 
	else
		return 1;		// d2가 정렬 순서상 앞서거나 같다. 
}

int main(void) {
	List list; 
	int data; 
	ListInit(&list); 

	SetSortRule(&list, WhoIsPrecede);		// 정렬의 기준을 등록한다.!!

	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수: %d \n", LCount(&list)); 
	
	if (LFirst(&list, &data)) {
		printf("%d ", data); 

		while (LNext(&list, &data))
			printf("%d ", data); 
	}
	printf("\n\n"); 

	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list); 

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list); 
		}
	}
	printf("현재 데이터의 수 : %d \n", LCount(&list)); 

	if (LFirst(&list, &data)) {
		printf("%d ", data); 

		while (LNext(&list, &data))
			printf("%d ", data); 
	}
	printf("\n\n"); 
	return 0; 
}