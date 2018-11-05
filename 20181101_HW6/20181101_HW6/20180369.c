#include <stdio.h>
#include <string.h>

/*
Single line
�̸�    �������    ���� ...

Multi line
�̸� ...
������� ...
���� ...

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
	char *gArr[2] = { "male", "female" };
	int chk;

	// �⺻�� 5�� ����
	struct Human Harr[10];
	struct Human A = { "AAA", {2000, 1, 1}, 0, "AAAA", "00000000000" };
	struct Human B = { "BBB", {2000, 12, 1}, 0, "BBBB", "00000000000" };
	struct Human C = { "CCC", {2001, 1, 1}, 0, "CCCC", "00000000000" };
	struct Human D = { "DDD", {2001, 1, 30}, 0, "DDDD", "00000000000" };
	struct Human E = { "EEE", {2002, 1, 1}, 0, "EEEE", "00000000000" };
	Harr[0] = A;
	Harr[1] = B;
	Harr[2] = C;
	Harr[3] = D;
	Harr[4] = E;	

	// ���� �Է¹޾� Harr �� ����
	int exit = 1, count = 5;
	do
	{
		printf_s("\n=== �Ż���� �Է� ===\n");

		printf_s("\n�̸�(20����)[Default] : ");
		scanf_s("%s", Harr[count].name, 20);
		printf_s("\n����(0 = male, 1 = female)[male] : ");
		scanf_s("%d", &Harr[count].gender);
		printf_s("\n�������(YYYY MM DD)[2000.1.1] : ");
		scanf_s("%d %d %d", &Harr[count].birth.year, &Harr[count].birth.month, &Harr[count].birth.date);
		printf_s("\n�ּ�(30����)[Default] : ");
		scanf_s("%s", Harr[count].addr, 30);
		printf_s("\n��ȭ��ȣ(���ڸ�)[000-0000-0000] : ");
		scanf_s("%s", Harr[count].num, 20);

		printf_s("\n�Է� ����(0) ���� �Է�(�ƹ� ����) : ");
		scanf_s("%d", &exit);

		count++;
	} while (exit != 0|| count==10); 
	// False = 0, True = 1
	

	//�Ż���� ���
	printf_s("\n�̸�\t\t�������\t����\t�ּ�\t��ȭ��ȣ\n");
	for (int i = 0; i < count; i++) {
		printf_s("\n%s\t\t%d.%d.%d\t%s\t%s\t", Harr[i].name, Harr[i].birth.year, Harr[i].birth.month, Harr[i].birth.date, gArr[Harr[i].gender], Harr[i].addr);
		for (int j = 0; j < strlen(Harr[i].num); j++) {
			if (j == 3 || j == 7) {
				printf_s("-%c", Harr[i].num[j]);
			}else
				printf_s("%c", Harr[i].num[j]);
		}
	}

	sort(Harr, 0);

	/*
	printf_s("\n�̸��� ����(0) ������ϼ� ����(1) : \n");
	scanf_s("%d", &chk);
	
	sort(chk);
	*/
	printf_s("\n\n");
}

//0 > �̸���, 1 > ������ϼ� ����
//�̰� main�� Harr ���� �ٲٰ� ������ �ȵǳ�
int sort(struct Human Harr[], int chk) {
	struct Human temp;
	if (chk == 0) {//�̸���	L > H
		printf_s("\n�̸��� ����\n");
		for (int i = 1; i < 9; i++) {
			if (strcmp(Harr[i].name, Harr[i+1].name) < 0) {
				temp = Harr[i];
				Harr[i] = Harr[i + 1];
				Harr[i + 1] = temp;
			}
		}

		printf_s("\n�̸�\t\t�������\t����\t�ּ�\t��ȭ��ȣ\n");
		for (int i = 0; i < 5; i++) {
			printf_s("\n%s\t\t%d.%d.%d\t%s\t%s\t", Harr[i].name, Harr[i].birth.year, Harr[i].birth.month, Harr[i].birth.date, Harr[i].gender, Harr[i].addr);
			for (int j = 0; j < strlen(Harr[i].num); j++) {
				if (j == 3 || j == 7) {
					printf_s("-%c", Harr[i].num[j]);
				}
				else
					printf_s("%c", Harr[i].num[j]);
			}
		}
	}
	else if (chk == 1) {//������� L > H
		for (int i = 1; i < 9; i++) {//�� ��	L > H
			if (Harr[i].birth.year > Harr[i + 1].birth.year) {//Y �ٸ�
				temp = Harr[i];
				Harr[i] = Harr[i + 1];
				Harr[i + 1] = temp;
			}
			else if (Harr[i].birth.year == Harr[i + 1].birth.year) {
				if (Harr[i].birth.month > Harr[i + 1].birth.month) {//Y ���� M �ٸ�
					temp = Harr[i];
					Harr[i] = Harr[i + 1];
					Harr[i + 1] = temp;
				}
				else if (Harr[i].birth.month == Harr[i + 1].birth.month) {
					if (Harr[i].birth.date > Harr[i + 1].birth.date) {//Y M ���� D �ٸ�
						temp = Harr[i];
						Harr[i] = Harr[i + 1];
						Harr[i + 1] = temp;
					}
					else {//Y M D ����
					}
				}
			}
		}
	}
}
