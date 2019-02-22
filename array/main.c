#include "../head.h"

int *find_element(int *array, int ele)
{
	for(int i = 0; array[i] != '\0'; i++){
		if (array[i] == ele)
			array[i] = 10;
			return &array[i];
	}
	return NULL;
}
int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int *p = find_element(array, 4);
	printf("p=%d\n", *p);
	for (int i = 0; i < 5; i++){
		printf("array[%d]=%d\n", i, array[i]);
	}

	int a2[2][2][2] = {1,2,3,4,5,6,7,8};
	int i,j,k;
	for (i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			for (k = 0; k < 2; k++){
				printf("a[%d][%d][%d] = %d\n", i, j, k, a2[i][j][k]);
			}
		}
	}
	return 0;
}
