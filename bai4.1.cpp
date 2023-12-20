/* To Thai Linh 20215414
Ma lop thuc hanh 732826*/
#include <iostream> 
using namespace std;

//Cau truc cua mot node trong danh sach lien ket don
struct Node { 
    int data; 
    Node* next;
    //Ham khoi tao gia tri cua mot node moi 
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    //Khoi tao mot Node p co gia tri la data
    Node *p =new Node(data);
    //Con tro next cua p tro den vung nho head
    p -> next = head;
    return p;//Tra ve node dau cua danh sach moi
}

// print the list content on a line
void print(Node* head) {
    //Dung Node p de duyet toan bo danh sach
    //Gan dia chi cua head cho con tro p
    Node *p = head;
    while(p != NULL) {
        //In gia tri cua tung Node
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");//Xuong dong
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    //Khoi tao 2 con tro Node prev va next la NULL
    Node *prev = NULL;
    Node *next = NULL;
    while(head != NULL) {
        //Gan dia chi cua node sau head cho next
        next = head -> next;
        //Gan dia chi next cua node head la prev
        head -> next = prev;
        //Gan dia chi node head cho prev
        prev = head;
        //Gan dia chi node next cho head
        head = next;
    }
    //Tra ve dia chi dau danh sach moi
    return prev;
}
  
int main() {
    //Khai bao 2 bien n va u kieu int
    int n, u;
    cin >> n;//Nhap gia tri cua n
    //Khai bao mot con tro kieu Node co gia tri NULL
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        //Nhap gia tri cho tung Node
        head = prepend(head, u);
        //Chen node vua tao vao dau danh sach
    } 
    
    cout << "Original list: ";
    print(head);//In ra danh sach vua tao

    head = reverse(head);//Goi ham dao nguoc danh sach
    
    cout << "Reversed list: ";
    print(head);//In ra danh sach dao nguoc

    return 0; 
}
//To Thai Linh 20215414
