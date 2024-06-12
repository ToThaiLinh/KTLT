/* To Thai Linh 20215414
Ma lop thuc hanh: 732826 */

#include <bits/stdc++.h>
using namespace std;

struct bigNum {
    char sign;
    char num[101];
};
/* Khai bao cau truc bigNum voi sign la dau
va mang num chua ky tu so tuong ung*/

void input(bigNum &num1, bigNum &num2){
    string tmp;
    cin >> tmp;
    //Nhap gia tri cho so dau tien
    num1.sign = tmp[0];
    int lens1 = tmp.length() - 1;
    for (int i = 0; i < lens1; i++){
        num1.num[100-lens1+i+1] = tmp[i+1];
    }
    for (int i = 0; i < 100-lens1+1; i++){
        num1.num[i] = '0';
    }
    //Nhap gia tri cho so thu 2
    cin >> tmp;
    num2.sign = tmp[0];
    int lens2 = tmp.length() - 1;
    for (int i = 0; i < lens2; i++){
        num2.num[100-lens2+i+1] = tmp[i+1];
    }
    for (int i = 0; i < 100-lens2+1; i++){
        num2.num[i] = '0';
    }
}

void add(char res[], char *num1, char *num2){
    int c = 0;
    //Khoi tao bien c = 0 de luu so du
    for(int i=100; i>=0; i--){
        int tmp = (int)num1[i] - 48 + (int)num2[i] - 48 + c;
        c = tmp / 10;
        res[i] = tmp % 10 + 48;
    }
    //Tinh tong 2 mang
}

void sub(char res[], char *num1, char* num2){
    int c = 0;
    //Khoi tao bien c = 0 kieu int de luu gia tri du
    for (int i = 100; i >= 0; i--){
        int tmp1 = (int)num1[i] - 48;
        int tmp2 = (int)num2[i] - 48;
    /*Tinh gia tri tung chu so cua 2 mang*/
        if (tmp1 >= tmp2 + c){
            res[i] = tmp1 - tmp2 - c + 48;
            c = 0;
        } else {
            tmp1 = tmp1 + 10;
            res[i] = tmp1 - tmp2 - c + 48;
            c = 1;
        }
    }
}

void multi(char res[], char *num1, char *num2){
	//Dinh nghia ham tinh tich 2 mang so
    for(int i = 0; i < 101; i++){
        res[i] = '0';
    }
    //Khoi tao mang res bang 0
    for (int i = 100; i >= 0; i--){
        char tmp[101];
        int k;
        for (k = 0; k < i; k++){
            tmp[100-k] = '0';
        }

        int c = 0, sum = 0;
        for (int j = 100; j >= 0; j--){
            sum = ((int)num1[i] - 48) * ((int)num2[j] - 48) + c;
            tmp[k] = (sum % 10) + 48;
            c = sum / 10;
            k--; 
            if(k < 0) break;
        }

        add(res,tmp,res);
    }
    //Tinh tich cua 2 so 
}

bool check(char *num1, char *num2){
	//ham so sanh 2 so 
    int foo1, foo2;
    for (foo1 = 0; foo1 < 101; foo1++){
        if (num1[foo1] != '0') break;
    }
    //Duyet den phan tu khac 0 dau tien cua num1

    for (foo2 = 0; foo2 < 101; foo2++){
        if (num2[foo2] != '0') break;
    }
    //Duyet den phan tu khac 0 dau tien cua mang num2

    if (foo1 > foo2) return false;
    else if (foo1 < foo2) return true;
    else { 
        int foo = foo1;
        while (foo < 101){
            if (num1[foo] < num2[foo]) return false;
            else if (num1[foo] > num2[foo]) return true;
            else foo++;
        }
    }
    //So sanh 2 so voi nhau

    return true;
}

bigNum operator + (bigNum num1, bigNum num2){
	//Da nang hoa toan tu +
    bigNum res;

    if (num1.sign == '1' && num2.sign == '1'){
        res.sign = '1';
        add(res.num, num1.num, num2.num);
        return res;
    } else if (num1.sign == '1' && num2.sign == '0'){
        if (check(num1.num, num2.num)){
            res.sign = '1';
            sub(res.num, num1.num, num2.num);
            return res;
        } else {
            res.sign = '0';
            sub(res.num, num2.num, num1.num);
            return res;
        }
    } else if (num1.sign == '0' && num2.sign == '1'){
        if (check(num1.num, num2.num)){
            res.sign = '0';
            sub(res.num, num1.num, num2.num);
            return res;
        } else {
            res.sign = '1';
            sub(res.num, num2.num, num1.num);
            return res;
        }
    } else {
        res.sign = '0';
        add(res.num, num1.num, num2.num);
        return res;
    }
}

bigNum operator - (bigNum num1, bigNum num2){
	//Ham da nang hoa toan tu - 
    bigNum res;

    if (num1.sign == '1' && num2.sign == '0'){
        num2.sign = '1';
        res = num1 + num2;
        return res;
    } else if (num1.sign == '1' && num2.sign == '1'){
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } else if (num1.sign == '0' && num2.sign == '1'){
        num2.sign = '0';
        res = num1 + num2;
        return res;
    } else {
        num2.sign = '1';
        res = num1 + num2;
        return res;
    }
}

bigNum operator * (bigNum num1, bigNum num2){
	//ham da nang hoa toan tu nhan 
    bigNum res;

    if (num1.sign == '1' && num2.sign == '1'){
        res.sign = '1';
        multi(res.num, num1.num, num2.num);
        return res;
    } else if (num1.sign == '1' && num2.sign == '0'){
        res.sign = '0';
        multi(res.num, num1.num, num2.num);
        return res;
    } else if (num1.sign == '0' && num2.sign == '1'){
        res.sign = '0';
        multi(res.num, num1.num, num2.num);
        return res;
    } else {
        res.sign = '1';
        multi(res.num, num1.num, num2.num);
        return res;
    }
}

void printBigNumber(bigNum number){
	//Ham in ket qua
    cout << number.sign;
    int start;
    for (start = 0; start < 101; start++){
        if (number.num[start] != '0') break;
    }
    for (int i = start; i < 101; i++){
        cout << number.num[i];
    }
}

int main(){
	//printf("To Thai Linh 20215414 K66-DHBKHN\n");
    bigNum num1, num2;
    input(num1,num2);
    //Khoi tao 2 so bigNum va nhap gia tri 
    
    bigNum so3, so4;
    //Khai bao 2 so so3 va so4 de lam so tu do
    so3.sign = '1', so4.sign = '1';
    for (int i = 0; i < 100; i++){
        so3.num[i] = '0';
        so4.num[i] = '0';
    }
    so3.num[100] = 3 + 48;
    so4.num[100] = 4 + 48;
    //Nhap gia tri cho so3 va so4
    bigNum res = num1*num2 - so3 * num1 + so4 * num2;
    //Tinh gia tri cua ab - 3a + 4b
    //printf("\nKet qua la:\n");
    printBigNumber(res);
}

//To Thai Linh 20215414 
