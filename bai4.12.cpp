/* To Thai Linh 20215414
Ma lop thuc hanh 732826 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Ham tinh dien tich hinh chu nhat lon nhat tu cac cot
long long largestRectangleArea(vector<long long>& heights) {
    stack<long long> st; // Stack luu tru chi so cac cot tang dan
    long long maxArea = 0; // Bien luu tru dien tich lon nhat tim duoc
    long long i = 0; // chi so cot hien tai

    while (i < heights.size()) {
    	//Duyet qua tung cot
        if (st.empty() || heights[i] >= heights[st.top()]) {
            //Neu stack rong hoac chieu cao cua cot hien tai lon hon chieu cao tren dinh stack
            // Day chi so cot hien tai vao stack va tang chi so cot
            st.push(i);
            i++;
        } else {
            // Neu chieu cao cua cot hien tai nho hon chieu cao tren dinh stack 
            // Lay chieu cao cua cot tren dinh stack va tinh dien tich hinh chu nhat 
            long long tp = st.top();
            st.pop();
            long long area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    //kiem tra cac cot con lai trong stack  
    while (!st.empty()) {
        long long tp = st.top();
        st.pop();
        long long area = heights[tp] * (st.empty() ? i : i - st.top() - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    long long n;
    //Khai bao bien n kieu long long luu tru cac cot
    cin >> n;//Nhap gia tri cho n
    vector<long long> heights(n);
    //Khai bao vector heights luu chieu cao cua tung cot
    for (long long i = 0; i < n; i++) {
        cin >> heights[i];
        //Nhap chieu cao cua tung cot
    }
    //Khai bao bien result luu dien tich lon nhat tim duoc
    long long result = largestRectangleArea(heights);
    cout << result << endl;//In ket qua
    return 0;
}//To Thai Linh 20215414



