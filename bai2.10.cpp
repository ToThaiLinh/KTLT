/*To Thai Linh 20215414
Ma lop thuc hanh: 732826*/

#include <bits/stdc++.h>

using namespace std;

const int N = 128;
//Khai bao hang so N bang 128 

struct Matrix {
	unsigned int mat[N][N];
	Matrix () {
		memset(mat, 0, sizeof mat);
	}
};
//Dinh nghia mot cau truc voi mat[N][N] va khoi tao gia tri bang 0

bool operator == (const Matrix &a, const Matrix &b) {
	//Ham da nang hoa toan tu logic == voi 2 ma tran a va b
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(a.mat[i][j] != b.mat[i][j]) return false;
			//Neu phan tu nao cua a khac b thi tra ve false
			//Con bang nhau het tra ve true
		}
	}
	return true;
}
Matrix multiply_naive(const Matrix &a, const Matrix &b) {
	//ham tinh tich 2 ma tran mot cach cham
	Matrix c;
	//Khai bao mot ma tran c de luu ket qua
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
		}
	}
	//Dung 3 vong lap de tinh gia tri tung phan tu
	return c;
}

Matrix multiply_fast(const Matrix &a, const Matrix &b) {
	//ham tinh tich 2 ma tran mot cach nhanh hon 
	Matrix c;
	//Khai bao mot ma tran c de luu ket qua
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			//Tinh tung phan tu cua c bang cach dung bien sum 
			int sum = 0;
			for(int k = 0; k < N; k++) {
				sum += a.mat[i][k] * b.mat[k][j];
			}
			c.mat[i][j] = sum;
		}
	}
	return c;
}

Matrix gen_radom_matrix() {
	//ham lay gia tri ngau nhien cho ma tran 
	Matrix a;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			a.mat[i][j] = rand();
		}
	}
	return a;
}

Matrix base;
//Khai bao mot ma tran base

double benchmark(Matrix (*multiply)(const Matrix &, const Matrix &), Matrix &result) {
	const int NUM_TEST = 10;//hang so luot test 
	const int NUM_ITER = 64;//hang so luot tinh ham
	
	Matrix a = base;//Gan ma tran base cho a
	result = a;//tham chieu result toi ma tran a
	
	double taken = 0;
	//Khai bao bien taken de luu tong thoi gian
	for(int t = 0; t < NUM_TEST; ++t) {
		clock_t start = clock();
		//Khoi tao thoi gian bat dau
		for(int i = 0; i < NUM_ITER; ++i) {
			a = multiply(a, result);
			result = multiply(result, a);
		}
		clock_t finish = clock();
		//tinh thoi gian ket thuc
		taken += double(finish - start); 
		//tinh thoi gian tong 
	}
	taken /= NUM_TEST;//thoi gian trung binh 
	printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
	return taken;
}

int main() {
	base = gen_radom_matrix();
	//Gan gia tri cua ma tran base ngau nhien
	
	Matrix a, b;//Khai bao 2 ma tran a va b 
	printf("Slow version\n");
	double slow = benchmark(multiply_naive, a);
	//Tinh thoi gian khi thuc hien ham multiply_naive
	printf("Fast version\n");
	double fast = benchmark(multiply_fast, b);
	//Tinh thoi gian khi thuc hien ham multiply_fast
	
	if(a == b) {
		printf("Correct answer! Your code is %.2f%% faster\n",slow / fast * 100.0 );
		//In ra phan tram toc do nhanh hon
	}	
	else {
		printf("Wrong answer!\n");
	}
	return 0;	
}
//To Thai Linh 20215414
