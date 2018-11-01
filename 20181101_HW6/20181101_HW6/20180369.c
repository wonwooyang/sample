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
int sort(struct Human Harr[], int chk);
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
	struct Human Harr[10];
	struct Human A = { "AAA", {2000, 1, 1}, 0, "AAAA", "00000000000" };
	struct Human B = { "BBB", {2000, 12, 1}, 0, "BBBB", "00000000000" };
	struct Human C = { "CCC", {2001, 1, 1}, 0, "CCCC", "00000000000" };
	struct Human D = { "DDD", {2001, 1, 30}, 0, "DDDD", "00000000000" };
	struct Human E = { "EEE", {2002, 1, 1}, 0, "EEEE", "00000000000" };
	struct Human F = { "FFF", {2003, 1, 1}, 0, "FFFF", "00000000000" };
	Harr[0] = A;
	Harr[1] = B;
	Harr[2] = C;
	Harr[3] = D;
	Harr[4] = E;
	Harr[5] = F;

	sort(Harr, 0);

	struct Human yang = { "Wonwoo yang", {1998, 5, 23}, 0, "Seoul", "01012345678" };
	char *gArr[2] = { "male", "female" };
	

	printf_s("\n이름\t\t생년월일\t성별\t주소\t전화번호\n");
	for (int i = 0; i < 10; i++) {
		printf_s("%d", sizeof(Harr));
		printf_s("\n%s\t%d.%d.%d\t%d\t%s\t%s\n", Harr[i].name, Harr[i].birth.year, Harr[i].birth.month, Harr[i].birth.date, gArr[Harr[i].gender], Harr[i].addr, Harr[i].num);

	}
	
}


int sort(struct Human Harr[], int chk) {
	struct Human temp;
	if (chk == 0) {//이름순	L > H
		for (int i = 1; i < 9; i++) {
			if (strcmp(Harr[i].name, Harr[i+1].name) < 0) {
				temp = Harr[i];
				Harr[i] = Harr[i + 1];
				Harr[i + 1] = temp;
			}
		}
	}
	else if (chk == 1) {//생년월일 L > H
		for (int i = 1; i < 9; i++) {//년 비교	L > H
			if (Harr[i].birth.year > Harr[i + 1].birth.year) {//Y 다름
				temp = Harr[i];
				Harr[i] = Harr[i + 1];
				Harr[i + 1] = temp;
			}
			else if (Harr[i].birth.year == Harr[i + 1].birth.year) {
				if (Harr[i].birth.month > Harr[i + 1].birth.month) {//Y 동일 M 다름
					temp = Harr[i];
					Harr[i] = Harr[i + 1];
					Harr[i + 1] = temp;
				}
				else if (Harr[i].birth.month == Harr[i + 1].birth.month) {
					if (Harr[i].birth.date > Harr[i + 1].birth.date) {//Y M 동일 D 다름
						temp = Harr[i];
						Harr[i] = Harr[i + 1];
						Harr[i + 1] = temp;
					}
					else {//Y M D 동일
					}
				}
			}
		}
	}
}
