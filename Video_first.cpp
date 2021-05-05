#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CUST 20 // max customer
#define MAX_CHAR 50 // 문자열의 max 문자

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // 재고 대장: 현재 보유하고 있는 Video 정보 저장
	char title[MAX_CHAR];
	int qty; // 수량
} VideoInfo;

typedef struct { // 대출 대장: 대출해간 (고객 id와 video id)들이 저장
	int custId; // 정수3자리
	char title[MAX_CHAR]; // Video 제목
} RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount) {
	printf("Video제목	수량\n");
	printf("-----------------------\n");
	for(int i = 0; i<videoCount;i++) {
		printf("%-10s	%d\n", videoList[i].title, videoList[i].qty);
	}
}

void purchaseVideo(VideoInfo videoList[], int* videoCountPtr) {
	char title[MAX_CHAR];
	int qty;
	printf("Enter video 제목: ");
	scanf("%s", title);
	fflush(stdin);
	//문자열은 &붙일 필요없음, 문자열 시작 주소를 넘겨주는 것이기 때문에 다른 변수와는 달리 &안붙여줘도 됨.
	printf("Enter video 수량: ");
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
	printf("Enter video 제목: ");
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
	printf("Enter video 제목: ");
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
		printf("그런 비디오는 없습니다\n");
	}

	else {
		fflush(stdin);
		printf("Enter 고객 id:(숫자3자리) ");
		scanf("%d", &custom_num);
		rentList[*rentCount].custId = custom_num;
		strcpy(rentList[*rentCount].title, title);
		(*rentCount)++;
	}

}


void printAllRent(RentInfo rentList[], int* rentCount) {
	printf("고객id	Video제목\n");
	printf("-----------------------\n");
	for (int i = 0; i < *rentCount; i++) {
		printf("%d	%-10s\n", rentList[i].custId, rentList[i].title);
	}
}

void returnVideo(RentInfo rentList[],VideoInfo videoList[],int* rentCount, int videoCount) {
	char title[MAX_CHAR];
	int custom_num;

	fflush(stdin);
	printf("Enter 고객 id:(숫자3자리) ");
	scanf("%d", &custom_num);

	fflush(stdin);
	printf("Enter video 제목: ");
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
		int rentCount = 0; // 현재 대출 건수는 0임
		RentInfo rentList[MAX_CUST];
		int choice;
		VideoInfo* videoPtr;

		printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(반납), 7(종료): ");
		scanf("%d", &choice);
		printf("\n");
		while (choice != 7) {
			switch (choice) {
			case 1: printAllVideo(videoList, videoCount); break;
			case 2: purchaseVideo(videoList, &videoCount); break;
			case 3:
				if ((videoPtr = searchVideoByTitle(videoList, videoCount)) == NULL)
					printf("그런 비디오는 없습니다.\n");
				else if (videoPtr->qty == 0)
					printf("모두 대여중입니다.\n");
				else
					printf("대여 가능합니다.\n");
				break;
			case 4: rentVideo(rentList, videoList, &rentCount, videoCount); break;
			case 5: printAllRent(rentList, &rentCount); break;
			case 6: returnVideo(rentList,videoList,&rentCount,videoCount); break;
			}
			printf("-----------------------\n\n");
			printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(반납), 7(종료): ");
			scanf("%d", &choice);
			printf("\n");
		}
}