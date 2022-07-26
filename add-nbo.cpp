#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//파일 가져와서 4바이트 hbo로 바꿔주는 함수 
uint32_t trans(char* number_file) {
	FILE* fp = fopen(number_file, "rb"); //바이너리 모드로 읽어옴
	//파일 오류 검출
	if (fp == 0) {
		fprintf(stderr,"cannot find your file");
		exit(EXIT_FAILURE);
	}
uint32_t n;
//fread(저장할 데이터의 주소, 데이터 사이즈, 반복 횟수, 읽을 파일 포인터)
	fread(&n, 1, sizeof(n), fp);
//changing
	n = ntohl(n);
	fclose(fp);
	return n;
}

int main(int argc, char* argv[]) {
	if (argc != 3) { // 인자 개수 확인하기 
		printf("plz input 2 argv files to add (add-ndo a.bin b.bin)\n");
		exit(EXIT_FAILURE);
	}

// 입력한 파일 열어서 nbo -> hbo
	uint32_t n1 = trans(argv[1]);
	uint32_t n2 = trans(argv[2]);

//보기 쉽게 출력하기
	printf("0x%x(%d) + 0x%x(%d) = 0x%x(%d)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);
}

