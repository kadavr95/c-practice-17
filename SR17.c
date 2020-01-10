//��������������� ������ 17. ������� 2. ������� ������� (T02-01c). Dimini Inc. & Govnokod Inc.  (c)2013
#include <stdio.h>//����������� ���������
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct tAddress
{ /* ��������� ������ */
	char City[50]; /* ����� */
	char Street[50]; /* ����� */
	int House; //���
	int Flat; /* �������� */
};

struct tStudentCard //����� �����������
{
	char SurName[50]; /* ������� */
	char Name[50]; /* ��� */
	struct tAddress Address; /* ����� */
	char Department[50]; //���������
	int Points; //�����
};

int readfromfile(int *nmbr,struct tStudentCard *list); //��������� �������
int pointssearch(int places , char dept[50], struct tStudentCard *list, int number, int *okpoints);
int passed(char dept[50], struct tStudentCard *list, int number, int okpoints);
int campus(char dept[50],  int okpoints,struct tStudentCard *list,int number, int *places);

int main(void)//������� �������
{
	struct tStudentCard list[40];
	int placeT=6, placeKiB=5, placeU=4, number=0, okpointsT=0,okpointsKiB=0,okpointsU=0,placescampus=0;
	readfromfile(&number,list);//���������� �� �����
	printf("Points to departments\n");//����������� ��������� ������ �� ����������
	pointssearch(placeT,"T",list,number,&okpointsT);
	pointssearch(placeKiB,"KiB",list,number,&okpointsKiB);
	pointssearch(placeU,"U",list,number,&okpointsU);
	printf("\nAccepted students:\n");//������ ���������
	passed("T",list,number,okpointsT);
	printf("\n");
	passed("KiB",list,number,okpointsKiB);
	printf("\n");
	passed("U",list,number,okpointsU);
	printf("\n");
	campus("T",okpointsT,list,number,&placescampus);//������� ���� ��� ���������
	campus("KiB",okpointsKiB,list,number,&placescampus);
	campus("U",okpointsU,list,number,&placescampus);
	printf("Campus needs %d places\n",placescampus);
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}


int readfromfile(int *nmbr,struct tStudentCard *list)//���������� �� �����
{
	FILE *filepointer;//����������� ����������
	int i=0;
	*nmbr=0;//����� ���������� ��������� � �������
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
			i++;//��������� ������ ��������
			*nmbr=*nmbr+1;//��������� ���������� ���������
		}
		fclose(filepointer);//�������� �����
	}
	*nmbr=*nmbr-1;//������������ � ������ ���������� ���� � ����� �����
}

int pointssearch(int places, char dept[50], struct tStudentCard *list, int number,int *okpoints)//����� ����� � ������������ ������ ��������� � ���
{
	int plc=0,nmr,maxpoint,i,j;
	maxpoint=0;//��������� �������� ������������� �����
	while(plc<=places)
	{
		for (i = 0; i < number; i++)//����������� ������������� ��������
		{
			if (strstr(list[i].Department,dept)>0)//���� � ������� ����������
			{
				if (list[i].Points>=maxpoint)//���� ����� ������ �������������
				{
					maxpoint=list[i].Points;//����. ���� �����
					nmr=i; //����������� ������ ����� ��������
				}
			}
		}
		plc=plc+1;//����� 1 �����
		list[nmr].Points=list[nmr].Points*(-1);//���������� �� ������� ��������� ������
		if (plc==places)//���� ��������� �����
		{
			*okpoints=maxpoint;//��������� ����
		}
		maxpoint=0;//����� ����. ��������
	}
	for (i = 0; i < number; i++)//������� ������ � ���������� ���������
	{
		if (list[i].Points<0)
		{
			list[i].Points=list[i].Points*(-1);
		}
	}
	printf("Department %s accepts with %d points\n",dept,*okpoints); //����� ���������� �����
}

int passed(char dept[50], struct tStudentCard *list, int number,int okpoints)//�������� ��������
{
	int i;
	printf("Department %s\n",dept);//����� ����������
	for (i = 0; i < number; i++)//����� ���������
	{
		if (strstr(list[i].Department,dept)>0)//� ������ �����������
		{
			if (list[i].Points>=okpoints)//� ������ ���� ���������� �� ����
			{
				printf("%s %s from %s %s street %d, %d with %d points\n",list[i].SurName,list[i].Name,list[i].Address.City,list[i].Address.Street,list[i].Address.House,list[i].Address.Flat,list[i].Points);//����� ������ ��������
			}
		}
	}

}

int campus(char dept[50],  int okpoints,struct tStudentCard *list,int number, int *places)//����� � ���������
{
	int i;
	for (i = 0; i < number; i++)//����� ���������
	{
		if ((strstr(list[i].Address.City,"Moscow")<=0)&& (strstr(list[i].Department,dept)>0) &&(list[i].Points>=okpoints))//��������� ��������� ����� �� ���������� � �� ������� � ������
		{
			*places=*places+1;//���������� ����� ������ ����
		}
	}
}
