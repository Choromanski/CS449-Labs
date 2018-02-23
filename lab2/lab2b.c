#include <stdio.h>

main(){

	float  weight = 0;
	printf("Please enter the weight you'd like to convert: ");
	scanf("%f", &weight);
	printf("\nHere is your weight on other planets:\n\n");
	printf("Mercury\t\t%.0f lbs\n",weight*.38);
	printf("Venus\t\t%.0f lbs\n", weight*.91);
	printf("Mars\t\t%.0f lbs\n", weight*.38);
	printf("Jupiter\t\t%.0f lbs\n", weight*2.54);
	printf("Saturn\t\t%.0f lbs\n", weight*1.08);
	printf("Uranus\t\t%.0f lbs\n", weight*.91);
	printf("Neptune\t\t%.0f lbs\n", weight*1.19);
}
