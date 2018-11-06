#include <stdio.h>
#include <string.h>

/*
Single line
이름    생년월일    성별 ...

Multi line
이름 ...
생년월일 ...
성별 ...

sorting

*/
int prtList(struct Human Harr[], int size);
int swap(struct Human *H1, struct Human *H2);
int sort(struct Human Harr[], int size, int chk);

struct Birth {
	int year, month, date;
};
struct Human {
	char name[20];
	struct Birth birth;
	int gender;
	char addr[30];
	char num[20];
};

main() {
	printf_s("\n20180369 양원우 6주차 과제\n");
	int chk;

	// 기본값 5개 저장
	struct Human Harr[10];
	struct Human A = { "Noah", {1998, 3, 23}, 0, "Seoul", "00000000000" };
	struct Human B = { "Wonwoo", {1998, 5, 23}, 0, "Seoul", "00000000000" };
	struct Human C = { "Aiden", {1987, 11, 7}, 0, "Seoul", "00000000000" };
	struct Human D = { "Hannah", {1987, 11, 23}, 1, "Seoul", "00000000000" };
	struct Human E = { "Camila", {2001, 8, 9}, 1, "Seoul", "00000000000" };
	Harr[0] = A;
	Harr[1] = B;
	Harr[2] = C;
	Harr[3] = D;
	Harr[4] = E;	

	// 값을 입력받아 Harr 에 넣음
	int exit = 1, count = 5;
	while (exit != 0 && count != 10) {
		printf_s("\n=== 신상명세서 입력 (%d / 10) ===\n", count+1);
		printf_s("\n이름(20글자) : ");
		scanf_s("%s", Harr[count].name, 20);
		printf_s("\n성별(0 = male, 1 = female) : ");
		scanf_s("%d", &Harr[count].gender);
		printf_s("\n생년월일(YYYY MM DD) : ");
		scanf_s("%d %d %d", &Harr[count].birth.year, &Harr[count].birth.month, &Harr[count].birth.date);
		printf_s("\n주소(30글자) : ");
		scanf_s("%s", Harr[count].addr, 30);
		printf_s("\n전화번호(11자리, 숫자만) : ");
		scanf_s("%s", Harr[count].num, 20);
		printf_s("\n입력 종료(0) 다음 입력(아무 숫자) : ");
		scanf_s("%d", &exit);
		
		if (count + 1 > 10) {
			count = 10;
		}
		else count++;
	}
	// False = 0, True = 1

	printf_s("\n\n=========== 신상명세서 ===========\n");
	prtList(Harr, count);
	printf_s("\n\n========== 이름 (Z->A) ==========\n");
	sort(Harr, count, 0);
	prtList(Harr, count);
	printf_s("\n\n======== 생년월일 (L->H) ========\n");
	sort(Harr, count, 1);
	prtList(Harr, count);

	printf_s("\n\n");
}



int prtList(struct Human Harr[], int size) {//신상명세서 출력
	char *gArr[2] = { "male", "female" };

	printf_s("\n이름\t\t생년월일\t성별\t주소\t전화번호\n");
	for (int i = 0; i < size; i++) {
		printf_s("\n%s\t\t%d.%d.%d\t%s\t%s\t", Harr[i].name, Harr[i].birth.year, Harr[i].birth.month, Harr[i].birth.date, gArr[Harr[i].gender], Harr[i].addr);
		for (int j = 0; j < strlen(Harr[i].num); j++) {
			if (j == 3 || j == 7) {
				printf_s("-%c", Harr[i].num[j]);
			}
			else
				printf_s("%c", Harr[i].num[j]);
		}
	}
}

int swap(struct Human *H1, struct Human *H2) {
	struct Human temp;
	temp = *H1;
	*H1 = *H2;
	*H2 = temp;
	return 0;
}

//0 > 이름순, 1 > 생년월일순 정렬
int sort(struct Human Harr[], int size, int chk) {
	if (chk == 0) {//이름순 H > L
		for (int i = 0; i < size - 1; i++) {// Selction sort
			for (int j = i+1; j < size; j++) {
				if (strcmp(Harr[i].name, Harr[j].name) < 0) {
					swap(&Harr[i], &Harr[j]);
				}
			}
		}
	}
	else if (chk == 1) {//생년월일 L > H
		for (int i = 0; i < size - 1; i++) {// Selction sort
			for (int j = i + 1; j < size; j++) {
				if (Harr[i].birth.year > Harr[j].birth.year) {//Y 다름
					swap(&Harr[i], &Harr[j]);
				}
				else if (Harr[i].birth.year == Harr[j].birth.year) {
					if (Harr[i].birth.month > Harr[j].birth.month) {//Y 동일 M 다름
						swap(&Harr[i], &Harr[j]);
					}
					else if (Harr[i].birth.month == Harr[j].birth.month) {
						if (Harr[i].birth.date > Harr[j].birth.date) {//Y M 동일 D 다름
							swap(&Harr[i], &Harr[j]);
						}
						else {//Y M D 동일
						}
					}
				}
			}			
		}
	}
}
