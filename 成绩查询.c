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
	printf("请输入学生人数\n");
	scanf("%d",&n);
	printf("请输入课程数\n");
	scanf("%d",&m);
	inputScore(stu,n,m,fp2);
	averScore(stu,aver,n,m);
	mmScore(stu,aver,n,m,fp1);
	getchar();
	printf("您还需要继续查询吗？（y/n或Y/N）\n");
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
	fp2=fopen("学生信息.txt","a");
	for(i=0;i<n;i++)
	{
		printf("请依次输入第%d学生学号，姓名，成绩：(格式：100 小明)\n",i+1);
		scanf("%ld %s",&stu[i].studentID,&stu[i].studentName);
		fprintf(fp2,"%ld        %s            ",stu[i].studentID,stu[i].studentName);
		for(j=0;j<m;j++)
		{
			printf("第%d门课程的成绩：\n",j+1);
			scanf("%d",&stu[i].score[j]);
			fprintf(fp2,"%d            ",stu[i].score[j]);
		}
		fprintf(fp2,"\n");
	}
	fclose(fp2);
	printf("学生信息保存成功\n");
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
	fp1=fopen("成绩.txt","a");
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
		printf("第%d门课程的平均成绩是：%0.2f\n",j+1,aver[j]);
		printf("-------------------------------------------------------------------------------------------------------------\n");
		printf("第%d门课程的最高分是：%d\n相应的学生信息：%ld %s\n",j+1,stu[ka].score[j],stu[ka].studentID,stu[ka].studentName);
		printf("第%d门课程的最低分是：%d\n相应的学生信息：%ld %s\n",j+1,stu[ki].score[j],stu[ki].studentID,stu[ki].studentName);
		printf("-------------------------------------------------------------------------------------------------------------\n\n");
		fprintf(fp1," %d              %0.2f            %d                    %ld %s                    %d                   %ld %s\n",j+1,aver[j],stu[ka].score[j],stu[ka].studentID,stu[ka].studentName,stu[ki].score[j],stu[ki].studentID,stu[ki].studentName);
	}
	fclose(fp1);
	printf("成绩文件保存成功\n");
}
void createFile(FILE *fp1,FILE *fp2)
{
	fp1=fopen("成绩.txt","w");
	fp2=fopen("学生信息.txt","w");
	if(!fp1&&!fp2)
	{
		printf("文件创建失败\n");
		exit(0);
	}
	fprintf(fp1,"%s        %s         %s        %s        %s        %s\n","课程","平均成绩","最高分","最高分相关学生信息","最低分","最低分相关学生消息");
	fprintf(fp2,"%s        %s         %s\n","学号","姓名","成绩");
	fclose(fp1);
	fclose(fp2);
	printf("文件创建成功\n");
}
