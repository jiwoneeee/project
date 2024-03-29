#include <iostream>
#include <cstddef>
#include <algorithm> //swap

//using namespace std;

class Node {
   public:
       int data;
       Node* next;
       Node* prev;
   
       
       Node(int value) //생성자
      {
          data= value;
         next= nullptr;
         prev= nullptr;
      }
};

class linked_list {
   public:
      Node* head;
      
      //생성자  
       linked_list() {
         head=nullptr;
      }
      
      //소멸자
      ~linked_list()  {    
           Node* now = head;
           while (1) {
              if (now==NULL) break; //다 없앴다는 뜻  
              
               Node* next = now->next;
               delete now; //==free
               
               now = next;
           }
           std::cout << "linked list is free!" <<std::endl;
       }
       
      //추가
       void append(int value){
           Node* newNode = new Node(value); //malloc size of 할 필요 없음  
           
           if (head == nullptr) { //첫번째 append 일때  
               head = newNode;
           } 
         else {  
               Node* now = head;
               while (now->next != nullptr) {
                   now = now->next;
               }
               now->next = newNode;
               newNode->prev = now;
           }
       }
       
       //출력  
       void display(){
           Node* now = head;
           while (1) {
              if (now==nullptr) break;
              
               std::cout << " ["<< now->data << "] ";
               now = now->next;
           }
           std::cout << std::endl;
       }
   
      //삭제  
       void remove (int value) {
          if (head==nullptr){
             std::cout<< "list empty" <<std::endl;
             return;
         }
          
           if (head->data == value)
         {
               Node* temp = head;
               head = head->next;
               delete temp;
               return;
           }
         // .. ... ....
           Node* now = head;
           int chk=0; 
           while (1) 
         {
            if(now->next == NULL){
               break;
            }
            if (now->next->data == value) {
               chk=1;
               break;
            }
            //이미 찾았거나 더이상 찾아볼게 없으면  
               now = now->next;
           }
         // 지금 now 에는 마지막 노드 or  value 전의 값이 들어가있음 
         
           if (chk==1) {
               Node* temp = now->next;
               now->next = now->next->next;
               delete temp;
           }
           else {
              std::cout<<value<<" is not in this linked list. "<<std::endl;
         }
           
       }
      
      //구분 
      Node* partition(Node* left, Node* right) {
          int pivot = left->data;
          Node* low= left->next;
          Node* high= right;
      
         while(low-!=high&&low->prev!=high){ //홀짝 
            while(pivot>=low->data && low!=high){
               low=low->next;
            }
            while(pivot<=high->data && low!=high){
               high=high->prev;
            }

            //헷갈리는 부분
            if (low!=high){
               std::swap(low->data, high->data);
            }
         }
         std::swap(left->data, high->data);
          
          return high;
      }
      
      //파티션 함수 쓰기  
      void quicksort_recursive(Node* low, Node* high){
         if (low!=high && low->prev!=high){
            if (high !=nullptr && low!= nullptr){
               Node* pivot = partition (low, high);
               quicksort_recursive(low, pivot->prev);
               quicksort_recursive(pivot->next, high);
            }
         }
      }
};

int main() {
   linked_list testlist;
   int n;
   std::cin >> n;
   
   for (int i=0;i<n;i++){
      int temp=0;
      std::cin>>temp;
      testlist.append(temp);
   }

  Node* tail = testlist.head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
   
   /*
   testlist.display();
   testlist.remove(10); //존재하는 값 
   testlist.remove(9999); //존재하지 않는 값 
   */
   
   testlist.display(); //sort 이전
   
   testlist.quicksort_recursive(testlist.head, tail);
   
   testlist.display(); //sort 이후  

    return 0;
}
