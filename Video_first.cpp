#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CUST 20 // max customer
#define MAX_CHAR 50 // ���ڿ��� max ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // ��� ����: ���� �����ϰ� �ִ� Video ���� ����
	char title[MAX_CHAR];
	int qty; // ����
} VideoInfo;

typedef struct { // ���� ����: �����ذ� (�� id�� video id)���� ����
	int custId; // ����3�ڸ�
	char title[MAX_CHAR]; // Video ����
} RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount) {
	printf("Video����	����\n");
	printf("-----------------------\n");
	for(int i = 0; i<videoCount;i++) {
		printf("%-10s	%d\n", videoList[i].title, videoList[i].qty);
	}
}

void purchaseVideo(VideoInfo videoList[], int* videoCountPtr) {
	char title[MAX_CHAR];
	int qty;
	printf("Enter video ����: ");
	scanf("%s", title);
	fflush(stdin);
	//���ڿ��� &���� �ʿ����, ���ڿ� ���� �ּҸ� �Ѱ��ִ� ���̱� ������ �ٸ� �����ʹ� �޸� &�Ⱥٿ��൵ ��.
	printf("Enter video ����: ");
	scanf("%d", &qty);
	fflush(stdin);

	int i;
	for (i = 0; i < *videoCountPtr; i++) {
		int ret = strcmp(title, videoList[i].title);
		if (!ret) {
			videoList[i].qty += 1;
			break;
		}
	}
	if (i == *videoCountPtr) {
		strcpy(videoList[*videoCountPtr].title, title);
		videoList[*videoCountPtr].qty = qty;
		*videoCountPtr += 1;
	}
}

VideoInfo* searchVideoByTitle(VideoInfo videoList[], int videoCount) {
	char title[MAX_CHAR];
	printf("Enter video ����: ");
	scanf("%s", title);
	for (int i = 0; i < videoCount; i++) {
		int ret = strcmp(title, videoList[i].title);
		if (!ret) {
			return &videoList[i];
		}
	}
	return NULL;
}


void rentVideo(RentInfo rentList[],VideoInfo videoList[],int* rentCount,int videoCount) {
	char title[MAX_CHAR];
	int custom_num;
	
	fflush(stdin);
	printf("Enter video ����: ");
	scanf("%s", title);
	
	int ret, i;
	for (i = 0; i < videoCount; i++) {
		ret = strcmp(title, videoList[i].title);
		if (!ret) {
			videoList[i].qty--;
			break;
		}
	}

	if (ret) {
		printf("�׷� ������ �����ϴ�\n");
	}

	else {
		fflush(stdin);
		printf("Enter �� id:(����3�ڸ�) ");
		scanf("%d", &custom_num);
		rentList[*rentCount].custId = custom_num;
		strcpy(rentList[*rentCount].title, title);
		(*rentCount)++;
	}

}


void printAllRent(RentInfo rentList[], int* rentCount) {
	printf("��id	Video����\n");
	printf("-----------------------\n");
	for (int i = 0; i < *rentCount; i++) {
		printf("%d	%-10s\n", rentList[i].custId, rentList[i].title);
	}
}

void returnVideo(RentInfo rentList[],VideoInfo videoList[],int* rentCount, int videoCount) {
	char title[MAX_CHAR];
	int custom_num;

	fflush(stdin);
	printf("Enter �� id:(����3�ڸ�) ");
	scanf("%d", &custom_num);

	fflush(stdin);
	printf("Enter video ����: ");
	scanf("%s", title);

	int i;
	for (i = 0; i < *rentCount; i++) {
		int ret = strcmp(title, rentList[i].title);
		if (!ret && (rentList[i].custId == custom_num)) {
			for (int j = i; j < *rentCount; j++) {
				strcpy(rentList[j].title, rentList[j + 1].title);
				rentList[j].custId = rentList[j + 1].custId;
			}
			(*rentCount)--;
			break;
		}
	}
	
	for (int i = 0; i < videoCount; i++) {
		int ret = strcmp(title, videoList[i].title);
		if (!ret) {
			videoList[i].qty++;
			break;
		}
	}
}

int main(void){
		int videoCount = 5;
		VideoInfo videoList[MAX_VIDEO] = { {"Minari", 5}, {"Parasite", 3}, {"Avatar", 2}, {"Soul", 7}, {"HomeAlone", 3} };
		int rentCount = 0; // ���� ���� �Ǽ��� 0��
		RentInfo rentList[MAX_CUST];
		int choice;
		VideoInfo* videoPtr;

		printf("1(All Video ���), 2(����), 3(�˻�), 4(�뿩), 5(All �뿩���� ���), 6(�ݳ�), 7(����): ");
		scanf("%d", &choice);
		printf("\n");
		while (choice != 7) {
			switch (choice) {
			case 1: printAllVideo(videoList, videoCount); break;
			case 2: purchaseVideo(videoList, &videoCount); break;
			case 3:
				if ((videoPtr = searchVideoByTitle(videoList, videoCount)) == NULL)
					printf("�׷� ������ �����ϴ�.\n");
				else if (videoPtr->qty == 0)
					printf("��� �뿩���Դϴ�.\n");
				else
					printf("�뿩 �����մϴ�.\n");
				break;
			case 4: rentVideo(rentList, videoList, &rentCount, videoCount); break;
			case 5: printAllRent(rentList, &rentCount); break;
			case 6: returnVideo(rentList,videoList,&rentCount,videoCount); break;
			}
			printf("-----------------------\n\n");
			printf("1(All Video ���), 2(����), 3(�˻�), 4(�뿩), 5(All �뿩���� ���), 6(�ݳ�), 7(����): ");
			scanf("%d", &choice);
			printf("\n");
		}
}