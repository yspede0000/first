/*
 ============================================================================
 Name        : random.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int members = 0;
int value = 0;
int x,y=0;
int main(void) {

// get the numbers for the class (scanf)

	printf("how many class members 6-15: ");
	scanf("%d", &members);
	printf("how many members in every group: ");
	scanf("%d", &value);

// get random numbers from the input
	{
		int array[members];
		int i;

		for (i = 0; i <= members; i++)
			array[i] = i;

		srand((unsigned) time(NULL ));
		for (i = 0; i <= members; i++) {
			int index1 = i;
			int index2 = rand() % members;

			int temp;
			temp = array[index1];
			array[index1] = array[index2];
			array[index2] = temp;
		}

		{
// print the numbers in groups.

//	for (i=0; i<=value; i++)
//			printf("member[%d] = %d",i,array[i]);





		//	for (b = 0; b < members; b++, printf("\n"))
		//		for (a = 0; a < value; a++)
		//	        for (i=0; i<=5; i++)
		//			printf("%d ",array[i]);



			  for (i=0; i<=members; i++){
					printf("%d ",array[i]);
			  }
			  printf("\n");

			  for (i=0; i<=members; i++){
					printf("%d ",array[i]);
			  }

// print where the last group members will be
			return (0);

	}
}
}
