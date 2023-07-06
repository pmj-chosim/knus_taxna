#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binpres(int n, int c) {
	if (n <= 1) { 
		if (n == 1)c++; 
		 return c;
	}
	if (n % 2 == 1) {
		c++;
	}
	else;
	binpres((int)( n/ 2), c);
}

void P1() {
	FILE* fp;
	fopen_s(&fp, "in1.txt", "r");
	int n;
	fscanf_s(fp, "%d", &n);
	fclose(fp);
	int c = 0;
	printf("문제 1: %d\n",binpres(n, c));
	
}



int binsearch(int list[], int searchnum, int left, int right) {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (list[middle] < searchnum) {
			left = middle + 1;
		}
		else if (list[middle] == searchnum)return middle;
		else {
			right = middle - 1;
		}
	}return -1;
}


void P2() {
	FILE* fp;
	fopen_s(&fp, "in2.txt", "r");
	 int c ;
	int key;
	fscanf_s(fp, "%d %d", &key, &c);
	int* arr = (int*)malloc(sizeof(int) * c);
	
	for (int i = 0; i < c; i++) {
		fscanf_s(fp, "%d", &arr[i]);
	}

	printf("문제 2: %d\n",binsearch(arr, key, 0, c-1));
	fclose(fp);

}

typedef enum{lparen, rparen, plus, minus, times, divide, mod, eos, operand}precedence;
int stack[100]; char expr[100];
char L[100];
precedence get_token(char* sym, int* n) {
	*sym = L[(*n)++];
	switch (*sym) {
	case '(': return lparen; break;
	case ')': return rparen;
	case '+':return plus;
	case '-': return minus;
	case '/':return divide;
	case '*': return times;
	case '%': return mod;
	case'\0': return eos;
	default:return operand;

	}
}

void print_token(precedence e) {
	switch (e) {
	case mod: printf("%%"); break;
	case lparen: printf("("); break;
	case  rparen: printf(")"); break;
	case plus:printf("+"); break;
	case minus:printf("-"); break; 
	case divide:printf("/"); break;
	case times: printf("*"); break; 
	

	}
}
int top;
void push(int token) {
	stack[++top] = token;
}
int pop() {
	return stack[top--];
}
int isp(int d) {
	switch (d) {
	case lparen: return 0; 
	case rparen: return 19;
	case minus: case plus: return 10;
	case mod: case divide: case times: return 15;
	case eos: return 0;

	}
}

int icp(int d) {
	switch (d) {
	case lparen: return 20;
	case rparen: return 19;
	case minus: case plus: return 10;
	case mod: case divide: case times: return 15;
	case eos: return 0;

	}
}

void postfix(void) {
	char symbol;
	precedence token;
	int n = 0; top = 0;
	stack[0] = eos;
	for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n)) {
		if (token == operand)printf("%c", symbol);
		else if (token == rparen) {
			while (stack[top] != lparen)
				print_token(pop());
			pop();
		}
		else {
			while (isp(stack[top]) >= icp(token))
				print_token(pop());
			push(token);
			//printf("top :"); print_token(token); printf("\n");
		}
	}
	while ((token = pop()) != eos)print_token(token);
	printf("\n");
}

void P3() {
	FILE* fp;
	fopen_s(&fp, "in3.txt", "r");
	fscanf_s(fp, "%s", L,100);
	printf("문제 3: ");
	postfix();
}

typedef struct nn{
	int data;
	struct nn* next;
}node;

void makenode(node** head, node** rear, int d) {
	node* new = (node*)malloc(sizeof(node));
	new->data = d; new->next = NULL;
	if (!(*head)) {
		//head가 없을때
		*head = new;*rear = new;
	}
	else {
		if (d % 2) { //홀수 니까 뒤에 추가
			(*rear)->next = new;
			*rear = new;
		}
		else {
			//짝수
			new->next = *head;
			*head = new;
		}
	}
}

void print(node** head) {
	node* cur = *head;
	while (cur) {
		printf("%d (%p)  ", cur->data, cur);
		cur = cur->next;
	}
}

void P4() {
	printf("문제 4: ");
	FILE* fp;
	fopen_s(&fp, "in4.txt", "r");
	if (fp == 0) {
		printf("non file"); return;
	}
	int data;
	node* head, * rear;
	head = rear = NULL;
	while(!feof(fp)){
		fscanf_s(fp, "%d", &data, sizeof(int));
		//printf("%d ", data);
		makenode(&head, &rear, data);
	}
	fclose(fp);
	print(&head);
	
}

int main(void) {

	printf("학과 : 컴퓨터학부 학번 : 2022117119 이름:  박민진 \n");
	P1();	//문제 1에 대한 코드가 수행되는 function
	P2();	//문제 2에 대한 코드가 수행되는 function
	P3();	//문제 3에 대한 코드가 수행되는 function
	P4();	//문제 4에 대한 코드가 수행되는 function


	return 0;
}                     
