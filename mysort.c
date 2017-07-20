#include "func.h"
#include <string.h>

int mysort(char *string_array[], int size) {
  int ret;
  //input your code here...

	char **temp = (char**)malloc(sizeof(char*)*MAXLINE); // 大きいサイズの配列を確保
	Msort(string_array, temp, 0, size - 1);

  ret = definecheck(918210);
  return ret;
}

void Msort(char *Data[], char *temp[], int left, int right){
	int mid, i, j, k;

	if(left >= right){
  	return;
	}

	mid = (left + right) / 2;
	Msort(Data, temp, left, mid);
	Msort(Data, temp, mid + 1, right);

	for(i = left; i <= mid; i++)
		temp[i] = Data[i];
	for(i = mid + 1, j = right; i <= right; i++, j--)
		temp[i] = Data[j];

	i = left;
	j = right;

	for(k = left; k <= right; k++){
		if(strcmp(temp[i], temp[j]) == -1){
			Data[k] = temp[i];
			i++;
		}else{
			Data[k] = temp[j];
			j--;
		}
	}
}

