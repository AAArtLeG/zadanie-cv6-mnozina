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
		printf("Error\n");
		return nullptr;
	}
	mn->arr = NULL;
	//mn->arr = (int*)malloc(1 * sizeof(int));
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
		printf("Error\n");
		return nullptr;
	}
	newMn->arr = (int*)malloc((mn->size) * sizeof(int));
	if (newMn->arr == NULL) {
		printf("Error\n");
		return nullptr;
	}
	newMn->size = mn->size;
	for (int i = 0; i < mn->size; i++)
	{
		newMn->arr[i] = mn->arr[i];
	}

	//push_back(newMn);
	return(newMn);
}

Mnozina* remove(Mnozina *mn, int index)
{
	if (mn->size == 0) {
		printf("No elements left\n");
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

void merge(int arr[], int l, int mid, int r) {
	int i, j, k;
	const int n1 = mid - l + 1;  
	const int n2 = r - mid;       

	int* L = (int*)malloc(n1 * sizeof(int));
	if (L == NULL) {
		printf("Error\n");
		return;
	}
	int* R = (int*)malloc(n2 * sizeof(int));
	if (R == NULL) {
		printf("Error\n");
		return;
	}
	//int L[n1], R[n2];

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
}

void mergeSort(int arr[], int l, int r) {
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
	/*printf("sorted ff0 \n");
	for (int i = 0; i < mn->size; i++)
	{
		printf(" %d ", mn->arr[i]);

	}*/
	printf("\n");
	//print(mn);
	int count = 0;
	int ttemp = 0;
	Mnozina* nTemp = konstructor();
	if (nTemp == NULL) {
		printf("Error\n");
		return nullptr;
	}
	for (int i = 0; i < mn->size; i++)
	{
		if (i == 0)
		{
			nTemp->arr = (int*)malloc(1 * sizeof(int));
			if (nTemp->arr == NULL) {
				printf("Error\n");
				return nullptr;
			}
			nTemp->arr[nTemp->size] = mn->arr[i];
			nTemp->size++;
			//printf("%d %d\n", mn->arr[0], mn->size);
			ttemp = mn->arr[i];
			//print(nTemp);
		}
		else
		{
			if (ttemp != mn->arr[i])
			{
				nTemp->size++;
				Mnozina* temp = copy(nTemp);

				nTemp->arr = (int*)malloc((nTemp->size) * sizeof(int));
				if (nTemp->arr == NULL) {
					printf("Error\n");
					return nullptr;
				}
				for (int j = 0; j < temp->size; j++)
				{
					nTemp->arr[j] = temp->arr[j];
				}
				nTemp->arr[nTemp->size - 1] = mn->arr[i];
				ttemp = mn->arr[i];
				//print(nTemp);
			}
		}
	}
	destrucktor(mn);
	mn = nTemp;
	
	return(mn);
}

Mnozina* pop_back(Mnozina* mn)
{
	if (mn->size == 0) {
		printf("No elements left\n");
		return(mn);
	}
	//free(&mn->arr[mn->size]);
	mn->size--;
	return(mn);
}



Mnozina* prienik(Mnozina* a, Mnozina* a2)
{
	Mnozina* mn = konstructor();
	if (mn == NULL) {
		printf("Error\n");
		return nullptr;
	}
	int ttemp = 0;
	for (int i = 0; i < a->size; i++)
	{
		for (int j = ttemp; j < a2->size; j++)
		{
			if (a->arr[i] == a2->arr[j])
			{
				if (mn->size == 0)
				{
					mn->arr = (int*)malloc(1 * sizeof(int));
					if (mn->arr == NULL) {
						printf("Error\n");
						return nullptr;
					}
					mn->arr[mn->size] = a->arr[i];
					mn->size++;
					//printf("%d %d\n", mn->arr[0], mn->size);
					ttemp = j;
					break;
				}
				mn->size++;
				Mnozina* temp = copy(mn);

				mn->arr = (int*)malloc((mn->size) * sizeof(int));
				if (mn->arr == NULL) {
					printf("Error\n");
					return nullptr;
				}
				for (int i = 0; i < temp->size; i++)
				{
					mn->arr[i] = temp->arr[i];
				}
				mn->arr[mn->size - 1] = a->arr[i];
				ttemp = j;
				break;
			}
		}
	}
	/*printf("ffp ");
	for (int i = 0; i < mn->size; i++)
	{
		printf(" %d ", mn->arr[i]);

	}
	printf("\n");*/
	//mn = optimize(mn);
	return(mn);
}

Mnozina* ziednotenie(Mnozina* a, Mnozina* a2/*int* a, int* a2, int* arr, int* p*/)
{
	Mnozina* mn = konstructor();
	if (mn == NULL) {
		printf("Error\n");
		return nullptr;
	}
	mn = copy(a);
	int k = 0;
	for (int i = 0; i < a2->size; i++)
	{
		mn->size++;
		Mnozina* temp = copy(mn);

		mn->arr = (int*)malloc((mn->size) * sizeof(int));
		if (mn->arr == NULL) {
			printf("Error\n");
			return nullptr;
		}
		for (int i = 0; i < temp->size; i++)
		{
			mn->arr[i] = temp->arr[i];
		}
		mn->arr[mn->size - 1] = a2->arr[i];
	}

	mn = optimize(mn);
	return(mn);
}



Mnozina* push_back(Mnozina* mn)
{
	
	int a = rand() % 15;

	if (mn->size == 0)
	{
		printf("fff %d   \n", a);
		mn->arr = (int*)malloc(1 * sizeof(int));
		if (mn->arr == NULL) {
			printf("Error\n");
			return nullptr;
		}
		mn->arr[mn->size] = a;
		mn->size++;
		//printf("%d %d\n", mn->arr[0], mn->size);
		return(mn);
	}
	mn->size++;
	Mnozina* temp = copy(mn);

	mn->arr = (int*)malloc((mn->size) * sizeof(int));
	if (mn->arr == NULL) {
		printf("Error\n");
		return nullptr;
	}
	for (int i = 0; i < temp->size; i++)
	{
		mn->arr[i] = temp->arr[i];
	}
	mn->arr[mn->size-1] = a;
	destrucktor(temp);
	//printf("%d %d", mn->arr[0], mn->size);
	return(mn);
}



int main()
{
	srand(time(0));
	Mnozina* mn = konstructor();
	Mnozina* mn2 = konstructor();
	for (int i = 0; i < 15; i++)
	{
		push_back(mn);
	}
	//mn = optimize(mn);
	for (int i = 0; i < 15; i++)
	{
		push_back(mn2);
	}
	mn = optimize(mn);
	mn2 = optimize(mn2);
	print(mn);
	print(mn2);
	Mnozina* pr = prienik(mn, mn2);
	printf("prie\n");
	print(pr);
	printf("\n");
	Mnozina* copia = copy(mn);

	print(copia);
	printf("\n");
	print(mn);
	printf("\n");
	Mnozina* zied = konstructor();
	zied = ziednotenie(mn, mn2);
	printf("zied \n");

	print(zied);
	destrucktor(mn);
	destrucktor(mn2);
	destrucktor(pr);






	//int n = 4;
	//int a[4] = { 1,2,3,4 };
	//int a2[4] = { 1,4,5,6 };
	//int* arr = konstructor();
	//int p = 0;
	///*for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		if (a[i] == a2[j])
	//		{
	//			arr = (int*)realloc(arr, sizeof(arr) * 4);
	//			arr[p] = a[i];
	//			p++;
	//		}
	//	}
	//}*/

	//arr = prienik(a, a2, arr, &p);

	//for (int i = 0; i < p; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf(" g ");


	//
	//p = 0;
	//int k = 0;
	//int* arr2 = konstructor();
	///*for (int i = 0; i < 4; i++)
	//{
	//	arr2[i] = a[i];
	//}
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		if (a2[i] == a[j])
	//		{
	//			k++;
	//		}
	//	}
	//	if (k == 0)
	//	{
	//		arr2 = (int*)realloc(arr2, sizeof(arr2) * 4);
	//		arr2[4 + p] = a2[i];
	//		p++;
	//	}
	//	k = 0;
	//}*/

	//arr2 = ziednotenie(a, a2, arr, &p);

	//for (int i = 0; i < p + 4; i++)
	//{
	//	printf("%d ", arr2[i]);
	//}

	//free(arr2);

}