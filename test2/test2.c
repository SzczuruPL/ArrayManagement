#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

void print(int t[], int size)
{
	for (size_t i = 0; i < size; i++)
		//printf("%d ", *(t + i));
		printf("%d ", t[i]);
	printf("\n");
}

void read(int* t, int size)
{
	printf("Podaj %d liczb do tablicy: ", size);
	for (size_t i = 0; i < size; i++)
		scanf_s("%d", &t[i]);
}

void random(int* t, int size)
{
	for (size_t i = 0; i < size; i++)
		t[i] = rand()%100;
}

int maxVal(int t[], int size)
{
	int inmax=0;
	for (int i = 1; i < size; i++)
	{
		if (t[i] > t[inmax])
			inmax = i;
	}
	return inmax;
}

int minVal(int t[], int size)
{
	int inmin = 0;
	for (int i = 1; i < size; i++)
	{
		if (t[i] < t[inmin])
			inmin = i;
	}
	return inmin;
}

void swap(int* t, int* smax, int* smin)
{
	int temp;
	temp = t[*smin];
	t[*smin] = t[*smax];
	t[*smax] = temp;

	temp = *smin;
	*smin = *smax;
	*smax = temp;
}

void clearEven(int* t, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			t[i] = 0;
	}
}

void bbSort(int* t, int size)
{
	int temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (t[j] > t[j + 1])
			{
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}

//func - sortowanie innym sposobem

void moveRight(int* t, int size)
{
	int temp = t[size-1];
	for (int i = size-2; i >= 0; i--)
		t[i + 1] = t[i];
	t[0] = temp;
}

void moveLeft(int* t, int size)
{
	int temp = t[0];
	for (int i = 1; i < size; i++)
		t[i - 1] = t[i];
	t[size-1] = temp;
}

void equalVal(int t[], int size)
{
	int w;
	printf("Powtarzajace sie liczby to:");
	for (int i = 0; i < size; i++)
	{
		w = 0;
		for (int j = 0; j < size; j++)
		{
			if (t[i] == t[j])
				w++;
		}
		if (w > 1)
			printf(" %d", t[i]);
	}
	printf("\n");
}

int main(void)
{
	srand(time(NULL));
	int tab[N];
	int s,inmin,inmax;

	random(&tab, N);
	printf("Zawartosc wylosowanej tablicy: ");
	print(tab, N);
	printf("\n");

	while(1)
	{
		printf("0 - wyjscie z programu\n");
		printf("1 - sortowanie tablicy\n");
		printf("2 - minimum z tablicy\n");
		printf("3 - maksimum z tablicy\n");
		printf("4 - zamiana minimum z maksimum w tablicy\n");
		printf("5 - zerowanie tablicy\n");
		printf("6 - przesuniecie tablicy w prawo\n");
		printf("7 - przesuniecie tablicy w lewo\n");
		printf("8 - znajdz takie same wartosci w tablicy\n");
		printf("Wybierz dzialanie programu: ");
		scanf_s("%d", &s);
		printf("\n");
		switch(s)
		{
			case 0:
				return 0;
			case 1:
				bbSort(&tab, N);
				printf("Zawartosc tablicy po sortowaniu: ");
				print(tab, N);
				printf("\n");
				break;
			case 2:
				inmin = minVal(tab, N);
				printf("Zawartosc tablicy: ");
				print(tab, N);
				printf("Najmniejsza wartosc: tab[%d] = %d\n", inmin, tab[inmin]);
				printf("\n");
				break;
			case 3:
				inmax = maxVal(tab, N);
				printf("Zawartosc tablicy: ");
				print(tab, N);
				printf("Najwieksza wartosc: tab[%d] = %d\n", inmax, tab[inmax]);
				printf("\n");
				break;
			case 4:
				printf("Zawartosc tablicy: ");
				print(tab, N);
				inmin = minVal(tab, N);
				inmax = maxVal(tab, N);
				swap(&tab, &inmax, &inmin);
				printf("Zawartosc tablicy po zamianie: ");
				print(tab, N);
				printf("\n");
				break;
			case 5:
				printf("Zawartosc tablicy: ");
				print(tab, N);
				clearEven(&tab, N);
				printf("Zawartosc tablicy po zerowaniu: ");
				print(tab, N);
				printf("\n");
				break;
			case 6:
				printf("Zawartosc tablicy: ");
				print(tab, N);
				moveRight(&tab, N);
				printf("Zawartosc tablicy po przesunieciu w prawo: ");
				print(tab, N);
				printf("\n");
				break;
				break;
			case 7:
				printf("Zawartosc tablicy: ");
				print(tab, N);
				moveLeft(&tab, N);
				printf("Zawartosc tablicy po przesunieciu w lewo: ");
				print(tab, N);
				printf("\n");
				break;
			case 8:
				printf("Zawartosc tablicy: ");
				print(tab, N);
				equalVal(tab, N);
				printf("\n");
				break;
		}
	}
}
