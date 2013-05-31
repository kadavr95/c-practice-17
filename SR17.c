//Самостоятельная работа 17. Вариант 2. Яскович Дмитрий (T02-01c). Dimini Inc. & Govnokod Inc.  (c)2013
#include <stdio.h>//подключение библиотек
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct tAddress
{ /* структура адреса */
	char City[50]; /* город */
	char Street[50]; /* улица */
	int House; //дом
	int Flat; /* квартира */
};

struct tStudentCard //карта абитуриента
{
	char SurName[50]; /* фамилия */
	char Name[50]; /* имя */
	struct tAddress Address; /* адрес */
	char Department[50]; //факультет
	int Points; //баллы
};

int readfromfile(int *nmbr,struct tStudentCard *list); //прототипы функций
int pointssearch(int places , char dept[50], struct tStudentCard *list, int number, int *okpoints);
int passed(char dept[50], struct tStudentCard *list, int number, int okpoints);
int campus(char dept[50],  int okpoints,struct tStudentCard *list,int number, int *places);

int main(void)//главная функция
{
	struct tStudentCard list[40];
	int placeT=6, placeKiB=5, placeU=4, number=0, okpointsT=0,okpointsKiB=0,okpointsU=0,placescampus=0;
	readfromfile(&number,list);//считывание из файла
	printf("Points to departments\n");//определение проходных баллов на факультеты
	pointssearch(placeT,"T",list,number,&okpointsT);
	pointssearch(placeKiB,"KiB",list,number,&okpointsKiB);
	pointssearch(placeU,"U",list,number,&okpointsU);
	printf("\nAccepted students:\n");//списки прошедших
	passed("T",list,number,okpointsT);
	printf("\n");
	passed("KiB",list,number,okpointsKiB);
	printf("\n");
	passed("U",list,number,okpointsU);
	printf("\n");
	campus("T",okpointsT,list,number,&placescampus);//подсчёт мест для общежития
	campus("KiB",okpointsKiB,list,number,&placescampus);
	campus("U",okpointsU,list,number,&placescampus);
	printf("Campus needs %d places\n",placescampus);
	fflush(stdin);//ожидание действий пользователя
	getchar();
	return 0;
}


int readfromfile(int *nmbr,struct tStudentCard *list)//считывание из файла
{
	FILE *filepointer;//определение переменных
	int i=0;
	*nmbr=0;//сброс количества элементов в массиве
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
			i++;//изменение номера элемента
			*nmbr=*nmbr+1;//изменение количества элементов
		}
		fclose(filepointer);//закрытие файла
	}
	*nmbr=*nmbr-1;//аннигилирует с лишним увеличение нмбр в конце цикла
}

int pointssearch(int places, char dept[50], struct tStudentCard *list, int number,int *okpoints)//поиск строк с максимальной суммой элементов в них
{
	int plc=0,nmr,maxpoint,i,j;
	maxpoint=0;//начальное значение максимального балла
	while(plc<=places)
	{
		for (i = 0; i < number; i++)//определение максимального значения
		{
			if (strstr(list[i].Department,dept)>0)//если с нужного факультета
			{
				if (list[i].Points>=maxpoint)//если баллы больше максимального
				{
					maxpoint=list[i].Points;//макс. балл новый
					nmr=i; //запоминание номера этого студента
				}
			}
		}
		plc=plc+1;//минус 1 место
		list[nmr].Points=list[nmr].Points*(-1);//избавление от старого максимума баллов
		if (plc==places)//если последнее место
		{
			*okpoints=maxpoint;//проходной балл
		}
		maxpoint=0;//сброс макс. значения
	}
	for (i = 0; i < number; i++)//возврат баллов в нормальное состояние
	{
		if (list[i].Points<0)
		{
			list[i].Points=list[i].Points*(-1);
		}
	}
	printf("Department %s accepts with %d points\n",dept,*okpoints); //вывод проходного балла
}

int passed(char dept[50], struct tStudentCard *list, int number,int okpoints)//принятые студенты
{
	int i;
	printf("Department %s\n",dept);//вывод факультета
	for (i = 0; i < number; i++)//поиск студентов
	{
		if (strstr(list[i].Department,dept)>0)//с нужным факультетом
		{
			if (list[i].Points>=okpoints)//и баллом выше проходного на него
			{
				printf("%s %s from %s %s street %d, %d with %d points\n",list[i].SurName,list[i].Name,list[i].Address.City,list[i].Address.Street,list[i].Address.House,list[i].Address.Flat,list[i].Points);//вывод данных студента
			}
		}
	}

}

int campus(char dept[50],  int okpoints,struct tStudentCard *list,int number, int *places)//места в общежитии
{
	int i;
	for (i = 0; i < number; i++)//поиск студентов
	{
		if ((strstr(list[i].Address.City,"Moscow")<=0)&& (strstr(list[i].Department,dept)>0) &&(list[i].Points>=okpoints))//набравших проходные баллы на факультеты и не живущих в Москве
		{
			*places=*places+1;//увеличение числа нужных мест
		}
	}
}
