#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>

int S = 0;

struct Mnozina
{
	int* arr;
	int size;
};

Mnozina* konstructor()
{
	Mnozina* mn = (Mnozina*)malloc(sizeof(Mnozina));
	if (mn == NULL) {
		return NULL;
	} 
	mn->arr = NULL;
	mn->size = 0;
	return(mn);
}

void destrucktor(Mnozina* mn)
{
	free(mn->arr);
	free(mn);
}


Mnozina* copy(Mnozina* mn)
{
	Mnozina* newMn = konstructor();
	if (newMn == NULL) {
		return NULL;
	}
	newMn->arr = (int*)malloc((mn->size) * sizeof(int));
	if (newMn->arr == NULL) {
		destrucktor(newMn);
		return NULL;
	}
	newMn->size = mn->size;
	for (int i = 0; i < mn->size; i++)
	{
		newMn->arr[i] = mn->arr[i];
	}
	return(newMn);
}

Mnozina* remove(Mnozina *mn, int index)
{
	if (mn->size == 0) {
		return(mn);
	}
	for (int i = index; i < mn->size - 1; i++)
	{
		mn->arr[i] = mn->arr[i + 1];
	}
	mn->size--;
	return(mn);
}

void print(Mnozina* mn)
{
	for (int i = 0; i < mn->size; i++)
	{
		printf(" %d ", mn->arr[i]);

	}
	printf("\n");
}

void push_back(Mnozina* mn, int a)
{
	if (mn->size == 0)
	{
		printf("fff %d   \n", a);
		mn->arr = (int*)malloc(1 * sizeof(int));
		if (mn->arr == NULL) {
			return;
		}
		mn->arr[mn->size] = a;
		mn->size++;
		return;
	}
	mn->size++;
	Mnozina* temp = copy(mn);
	if (temp == NULL) {
		return;
	}
	free(mn->arr);
	mn->arr = (int*)malloc((mn->size) * sizeof(int));
	if (mn->arr == NULL) {
		destrucktor(temp);
		return;
	}
	for (int i = 0; i < temp->size; i++)
	{
		mn->arr[i] = temp->arr[i];
	}
	mn->arr[mn->size - 1] = a;
	destrucktor(temp);
}

void merge(int *arr, int l, int mid, int r) {
	int i, j, k;
	const int n1 = mid - l + 1;  
	const int n2 = r - mid;       

	int* L = (int*)malloc(n1 * sizeof(int));
	if (L == NULL) {
		return;
	}
	int* R = (int*)malloc(n2 * sizeof(int));
	if (R == NULL) {
		free(L);
		return;
	}

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;   
	j = 0;   
	k = l;   

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void mergeSort(int *arr, int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

Mnozina* optimize(Mnozina* mn)
{
	mergeSort(mn->arr, 0, mn->size - 1);
	Mnozina* sorted = konstructor();
	if (sorted == NULL) {
		return NULL;
	}
	int last = -1;
	for (int i = 0; i < mn->size; i++) {
		if (last != mn->arr[i]) {
			push_back(sorted, mn->arr[i]);
			last = mn->arr[i];
		}
	}
	destrucktor(mn);
	return(sorted);
}

Mnozina* pop_back(Mnozina* mn)
{
	if (mn->size == 0) {
		return(mn);
	}
	mn->size--;
	return(mn);
}

Mnozina* ziednotenie(Mnozina* a, Mnozina* a2/*int* a, int* a2, int* arr, int* p*/)
{
	Mnozina* mn = konstructor();
	if (mn == NULL) {
		return NULL;
	}

	int i = 0;
	int j = 0;

	int last = -1;
	
	while (i < a->size && j < a2->size) {
		if (a->arr[i] < a2->arr[j]) {
			push_back(mn, a->arr[i]);
			
			last = a->arr[i];
			i++;
			continue;
		}
		if (a->arr[i] > a2->arr[j]) {
			push_back(mn, a2->arr[j]);
			last = a2->arr[j];
			j++;
			continue;
		}
		else {
			if (last != a->arr[i]) {
				push_back(mn, a->arr[i]);
				last = a->arr[i];
				i++;
				j++;
				continue;
			}
			else
			{
				i++;
				j++;
			}
		}
	}

	while (i < a->size) {
		push_back(mn, a->arr[i]);
		i++;
	}

	while (j < a2->size) {
		push_back(mn, a2->arr[j]);
		j++;
	}
	return(mn);
}



Mnozina* prienik(Mnozina* a, Mnozina* a2)
{
	Mnozina* mn = konstructor();
	if (mn == NULL) {
		return NULL;
	}

	int i = 0;
	int j = 0;

	int last = -1;

	while (i < a->size && j < a2->size) {
		if (a->arr[i] == a2->arr[j]) {
			if (last != a->arr[i]) {
				push_back(mn, a->arr[i]);
				last = a->arr[i];
			}
			i++;
			j++;
			continue;
		}
		if (a->arr[i] < a2->arr[j]) {
			i++;
			continue;
		}
		else {
			j++;
		}
	}
	
	return(mn);
}

bool search(Mnozina* a, int x) 
{
	int f = 0;
	int l = a->size - 1;
	while(f <= l) {
		int mid = l + (f - l) / 2;
		if (x == a->arr[mid])
			return true;
		if (x > a->arr[mid])
			f = mid + 1;
		if (x < a->arr[mid])
			l = mid - 1;
	}
	return false;
}


int main()
{
	srand(time(0));
	Mnozina* mn = konstructor();
	if (mn == NULL)
		return -1;
	Mnozina* mn2 = konstructor();
	if (mn2 == NULL)
		return -1;
	int a;
	for (int i = 0; i < 15; i++)
	{
		a = rand() % 15;
		push_back(mn, a);
	}
	for (int i = 0; i < 15; i++)
	{
		a = rand() % 15;
		push_back(mn2, a);
	}
	mn = optimize(mn);
	if (mn == NULL)
		return -1;
	mn2 = optimize(mn2);
	if (mn2 == NULL)
		return -1;
	print(mn);
	print(mn2);
	Mnozina* pr = prienik(mn, mn2);
	if (pr == NULL)
		return -1;
	printf("prie\n");
	print(pr);
	printf("\n");
	Mnozina* zied = konstructor();
	if (zied == NULL)
		return -1;
	zied = ziednotenie(mn, mn2);
	printf("zied \n");
	print(zied);
	print(mn);
	puts("Search: ");
	int x;
	scanf_s("%d", &x);
	if (search(mn, x))
		printf("True\n");
	else
		printf("False");
	destrucktor(mn);
	destrucktor(mn2);
	destrucktor(pr);
}