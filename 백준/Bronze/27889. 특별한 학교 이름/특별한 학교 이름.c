#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char first[5];
	scanf("%s", first);

	switch (first[0]) {
	case ('N'): {
		printf("North London Collegiate School");
		break;
	}
	case ('B'): {
		printf("Branksome Hall Asia");
		break;
	}
	case('K'): {
		printf("Korea International School");
		break;
	}
	case ('S'): {
		printf("St. Johnsbury Academy");
		break;
	}
	}

}