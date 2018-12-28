#include <stdio.h>
#include <ctype.h> // isdigit()に必要

// ファイルを開く操作
int fileopen(FILE** fpp, char *filename);

// fgetc()で1文字ずつ読み込む出力とsumの計算をする
// 読み込んだものの出力とsumの計算をする
int get_sum(FILE** fpp);

int main(int argc, char* argv[]){
	
	// コマンドライン引数のチェック
	if(argc != 2){
		fprintf(stderr, "引数の数が間違っています．\n");
		fprintf(stderr, "./fgetc input.txt\n");
		return 1;
	}
	
	// ファイルを開く処理
	// fileopen()は失敗したら1を返す
	// それを受け取ったらreturn 1;で異常終了
	FILE** fp;
	FILE* tmp;
	fp = &tmp;
	if(fileopen(fp, argv[1]) == 1)
		return 1;
	
	// ファイルを読み込んで出力しながらsumを計算して代入
	int sum = get_sum(fp);
	
	printf("\nsum: %d\n", sum);
	
	// ファイルを閉じる
	fclose(*fp);
	return 0;
}

int fileopen(FILE** fpp, char *filename){
	if(fpp == NULL){
		printf("aaa\n");
		if(*fpp == NULL)
			printf("bbb\n");
		else
			printf("ccc\n");
		return 1;
	}
	// 読み込みモードでファイルを開く
	printf("open %s\n", filename);
	*fpp = fopen(filename, "r"); // 失敗するとNULLを返す
	// ファイルを開くのに失敗したときの処理
	if(fpp == NULL){
		fprintf(stderr, "Error: file not opened.\n");
		return 1;
	}
	else{
		printf("success file open\n");
		return 0;
	}
}

int get_sum(FILE** fpp){
	int tmp; // fgetc()はint型の文字コードを返す
	int num = 0;
	int sum = 0;
	while((tmp = fgetc(*fpp)) != EOF){
		// ここでtmpを煮るなり焼くなりする
		printf("%c", (char)tmp); // そのまま出力
		
		// 数字ならnumに数として格納
		if(isdigit(tmp)){ // tmpが数字なら
			num = num * 10; // 位を1つ大きくする
			num += tmp - '0'; // 一の位に値を入れる
		}
		else{
			// 数字が終わった直後ならnumがsumに加算される
			// その後numを0にしているので直後以外はsumに0が加算される
			sum += num;
			num = 0;
		}
	}
	return sum;
}
