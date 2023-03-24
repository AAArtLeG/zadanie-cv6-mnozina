#include <stdio.h>
#include <windows.h>

int S = 0;

struct Mnozina
{
	int* arr;
	int size = 0;
};

Mnozina* konstructor()
{
	Mnozina* mn = (Mnozina*)malloc(sizeof(Mnozina));
	mn->arr = nullptr;
	//mn->arr = (int*)malloc(1 * sizeof(int));
	return(mn);
}

Mnozina* push_back(Mnozina* mn)
{
	
	int a = rand() % 10;
	
	if (mn->size == 0)
	{
		printf("fff %d   ", a);
		mn->arr = (int*)malloc(4 * sizeof(int));
		mn->arr[mn->size] = a;
		mn->size++;
		printf("%d %d", mn->arr[0], mn->size);
		return(mn);
	}
	mn->arr = (int*)realloc(mn->arr, sizeof(*((*mn).arr)) * 4);
	mn->arr[mn->size] = a;
	mn->size++;
	printf("%d %d", mn->arr[0], mn->size);
	return(mn);
}

int* prienik(int* a, int* a2, int* arr, int* p)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i] == a2[j])
			{
				arr = (int*)realloc(arr, sizeof(*arr) * 4);
				arr[*p] = a[i];
				(*p)++;
			}
		}
	}
	return(arr);
}

int* ziednotenie(int* a, int* a2, int* arr, int* p)
{
	const int n = 4;
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		arr[i] = a[i];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a2[i] == a[j])
			{
				k++;
			}
		}
		if (k == 0)
		{
			arr = (int*)realloc(arr, sizeof(arr) * 4);
			arr[n + (*p)] = a2[i];
			(*p)++;
		}
		k = 0;
	}
	return(arr);
}

int main()
{
	Mnozina* mn = konstructor();
	push_back(mn);
	for (int i = 0; i <= mn->size; i++)
	{
		printf("%d ", mn->arr[i]);

	}





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