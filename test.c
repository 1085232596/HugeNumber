#include<stdio.h>
#include<malloc.h>
#include<math.h>

#include"HugeNumber.h"

//巨大数高位先打印
void showHugeInfor(HUGENUMBER myNumber);
void showHugeInfor(HUGENUMBER myNumber) {
	int i;

	printf("[%c]", (myNumber.number_sign == NEGATIVE_SIGN)? '-' :'+');
	for(i = myNumber.number_count - 1; i >= 0; i--) {
		printf("%00004d ", myNumber.number_array[i]);
	}
	printf("\n");
}

int main(void) {
	const char *addNumFileName = "../file\\Num1.txt";
	const char *augendNumFileName = "../file\\Num2.txt";
	long before_time;
	long after_time;
	long total_Time;

	HUGENUMBER addNumber = {0};
	HUGENUMBER augendNumber = {0};
	HUGENUMBER result = {0};

	readFileInfor(&addNumber, addNumFileName);
	readFileInfor(&augendNumber, augendNumFileName);

	showHugeInfor(addNumber);
	showHugeInfor(augendNumber);

before_time = clock();
	// result = removeHugenumber(addNumber, augendNumber);
	result = divHugeNumber(addNumber, augendNumber);
	// result = addHugeNumber(addNumber, augendNumber);
after_time = clock();
total_Time = after_time - before_time;
	showHugeInfor(result);

printf("\n%d digits dividend by %d digits took", getHugenumerLength(addNumber),getHugenumerLength(augendNumber));
printf(" %ld.%03ld seconds\n", total_Time / 1000, total_Time % 1000);

	destoryHugnumber(&addNumber);
	destoryHugnumber(&augendNumber);
	destoryHugnumber(&result);

	return 0;
}

/*
long before_time;
	long after_time;
	long total_Time;

after_time = clock();
total_Time = after_time - before_time;
printf("\n%d digits dividend by %d digits took", getHugenumerLength(addNumber),getHugenumerLength(augendNumber));
printf(" %ld.%03ld seconds\n", total_Time / 1000, total_Time % 1000);
 */
