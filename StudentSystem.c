#include <stdio.h>
#include <stdlib.h>
#define CourseNum 3 //�γ�����
#define N 100
int stuNum = 0;
typedef struct
{
	int flag;
	int Class;
	int Sno;
	char Name[15];
	char Sex;
	float Score[CourseNum];
	float Total;
	float Average;

} STUDENT;
void Menu(float x)
{
	printf("\n--------------------------------ѧ������ϵͳ--------------------------------\n\n");
	if (x == 0)
	{
		printf("-------------1:���ѧ����Ϣ                      2:ɾ��ѧ����Ϣ-------------\n\n");
		printf("-------------3:��ѯѧ����Ϣ                      4:��ѯ�ɼ���Ϣ-------------\n\n");
		printf("-------------5:ѧ���ɼ�����                      6:ѧ����Ϣ����-------------\n\n");
		printf("-------------7:ѧ����Ϣ����                      0:�˳�����ϵͳ-------------\n\n");
	}
	else if (x == 3)
	{
		printf("-------------1:����ѧ����ѯ                      2:�༶ѧ����ѯ-------------\n\n");
	}
	else if (x == 4)
	{
		printf("-------------1:�γ̳ɼ���ѯ                      2:ѧ���ɼ���ѯ-------------\n\n");
	}
	else if (x == 4.5)
	{
		printf("-------------1:��ѧ�ɼ�         2:Ӣ��ɼ�         3:������ɼ�-------------\n\n");
	}
	else if (x == 5)
	{
		printf("-------------1:�༶�ܷ�����                      2:�༶�ֽܷ���-------------\n\n");
		printf("-------------3:�γ�ƽ������                      4:�γ�ƽ������-------------\n\n");
	}
	printf("----------------------------------------------------------------------------\n\n");
}
int Lookup(STUDENT student[], int cla, int sno)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (student[i].flag == 1 && student[i].Class == cla && student[i].Sno == sno)
			return 0;
	}
	return 1;
}
void Add(STUDENT student[], int n)
{
	int i = 0, j, index = 0;
	float total = 0;
	printf("������ѧ����Ϣ[�༶ ѧ�� ���� �Ա� ��ѧ Ӣ�� ������ɼ�]:\n");
	while (i != n)
	{ //�жϳɹ�����������Ƿ�ﵽ��Ҫ���������
		if (student[index].flag == 0)
		{ //���flagΪ0��ʾ��Ч����
			scanf("%d %d %s %c", &student[index].Class, &student[index].Sno, student[index].Name, &student[index].Sex);
			if (Lookup(student, student[index].Class, student[index].Sno))
			{
				for (j = 0; j < CourseNum; j++)
				{
					scanf("%f", &student[index].Score[j]); //����ɼ�
					total += student[index].Score[j];
				}
				student[index].flag = 1;								   //��ʼ��Ϊ1��ʾΪ��Ч��Ϣ
				student[index].Total = total;							   //�����ܳɼ�
				student[index].Average = student[index].Total / CourseNum; //����ƽ����
				i++;													   //�ɹ�����+1
				stuNum++;												   //ѧ������+1
				printf("��ӳɹ�\n");
				total = 0;
			}
		}
		index++; //�����±�+1
	}
}
void StuQuery(STUDENT student[], int flag, int cla, int sno)
{
	printf("%-3s %-10s %-6s %-6s  %-6s  %-6s  %-6s  %-6s  %-6s\n", "�༶", "ѧ��", "����", "�Ա�", "��ѧ", "Ӣ��", "�����", "�ܷ�", "ƽ����");
	if (flag == 1)
	{
		int i = 0, j;
		for (i = 0; i < N; i++)
		{
			if (student[i].Class == cla && student[i].Sno == sno && student[i].flag == 1)
			{
				printf("%-4d %-10d %-6s %-6c", student[i].Class, student[i].Sno, student[i].Name, student[i].Sex);
				for (j = 0; j < CourseNum; j++)
				{
					printf("  %-6.2f", student[i].Score[j]);
				}
				printf("  %-6.2f  %-6.2f", student[i].Total, student[i].Average);
			}
		}
	}
	else if (flag == 2)
	{
		int i = 0, j, count = 0;
		for (i = 0; i < N; i++)
		{
			if (student[i].Class == cla && student[i].flag == 1)
			{
				printf("%-4d %-10d %-6s %-6c", student[i].Class, student[i].Sno, student[i].Name, student[i].Sex);
				for (j = 0; j < CourseNum; j++)
				{
					printf("  %-6.2f", student[i].Score[j]);
				}
				printf("  %-6.2f  %-6.2f", student[i].Total, student[i].Average);
				printf("\n");
				if (count == stuNum)
					break;
			}
		}
	}
}
void Delete(STUDENT student[], int cla, int sno)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (student[i].Class == cla && student[i].Sno == sno && student[i].flag == 1)
		{
			student[i].flag = 0;
			stuNum--;
			printf("ɾ���ɹ�");
			return;
		}
	}
	printf("û���ҵ�ѧ����Ϣ!");
}
void ScoreQuery(STUDENT student[], int flag, int subject, int cla)
{
	int i;
	if (flag == 1)
	{
		if (subject == 0)
		{
			printf("%-3s %-10s %-6s %-6s  %-6s\n", "�༶", "ѧ��", "����", "�Ա�", "��ѧ");
		}
		else if (subject == 1)
		{
			printf("%-3s %-10s %-6s %-6s  %-6s\n", "�༶", "ѧ��", "����", "�Ա�", "Ӣ��");
		}
		else if (subject == 2)
		{
			printf("%-3s %-10s %-6s %-6s  %-6s\n", "�༶", "ѧ��", "����", "�Ա�", "�����");
		}
		for (i = 0; i < N; i++)
		{
			if (student[i].Class == cla && student[i].flag == 1)
			{
				printf("%-4d %-10d %-6s %-6c  %-6.2f", student[i].Class, student[i].Sno, student[i].Name, student[i].Sex, student[i].Score[subject]);
				printf("\n");
			}
		}
	}
	else if (flag == 2)
	{
		int j;
		for (i = 0; i < N; i++)
		{
			if (student[i].Class == cla && student[i].Sno == subject && student[i].flag == 1)
			{
				printf("%-3s %-10s %-6s %-6s %-6s %-6s %-6s\n", "�༶", "ѧ��", "����", "�Ա�", "��ѧ", "Ӣ��", "�����");
				printf("%-4d %-10d %-6s %-6c", student[i].Class, student[i].Sno, student[i].Name, student[i].Sex);
				for (j = 0; j < CourseNum; j++)
				{
					printf(" %-6.2f", student[i].Score[j]);
				}
				break;
			}
		}
	}
}
void TotalSort(STUDENT student[], int cla, STUDENT *stuSort[], int flag)
{
	int i, j, count = 0;
	if (flag == 1 || flag == 2)
	{
		for (i = 0; i < stuNum; i++)
		{
			if (student[i].flag != 0 && student[i].Class == cla)
			{
				stuSort[count] = student + i;
				count++;
			}
		}
	}
	if (flag == 3 || flag == 4)
	{
		for (i = 0; i < stuNum; i++)
		{
			if (student[i].flag != 0)
			{
				stuSort[count] = student + i;
				count++;
			}
		}
	}
	if (flag == 1)
	{
		STUDENT *p = student;
		for (i = 0; i < count; i++)
		{
			for (j = i + 1; j < count; j++)
			{
				if (stuSort[i]->Total > stuSort[j]->Total)
				{
					p = stuSort[j];
					stuSort[j] = stuSort[i];
					stuSort[i] = p;
				}
			}
		}
	}
	else if (flag == 2)
	{
		STUDENT *p = student;
		for (i = 0; i < count; i++)
		{
			for (j = i + 1; j < count; j++)
			{
				if (stuSort[i]->Total < stuSort[j]->Total)
				{
					p = stuSort[j];
					stuSort[j] = stuSort[i];
					stuSort[i] = p;
				}
			}
		}
	}
	else if (flag == 3)
	{
		STUDENT *p = student;
		for (i = 0; i < count; i++)
		{
			for (j = i + 1; j < count; j++)
			{
				if (stuSort[i]->Average > stuSort[j]->Average)
				{
					p = stuSort[j];
					stuSort[j] = stuSort[i];
					stuSort[i] = p;
				}
			}
		}
	}
	else if (flag == 4)
	{
		STUDENT *p = student;
		for (i = 0; i < count; i++)
		{
			for (j = i + 1; j < count; j++)
			{
				if (stuSort[i]->Average < stuSort[j]->Average)
				{
					p = stuSort[j];
					stuSort[j] = stuSort[i];
					stuSort[i] = p;
				}
			}
		}
	}
	printf("%-3s %-10s %-6s %-6s  %-6s  %-6s  %-6s  %-6s  %-6s\n", "�༶", "ѧ��", "����", "�Ա�", "��ѧ", "Ӣ��", "�����", "�ܷ�", "ƽ����");
	for (i = 0; i < count; i++)
	{
		printf("%-4d %-10d %-6s %-6c", stuSort[i]->Class, stuSort[i]->Sno, stuSort[i]->Name, stuSort[i]->Sex);
		for (j = 0; j < CourseNum; j++)
		{
			printf("  %-6.2f", stuSort[i]->Score[j]);
		}
		printf("  %-6.2f  %-6.2f\n", stuSort[i]->Total, stuSort[i]->Average);
	}
}

void write(STUDENT student[])
{
	int i, j, count = 0;
	FILE *fp = fopen("student.txt", "w+");
	fprintf(fp, "%d\n", stuNum);
	for (i = 0; i < N; i++)
	{
		if (student[i].flag == 1 && !(Lookup(student, student[i].Class, student[i].Sno)))
		{
			fprintf(fp, "%d %d %s %c ", student[i].Class, student[i].Sno, student[i].Name, student[i].Sex);
			for (j = 0; j < CourseNum; j++)
			{
				fprintf(fp, "%.2f ", student[i].Score[j]);
			}
			fprintf(fp, "%.2f ", student[i].Total);
			fprintf(fp, "%.2f\n", student[i].Average);
			count++;
		}
		if (count == stuNum)
		{
			for (; i < N; i++)
			{
				fprintf(fp, "%c", '\n');
			}
			break;
		}
	}
	fclose(fp);
	fp = NULL;
}
void Read(STUDENT student[])
{
	int i, j, count = 0;
	FILE *fp = fopen("student.txt", "r");
	fscanf(fp, "%d\n", &stuNum);
	for (i = 0; i < N; i++)
	{
		student[i].flag = 1;
		fscanf(fp, "%d %d %s %c", &student[i].Class, &student[i].Sno, student[i].Name, &student[i].Sex);
		for (j = 0; j < CourseNum; j++)
		{
			fscanf(fp, " %f", &student[i].Score[j]);
		}
		fscanf(fp, " %f", &student[i].Total);
		fscanf(fp, " %f\n", &student[i].Average);
		if (count == stuNum)
		{
			for (; i < N; i++)
			{
				student[i].flag = 0;
			}
			break;
		}
		count++;
	}
	fclose(fp);
	fp = NULL;
}
int main(void)
{
	int select;
	STUDENT student[N] = {0};
	STUDENT *stuSort[N] = {NULL};
	while (1)
	{
		Menu(0);
		printf("�����빦����:");
		fflush(stdin);
		scanf("%d", &select);
		switch (select)
		{
		case 1:
		{
			int n;
			printf("������Ҫ��ӵ�����:");
			fflush(stdin);
			scanf("%d", &n);
			Add(student, n);
			break;
		}
		case 2:
		{
			int cla, sno;
			printf("������ɾ��ѧ���İ༶��ѧ��");
			fflush(stdin);
			scanf("%d%d", &cla, &sno);
			Delete(student, cla, sno);
			break;
		}
		case 3:
		{
			Menu(3);
			printf("�������ѯ������:");
			fflush(stdin);
			scanf("%d", &select);
			switch (select)
			{
			case 1:
			{
				int cla, sno;
				printf("�������ѯѧ���İ༶��ѧ��:");
				scanf("%d%d", &cla, &sno);
				StuQuery(student, 1, cla, sno);
				break;
			}
			case 2:
			{
				int cla, sno = 0;
				printf("�������ѯ�༶:");
				fflush(stdin);
				scanf("%d", &cla);
				StuQuery(student, 2, cla, sno);
				break;
			}
			}

			break;
		}
		case 4:
		{
			Menu(4);
			printf("�������ѯ������:");
			fflush(stdin);
			scanf("%d", &select);
			switch (select)
			{
			case 1:
			{
				int subject, cla;
				Menu(4.5);
				printf("������Ҫ��ѯ�Ŀγ�����źͰ༶:");
				fflush(stdin);
				scanf("%d%d", &subject, &cla);
				ScoreQuery(student, 1, subject - 1, cla);
				break;
			}
			case 2:
			{
				int sno, cla;
				printf("������Ҫ��ѯ�İ༶��ѧ��:");
				fflush(stdin);
				scanf("%d%d", &cla, &sno);
				ScoreQuery(student, 2, sno, cla);
				break;
			}
			}

			break;
		}
		case 5:
		{
			Menu(5);
			printf("�������ѯ������:");
			fflush(stdin);
			scanf("%d", &select);
			switch (select)
			{
			case 1:
			{
				int cla;
				printf("����������İ༶:");
				fflush(stdin);
				scanf("%d", &cla);
				TotalSort(student, cla, stuSort, 1);
				break;
			}
			case 2:
			{
				int cla;
				printf("����������İ༶:");
				fflush(stdin);
				scanf("%d", &cla);
				TotalSort(student, cla, stuSort, 2);
				break;
			}
			case 3:
			{
				TotalSort(student, 0, stuSort, 3);
				break;
			}
			case 4:
			{
				TotalSort(student, 0, stuSort, 4);
				break;
			}
			}
			break;
		}
		case 6:
		{
			write(student);
			printf("ѧ����Ϣ����ɹ�");
			break;
		}
		case 7:
		{
			printf("ѧ����Ϣ����ɹ�");
			Read(student);
			break;
		}
		case 0:
		{
			printf("ϵͳ�˳�");
			break;
		}
		default:
		{
			printf("����������!");
		}
		}
		if (select == 0)
			break;
	}
	system("pause");
	return 0;
}
