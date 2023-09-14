#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 1024
typedef char datatype;
typedef struct {
	datatype data[MAXSIZE];
	int last;
}sequenlist;

int insert(sequenlist* L, datatype x, int i) {
	int j;
	if (L->last == MAXSIZE - 1) {
		printf("overflow");
		return 0;
	}
	else if ((i < 0) || (i > L->last)) {
		printf("error, please input the right 'i'");
		return 0;
	}
	else {
		for (j = L->last; j >= i; j--)
			L->data[j + 1] = L->data[j];
		L->data[i] = x;
		L->last = L->last + 1;
	}

	return (1);
}

/* 删除第i个元素，元素从0开始计数 */
int dellist(sequenlist* L, int i) {
	if ((i < 0) || (i > L->last)) {
		printf("error, please input the right i");

		return 0;
	}
	else {
		for (; i < L->last; i++)
			L->data[i] = L->data[i + 1];
		L->last = L->last - 1;
		return(1);
	}
}

/* 建立顺序表，其元素为单个字符 */
void creatlist(sequenlist* L) {
	int n, i;
	char tmp;
	printf("请输入数据的个数：\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		printf("data[%d]=", i);
		fflush(stdin);
		scanf_s("%c", &tmp);
		L->data[i] = tmp;
	}
	L->last = n - 1;
	printf("\n");
}

/* 打印顺序表 */
void printout(sequenlist* L) {
	int i;
	for (i = 0; i < L->last; i++) {
		printf("data[%d]=", i);
		printf("%c\n", L->data[i]);
	}
}

int main(void) {
	sequenlist* L;
	char cmd, x;
	int i;
	L = (sequenlist*)malloc(sizeof(sequenlist));
	creatlist(L);
	printf(L);
	do {
		printf("i,I...插入\n");
		printf("d,D...删除\n");
		printf("q,Q...退出\n");
		do {
			fflush(stdin);
			scanf_s("%c", &cmd);
		} while ((cmd != 'd') && (cmd != 'D') && (cmd != 'q') && (cmd != 'Q') && (cmd != 'i') && (cmd != 'I'));
		switch (cmd) {
		case 'i':
		case 'I':
			printf("请输入你要插入的数据：");
			fflush(stdin);
			scanf_s("%c", &x);
			printf("请输入你要插入的位置：");
			scanf_s("%d", &i);
			insert(L, x, i);
			printout(L);
			break;
		case 'd':
		case 'D':
			printf("请输入你要删除元素的位置：");
			fflish(stdin);
			scanf_s("%d", &i);
			dellist(L, i);
			printout(L);
			break;
		}
	} while ((cmd != 'q') && (cmd != 'Q'));
}