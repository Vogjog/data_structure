#include <stdio.h>
#include <string.h>

void add(int* arr, int num) {
	int cur = 1;
	int goal;

	while(arr[cur] != -1){
		if(num <= arr[cur]) {
			goal = cur*2;
			cur = goal;
		}
		else {
			goal = cur*2+1;
			cur = goal;
		}
	}
	arr[cur] = num;	
}

void print_tree(int* arr, int idx){

	if(arr[idx] == -1) return;

	print_tree(arr, idx*2+1);
	printf("%d\n", arr[idx]);
	print_tree(arr, idx*2);
}


int main(void) {
	int numArr[129];

	memset(numArr, -1, 129);
	
	add(numArr, 9);
	add(numArr, 11);
	add(numArr, 3);
	add(numArr, 2);
	add(numArr, 6);
	add(numArr, 5);
	add(numArr, 10);
	add(numArr, 7);
	add(numArr, 13);

	print_tree(numArr, 1);

	return 0;

}
