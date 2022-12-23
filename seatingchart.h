#include<stdio.h>

void seating_chart(char seatarray[][30])
{
	for (int i = 0; i < 15; i++) {
		printf("%d:\t", i+1);
		for (int j = 0; j < 30; j++) {
			
			printf("%c ", seatarray[i][j]);
		}
		printf("\n");
	}
	
	
	}

