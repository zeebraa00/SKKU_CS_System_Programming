#include <stdio.h>
#include <string.h>
#include <time.h>

#define Digit 100000

char zero[Digit];

char temp[Digit]; // input 적절하게 초기화할 때 사용할 것
char output[Digit] = {'0', }; // 최종 연산 결과
char tmp[Digit] = {'0', }; // 연산 결과 처리할 때 사용
char tmp_2[Digit] = {'0', }; // 연산 결과 처리할 때 사용
int length; // output의 자릿수

char input1[Digit];
char input2[Digit];
char file_buff[Digit];

void initOutput()
{
	// for (int i = 0; i < Digit - 1; i++)
	// {
	// 	output[i] = '0';
	// }
	// output[Digit - 1] = '\0';
	strcpy(output, zero);
}

void initTmp()
{
	// for (int i = 0; i < Digit-1; i++)
	// {
	// 	tmp[i] = '0';
	// }
	// tmp[Digit - 1] = '\0';
	strcpy(tmp, zero);
}

void initTmp2()
{
	// for (int i = 0; i < Digit-1; i++)
	// {
	// 	tmp_2[i] = '0';
	// }
	// tmp_2[Digit - 1] = '\0';
	strcpy(tmp_2,zero);
}

void Add(char input1[], char input2[])
{
	int sum;
	int carry=0; // 자릿수 올림 변수
	int temp1;
	int temp2;

	//output 초기화
	initOutput();

	// 큰 수 더하기
	for (int i = Digit - 2; i > 0; i--)
	{
		// temp1 = (input1[i] - '0');
		// temp2 = (input2[i] - '0');
		sum = (input1[i] - '0') + (input2[i] - '0') + carry;
		carry = sum / 10;
		sum = sum % 10;
		output[i] = (sum + '0');
	}
}

void Product(char input1[], char input2[])
{
	int sum;
	int carry = 0;
	int temp1;
	int temp2;

	// 배열 전처리
	initOutput();
	initTmp();
	initTmp2();

	// 큰 수 곱하기
	for (int i = Digit-2; i > 0; i--)
	{
		for (int j = Digit-2; j > 0; j--)
		{
			// temp1 = input1[i] - '0';
			// temp2 = input2[j] - '0';
			sum = (input1[i] - '0') * (input2[j] - '0') + carry;
			carry = sum / 10;
			sum = sum % 10;
			tmp[j-(Digit-2-i)] = sum+'0';
		}
		Add(tmp_2, tmp);
		// for (int i = 0; i < Digit; i++)
		// {
		// 	tmp_2[i] = output[i];
		// }
		strcpy(tmp_2,output);
		// tmp 초기화
		// for (int i = 0; i < Digit; i++)
		// {
		// 	tmp[i] = '0';
		// }
		// tmp[Digit - 1] = '\0';
		strcpy(tmp,zero);
	}

	//printf("곱셈결과 : %s\n", tmp_2);
	// for (int i = 0; i < Digit; i++)
	// {
	// 	output[i] = tmp_2[i];
	// }
	strcpy(output,tmp_2);
}

void getInput1(FILE *fp)
{
	fgets(file_buff, sizeof(file_buff), fp);
	strcpy(input1,file_buff);
	input1[strlen(input1)-1]='\0';
	// printf("the first parameter : %s\n",input1);
}

void getInput2(FILE *fp)
{
	fgets(file_buff, sizeof(file_buff), fp);
	strcpy(input2,file_buff);
	input2[strlen(input2)-1]='\0';
	// printf("the second parameter : %s\n",input2);
}

void readFile(FILE *fp)
{
	getInput1(fp);
	getInput2(fp);
}

void writeAddError()
{
	FILE *fp;
	fp = fopen("addError.txt","w");
	strcpy(file_buff,"error occured in addition");
	fputs(file_buff, fp);
	fclose(fp);
}

void writeMultError()
{
	FILE *fp;
	fp = fopen("multError.txt","w");
	strcpy(file_buff,"error occured in multiplication");
	fputs(file_buff, fp);
	fclose(fp);
}

void writeAddResult()
{	
	FILE *fp;
	fp = fopen("addOutput.txt","w");
	
	strcpy(file_buff,output + length);
	fputs(file_buff, fp);
	fclose(fp);
}

void writeMultResult()
{	
	FILE *fp;
	fp = fopen("multOutput.txt","w");

	strcpy(file_buff,output + length);
	fputs(file_buff, fp);
	fclose(fp);
}

int length1()
{
	// int len;
	// for (len = 0; input1[len] != '\0'; len++); // len이 자릿수 의미

	// return len;
	return strlen(input1);
}

void initInput1()
{
	int len;
	// len이 자릿수 의미
	len = length1();

	for ( int i=0 ; i < Digit-len-1 ; i++)
	{
		temp[i] = '0'; // 앞을 다 0으로 채우기
	}
	// zero[Digit-len-1] = '\0';
	// strcpy(temp, zero);
	// zero[Digit-len-1] = '0';

	for (int i = Digit-len-1 ; i < Digit ; i++)
	{
		temp[i] = input1[i-(Digit-len-1)]; // 유효한 숫자들 맨 뒤로 뺴기
	}

	for (int i = 0; i < Digit; i++)
	{
		input1[i] = temp[i]; // temp에 있던거 input1으로 복붙
	}
	// strcpy(input1,temp);
}

int length2()
{
	// int len;
	// for (len = 0; input2[len] != '\0'; len++); // len이 자릿수 의미

	// return len;
	return strlen(input2);
}

void initInput2()
{
	int len;
	// len이 자릿수 의미
	len = length2();

	for (int i = 0; i < Digit - len - 1; i++)
	{
		temp[i] = '0'; // 앞을 다 0으로 채우기
	}
	// zero[Digit-len-1] = '\0';
	// strcpy(temp, zero);
	// zero[Digit-len-1] = '0';

	for (int i = Digit - len - 1; i < Digit; i++)
	{
		temp[i] = input2[i - (Digit - len - 1)]; // 유효한 숫자들 맨 뒤로 뺴기
	}

	for (int i = 0; i < Digit; i++)
	{
		input2[i] = temp[i]; // temp에 있던거 input2으로 복붙
	}
	// strcpy(input2,temp);
}

void initiateOutput()
{
// 	for (int i=0; i<Digit; i++) {
// 		output[i]='0';
// 	}
	strcpy(output,zero);
}

void addBigInt()
{
	Add(input1, input2);
	for (length = 0; output[length] == '0'; length++);
	if (length == Digit - 1)
	{
		printf("0\n"); // 결과값==0 일 때 예외처리
		writeAddError();
	}
	else
	{
		printf("Add result : %s\n", output + length);
		writeAddResult();
	}
}

int lengthOutput()
{
	int length;
	for (length = 0; output[length] == '0'; length++);

	return length;
}

void multBigInt()
{
	Product(input1, input2);

	length = lengthOutput();

	if (length == Digit - 1)
	{
		printf("0\n"); // 결과값==0 일 때 예외처리
		writeMultError();
	}
	else
	{
		printf("Mult result : %s\n", output + length);
		writeMultResult();
	}
}

int main()
{
	FILE *fp;
    clock_t start, finish;
    start = clock();

	for (int i=0; i<Digit-1; i++) {
		zero[i]='0';
	}
	zero[Digit-1]='\0';

	output[Digit-1]='\0';
	tmp[Digit-1]='\0';
	tmp_2[Digit-1]='\0';

	fp = fopen("input.txt","r");
    readFile(fp);
	fclose(fp);

	printf("the first parameter : %s\n",input1);
	printf("the second parameter : %s\n",input2);

	// input1 배열 초기화
	initInput1();
	
	// input2 배열 초기화
	initInput2();
	
	// 큰 수 덧셈
	addBigInt();

	// output 배열 초기화
	initiateOutput();

	// 큰 수 곱셈
	multBigInt();

	// 총 프로그램 실행시간 출력
    finish = clock();
    printf("TIME : %lf\n",(double)(finish-start)/CLOCKS_PER_SEC);

	return 0;
}