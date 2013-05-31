//������������ ������ 17. ������� 1. ������� ������� (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct tAddress
{ /* ��������� ������ */
	char City[50]; /* ������ �� ���������� */
	char Street[50]; /* ������ �� ������ */
	int House;
	int Flat; /* ������ �� ����������� */
};

struct tStudentCard
{
	char SurName[50]; /* ������� */
	char Name[50]; /* ��� */
	struct tAddress Address; /* ������ */
	char Department[50];
	int Points;
};

int readfromfile(struct tStudentCard *list);
int filling(struct tStudentCard *list);//��������� �������
int output(struct tStudentCard *list);
int pointssearch(int places , struct tStudentCard *list);

int main(void)//������� �������
{
	struct tStudentCard list[40];
	int placeT=6, placeKiB=5, placeU=4;
	readfromfile(list);
	//filling(list);//���������� ����������
  //	output(list);//����� ������
   //	search(group);//����� ������� � ������� �����
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}


int readfromfile(struct tStudentCard *list)
{
	FILE *filepointer;//����������� ����������
	int i=0,nmbr;
	nmbr=0;//����� ���������� ��������� � �������
	filepointer = fopen("List_students.txt", "r");//�������� �����
	if (filepointer==NULL)//�� ������� �������
	{
		printf("Error while opening file.\n");//��������� �� ������
		exit(1);//�����
	}
	else//������� �������
	{
		while(!feof(filepointer))//���������� �� ����� �����
		{
			fscanf(filepointer,"%s , %s , %s , %s , %d , %d , %s , %d",&list[i].SurName,&list[i].Name,&list[i].Address.City,&list[i].Address.Street,&list[i].Address.House,&list[i].Address.Flat,&list[i].Department,&list[i].Points);//���������� ��������
			i++;//��������� ������� � �������
			nmbr=nmbr+1;//��������� ���������� ���������
		}
		fclose(filepointer);//�������� �����
	}
}

int pointssearch(int places, struct tStudentCard *list)//����� ����� � ������������ ������ ��������� � ���
{
	int plc=0,nmr,maxpoint,i,j;
	maxpoint=0;//��������� �������� ������������ ����� ������
	for (i = 0; i < number; i++)//����������� ������������� ��������
	{
		if (list[i].Points>=maxpoint)
		{
			maxpoint=list[i].Points;
			nmr=i;
			plc=plc+1;
			list[i].Points=list[i].Points*(-1);
			if (sum>maxsum)//��������� � ������������ ������
			{
				maxsum=sum;//��������� ������������ ����� ���� ��� ������ �����
			}
		}
	}
}
/*int output(struct tStudentCard *group)//�����
{
	int i;
	printf("   Surname  |    Name    |   Course   | Mathematics|   Physics  |Informatics |\n");//���������
	for (i = 0; i < 25; i++)//����� ������ ���������
	{
		printf(" %-10s |",group[i].SurName);
		printf(" %-10s |",group[i].Name);
		//printf(" %-10d |",group[i].Course);
	   //	printf(" %-10d |",group[i].Marks.Math);
	   //	printf(" %-10d |",group[i].Marks.Phys);
	   //	printf(" %-10d |",group[i].Marks.Inform);
		printf("\n");//������� �� �������� �������
	}
}

int search(struct tStudentCard *group)//����� ����� � ������������ ������ ��������� � ���
{
	int sum,maxsum,i,j;
	maxsum=0;//��������� �������� ������������ ����� ������
	for (i = 0; i < number; i++)//����������� ������������� ��������
	{
		if (group[i].Course==1)
		{
			sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
			if (sum>maxsum)//��������� � ������������ ������
			{
				maxsum=sum;//��������� ������������ ����� ���� ��� ������ �����
			}
		}
	}
	printf("\nBest students from 1st course:\n");//����� ���������
	for (i = 0; i < number; i++)//����� ������� ����� � ������������� �������
	{
		if (group[i].Course==1)
		{
			sum=0;//��������� �����
			sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
			if (sum==maxsum)//�������� ��������� ������������ ����� � �������
			{
				printf("%s %s\n",group[i].SurName,group[i].Name);//����� ������ ������
			}
		}
	}
}

*/

