//Лабораторная работа 17. Вариант 1. Яскович Дмитрий (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//подключение библиотек
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define number 5;
#define Dep1 4;
#define Dep2 5;
#define Dep3 6;

struct tAddress
{ /* структура оценки */
	char City[20]; /* оценка по Математике */
	char Street[50]; /* оценка по Физике */
	int House;
	int Flat; /* оценка по Информатике */
};

struct tStudentCard
{
	char SurName[20]; /* фамилия */
	char Name[20]; /* имя */
	struct tAddress Address; /* оценки */
	char Department[50];
	int Points;
};

int readfromfile(struct tStudentCard *list);
int filling(struct tStudentCard *list);//прототипы функций
int output(struct tStudentCard *list);
int search(struct tStudentCard *list);

int main(void)//главная функция
{
	struct tStudentCard list[40];
	readfromfile(list);
	//filling(list);//заполнение остального
	output(list);//вывод списка
   //	search(group);//поиск лучшего с первого курса
	fflush(stdin);//ожидание действий пользователя
	getchar();
	return 0;
}


int readfromfile(struct tStudentCard *list)
{
	FILE *filepointer;//определение переменных
	int i=0,nmbr;
	nmbr=0;//сброс количества элементов в массиве
	filepointer = fopen("List_students.txt", "r");//открытие файла
	if (filepointer==NULL)//не удалось открыть
	{
		printf("Error while opening file.\n");//сообщение об ошибке
		exit(1);//выход
	}
	else//удалось открыть
	{
		while(!feof(filepointer))//считывание до конца файла
		{
			fscanf(filepointer,"%s , %s , %s , %s , %d , %d , %s , %d",&list[i].SurName,&list[i].Name,&list[i].Address.City,&list[i].Address.Street,&list[i].Address.House,&list[i].Address.Flat,&list[i].Department,&list[i].Points);//считывание элемента
			i++;//изменение позиции в массиве
			nmbr=nmbr+1;//изменение количества элементов
		}
		fclose(filepointer);//закрытие файла
	}
}

int output(struct tStudentCard *group)//вывод
{
	int i;
	printf("   Surname  |    Name    |   Course   | Mathematics|   Physics  |Informatics |\n");//заголовок
	for (i = 0; i < 25; i++)//вывод списка студентов
	{
		printf(" %-10s |",group[i].SurName);
		printf(" %-10s |",group[i].Name);
		//printf(" %-10d |",group[i].Course);
	   //	printf(" %-10d |",group[i].Marks.Math);
	   //	printf(" %-10d |",group[i].Marks.Phys);
	   //	printf(" %-10d |",group[i].Marks.Inform);
		printf("\n");//переход на следущую строчку
	}
}
/*
int search(struct tStudentCard *group)//поиск строк с максимальной суммой элементов в них
{
	int sum,maxsum,i,j;
	maxsum=0;//начальное значение максимальной суммы оценок
	for (i = 0; i < number; i++)//определение максимального значения
	{
		if (group[i].Course==1)
		{
			sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
			if (sum>maxsum)//сравнение с максимальной суммой
			{
				maxsum=sum;//изменение максимальной суммы если она меньше новой
			}
		}
	}
	printf("\nBest students from 1st course:\n");//вывод заголовка
	for (i = 0; i < number; i++)//вывод номеров строк с максимальными суммами
	{
		if (group[i].Course==1)
		{
			sum=0;//обнуление суммы
			sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
			if (sum==maxsum)//проверка равенства максимальной суммы и текущей
			{
				printf("%s %s\n",group[i].SurName,group[i].Name);//вывод номера строки
			}
		}
	}
}

*/

