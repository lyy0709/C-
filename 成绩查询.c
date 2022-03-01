#include<stdio.h>
#define N 10
typedef struct student
{
	long studentID;
	char studentName[10];
	int score[10];
}STU;
void inputScore(STU stu[],int n,int m,FILE *fp2);
void averScore(STU stu[],float aver[],int n,int m);
void mmScore(STU stu[],float aver[],int n,int m,FILE *fp1);
void createFile(FILE *fp1,FILE *fp2);
int main()
{
	FILE *fp1,*fp2;
	float aver[N];
	STU stu[N];
	int n,m;
	char j;
	createFile(fp1,fp2);
loop:
	printf("������ѧ������\n");
	scanf("%d",&n);
	printf("������γ���\n");
	scanf("%d",&m);
	inputScore(stu,n,m,fp2);
	averScore(stu,aver,n,m);
	mmScore(stu,aver,n,m,fp1);
	getchar();
	printf("������Ҫ������ѯ�𣿣�y/n��Y/N��\n");
	scanf("%c",&j);
	if(j=='y'||j=='Y')
	{
		goto loop;
	}
	else return 0;
}
void inputScore(STU stu[],int n,int m,FILE *fp2)
{
	int i,j;
	fp2=fopen("ѧ����Ϣ.txt","a");
	for(i=0;i<n;i++)
	{
		printf("�����������%dѧ��ѧ�ţ��������ɼ���(��ʽ��100 С��)\n",i+1);
		scanf("%ld %s",&stu[i].studentID,&stu[i].studentName);
		fprintf(fp2,"%ld        %s            ",stu[i].studentID,stu[i].studentName);
		for(j=0;j<m;j++)
		{
			printf("��%d�ſγ̵ĳɼ���\n",j+1);
			scanf("%d",&stu[i].score[j]);
			fprintf(fp2,"%d            ",stu[i].score[j]);
		}
		fprintf(fp2,"\n");
	}
	fclose(fp2);
	printf("ѧ����Ϣ����ɹ�\n");
}
void averScore(STU stu[],float aver[],int n,int m)
{
	int i,j,sum[N];
	for(j=0;j<m;j++)
	{
		sum[j]=0;
		for(i=0;i<n;i++)
		{
			sum[j]=sum[j]+stu[i].score[j];
		}
		aver[j]=1.0*sum[j]/n;
	}
}
void mmScore(STU stu[],float aver[],int n,int m,FILE *fp1)
{
	int i,j,max=0,min=0,ka=0,ki=0;
	fp1=fopen("�ɼ�.txt","a");
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			if(max<stu[i].score[j])
			{
				max=stu[i].score[j];
				ka=i;
			}
			if(min>stu[i].score[j])
			{
				min=stu[i].score[j];
				ki=i;
			}
		}
		printf("��%d�ſγ̵�ƽ���ɼ��ǣ�%0.2f\n",j+1,aver[j]);
		printf("-------------------------------------------------------------------------------------------------------------\n");
		printf("��%d�ſγ̵���߷��ǣ�%d\n��Ӧ��ѧ����Ϣ��%ld %s\n",j+1,stu[ka].score[j],stu[ka].studentID,stu[ka].studentName);
		printf("��%d�ſγ̵���ͷ��ǣ�%d\n��Ӧ��ѧ����Ϣ��%ld %s\n",j+1,stu[ki].score[j],stu[ki].studentID,stu[ki].studentName);
		printf("-------------------------------------------------------------------------------------------------------------\n\n");
		fprintf(fp1," %d              %0.2f            %d                    %ld %s                    %d                   %ld %s\n",j+1,aver[j],stu[ka].score[j],stu[ka].studentID,stu[ka].studentName,stu[ki].score[j],stu[ki].studentID,stu[ki].studentName);
	}
	fclose(fp1);
	printf("�ɼ��ļ�����ɹ�\n");
}
void createFile(FILE *fp1,FILE *fp2)
{
	fp1=fopen("�ɼ�.txt","w");
	fp2=fopen("ѧ����Ϣ.txt","w");
	if(!fp1&&!fp2)
	{
		printf("�ļ�����ʧ��\n");
		exit(0);
	}
	fprintf(fp1,"%s        %s         %s        %s        %s        %s\n","�γ�","ƽ���ɼ�","��߷�","��߷����ѧ����Ϣ","��ͷ�","��ͷ����ѧ����Ϣ");
	fprintf(fp2,"%s        %s         %s\n","ѧ��","����","�ɼ�");
	fclose(fp1);
	fclose(fp2);
	printf("�ļ������ɹ�\n");
}
