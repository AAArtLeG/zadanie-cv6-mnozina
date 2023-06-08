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
	newMn->arr = (int*)malloc((mn->size) * sizeof(int));
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

Mnozina* optimize(Mnozina* mn)
{
	for (int i = 0; i < mn->size; i++)
	{
		for (int j = i; j < mn->size; j++)
		{
			if (mn->arr[i] > mn->arr[j])
			{
				int temp;
				temp = mn->arr[i];
				mn->arr[i] = mn->arr[j];
				mn->arr[j] = temp;
			}
		}
	}
	/*printf("ff0 ");
	for (int i = 0; i < mn->size; i++)
	{
		printf(" %d ", mn->arr[i]);

	}*/
	printf("\n");
	//print(mn);
	int count = 0;
	int ttemp = 0;
	Mnozina* nTemp = konstructor();
	for (int i = 0; i < mn->size; i++)
	{
		if (i == 0)
		{
			nTemp->arr = (int*)malloc(1 * sizeof(int));
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
	//for (int h = 0; h < 2; h++)
	//{
	//	for (int i = 0; i < mn->size; i++)
	//	{
	//		for (int j = 0; j < mn->size; j++)
	//		{
	//			count++;
	//			if (mn->arr[i] == mn->arr[j] && i != j)
	//			{
	//				//printf("fff ");
	//				mn = remove(mn, j);
	//				/*for (int i = 0; i < mn->size; i++)
	//				{
	//					printf(" %d ", mn->arr[i]);

	//				}*/
	//				//printf("\n");
	//			}
	//			//printf("\n");
	//		}
	//	}
	//}
	//printf("%d \n", count);
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
					mn->arr[mn->size] = a->arr[i];
					mn->size++;
					//printf("%d %d\n", mn->arr[0], mn->size);
					ttemp = j;
					break;
				}
				mn->size++;
				Mnozina* temp = copy(mn);

				mn->arr = (int*)malloc((mn->size) * sizeof(int));
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
	mn = copy(a);
	int k = 0;
	for (int i = 0; i < a2->size; i++)
	{
		mn->size++;
		Mnozina* temp = copy(mn);

		mn->arr = (int*)malloc((mn->size) * sizeof(int));
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
		mn->arr[mn->size] = a;
		mn->size++;
		//printf("%d %d\n", mn->arr[0], mn->size);
		return(mn);
	}
	mn->size++;
	Mnozina* temp = copy(mn);

	mn->arr = (int*)malloc((mn->size) * sizeof(int));
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