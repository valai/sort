#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;

void bsort(char *string_array, int size) {
	//input your code here...
	char *w = (char*)malloc(sizeof(char)*size * 2);
	char *s = (char*)malloc(sizeof(char)*size);
	int i, j;

	int *order = (int*)malloc(sizeof(int)*size);
	/*
	for(i = 0; i < size; i++){
		order[i] = (int*)malloc(sizeof(int));
	}
	*/
	start = clock();
	i = 0;
	for(i = 0; i < size; i++){
		order[i] = i;
		//order[i][1] = size + i - 1;
	}
	end = clock();
	printf("%fsec\n", (double)(end - start)/CLOCKS_PER_SEC);

	strcpy(w, string_array);
	strcat(w, string_array);

	mysort(w, order, size);

	for(j = 0; j < size; j++){
		s[j] = w[order[j] + size - 1];
	}
	s[j] = '\0';

	strcpy(string_array, s);
/*
	for(i = 0; i < size; i++){
		free(order[i]);
	}
	*/
	free(order);
	free(w);
	free(s);

}

int mysort(char *string_array, int *order, int size) {
  int ret;
  //input your code here...
	int i;
	int *t_order = (int*)malloc(sizeof(int)*size);
	/*
	for(i = 0; i < size; i++){
		t_order[i] = (int*)malloc(sizeof(int));
	}
	*/

	Msort(string_array, order, t_order, 0, size - 1, size);
/*
	for(i = 0; i < size; i++)
		free(t_order[i]);
		*/
	free(t_order);

  ret = definecheck(918210);
  return ret;
}

void Msort(char *Data, int *order, int *t_order, int left, int right, int size){
	int mid, i, j, k;

	if(left >= right){
  	return;
	}

	mid = (left + right) / 2;
	Msort(Data, order, t_order, left, mid, size);
	Msort(Data, order, t_order, mid + 1, right, size);

	for(i = left; i <= right; i++){
		t_order[i] = order[i];
//		t_order[i][1] = order[i][1];
	}
	
	i = left;
	j = mid + 1;
	k = left;

	while(i <= mid || j <= right){
		if(j > right || (i <= mid && strncmp(Data + t_order[i], Data + t_order[j], size) <= 0)){
			order[k] = t_order[i];
//			order[k][1] = t_order[i][1];
			i++;
		}else{
			order[k] = t_order[j];
//			order[k][1] = t_order[j][1];
			j++;
		}
		k++;
	}
}

