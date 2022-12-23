#include<stdio.h>
#include "seatingchart.h"
void seating(char seatarray[][30], int numr, int numc) {

	if (seatarray[numr][numc] == '*') {
		printf("this seat is already booked\n");
	}
	else if (seatarray[numr][numc] == '#') {
		printf("this seat is  available\n");
	}
}
int num_of_seats_array(char array1[][30], int row, int column) {
	if (array1[row][column] == '*') {
		return 1;
	}
	else {
		return -1;
	}
}
int cancel_booking_fun(char array[][30], int numr, int numc) {
	array[numr][numc] = '#';
	return array;
}
void reportfun(char array[][30],int pricearray[], int cost) {
	int stars = 0, hash = 0, money=0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 30; j++) {
			if (array[i][j] == '*') {
				stars++;
				money = money + pricearray[i];
			}
			else {
				hash++;
			}
		}
	}
	printf("\ntotal seats occupaid are:\t%d", stars);
	printf("\ntoal seats available are:\t%d", hash);
	printf("\ntotal money collected:\t%d\n", money);

}
void pur_ticket_fun(int num_of_seats, int ticketarray_row[], int ticketarray_col[], int cost) {
	int get_money, remain_money = 0;
	printf("\nenter your money:\t");
	scanf_s("%d", &get_money);
	if (get_money > cost) {
		for(int i=0;i<num_of_seats;i++)
		{
			printf("\nNumber of your seat row %d ", ticketarray_row[i]+1);
			printf("\nNumber of your seats column %d", ticketarray_col[i]+1);
		}
		remain_money = get_money - cost;
		printf("\n%d is your remaining money", remain_money);
		printf("\n Now pay your bill");

	}
	else {
		printf("you have insufficient ballance");
	}
}

int main() {
	char seatarray[15][30] = { {"***###***###*########*****####"},
								{"####*************####*******##"} ,
							{"**###**********########****###"},
		{"**######**************##******"},
		{"********#####*********########"},
		{"##############************####"},
		{"#######************###########"},
		{"************##****############"},
		{"#########*****############****"},
		{"#####*************############"},
		{"#**********#################**"},
		{"#############********########*"},
		{"###***********########**######"},
		{"##############################"},
		{"##############################"}

	};
	int pricearray[15] = {200,220,240,260,300,340,380,450,380,340,300,260,240,220,200};
	int report_var, pur_tic = 0;
	int ticketarray_row[10]={0};
	int ticketarray_col[10]={0};
	int x = 0, m, num_of_seats = 0, v, cancel_var, cost = 0, exit_var = 0;
	int numr, numc, seat_status, cancel_booking;
	while (1) {
		printf("------------------MENU-----------------\n");
		printf("-----1:\tenter 1 to display siting status-----\n");
		printf("-----2:\tenter 2 to request booking-----\n");
		printf("-----3:\tenter 3 to cancel booking-----\n");
		printf("-----4:\tenter 4 to get ticket-----\n");
		printf("-----5:\tenter 5 to check sales report-----\n");
		printf("-----6:\tenter 6 to exit-----\n");
		printf("-----7:\tenter 7 to check seat status-----\n");
		int input;
		scanf_s("%d", &input);

		if (input == 1) {
			/*printf("\nenter 1 to display seating chart\n");
			scanf_s("%d", &m);*/
			/*if (m == 1) {
			}*/
			seating_chart(seatarray);
		}
		else if (input == 2) {
			printf("how many seats do you want to buy\n");
			scanf_s("%d", &num_of_seats);
			for (int i = 0; i < num_of_seats /*i<count*/; i++) {

				while (1) {
					printf("\nenter seat row and column:\t");
					scanf_s("%d %d", &numr, &numc);
					numr--;
					numc--;
					if ((numr >= 0 && numr <= 14) && (numc >= 0 && (numc <= 29))) {
						ticketarray_row[i] = numr;
						ticketarray_col[i] = numc;
						printf("Enter 2 to cheack this seat status\n");
						scanf_s("%d", &seat_status);
						if (seat_status == 2) {
							v = num_of_seats_array(seatarray, numr, numc);
							if (v == 1) {
								printf("this seat is already booked.\nplease choose another seat.\n");
								i--;

							}
							else if (v == -1) {
								seatarray[numr][numc] = '*';
								printf("booking seat for you\n");
								cost = cost + pricearray[numr];
								/*count += count;*/
							}
						}
						break;

					}
					else {
						printf("you have entered invalid input");
					}
					printf("\nyour total cost for seats are:\t%d\n", cost);

				}

			}
		}
		else if (input == 3) {
			/*printf("enter 3 if you want to cancel the booked seat");
			scanf_s("%d", &cancel_booking);
			if (cancel_booking == 3) {*/
				printf("how many booking do you want to cancel");
				scanf_s("%d", &cancel_var);
				for (int s = 0; s < cancel_var; s++) {
					printf("\nenter the seat row and column to cancel its booking");
					scanf_s("%d %d", &numr, &numc);
					numr--;
					numc--;
					cancel_booking_fun(seatarray, numr, numc);
					cost = cost - pricearray[numr];
				}

			//}
		}
		else if (input == 4) {
			/*printf("enter 5 to purchase a ticket:\t");
			scanf_s("%d", &pur_tic);
			if (pur_tic == 5) {*/
				pur_ticket_fun(num_of_seats, ticketarray_row, ticketarray_col, cost);
			
		}
		else if (input == 5) {
			printf("enter 9 for report:\t");
			scanf_s("%d", &report_var);
			if (report_var == 9) {
				reportfun(seatarray, pricearray, cost);
			}
		}
		else if (input == 6) {
			
			
			break;
			
		}
		else if (input == 7) {

			printf("\nenter seat row and column:\t");
		scanf_s("%d %d", &numr, &numc);
		numr--;
		numc--;
		printf("Enter 2 to cheack seat status\n");
		scanf_s("%d", &seat_status);
		if (seat_status == 2) {
			seating(seatarray, numr, numc);
		}
		}
		else {
			printf("Invalid input");
		}
		
		
		
		
		
			

			
			


		
	}
	printf("thanks for using cinema software");
	return 0;
}