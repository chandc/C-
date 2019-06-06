#include <iostream>

namespace custom {
    template< typename T>
    class list {
        struct node{
        T value;
        node* prev;
        node* next;
        node(T val, node* _prev, node* _next) : value(val), prev(_prev), next(_next) {}
        };
        node *head;
        node *tail;
        public:
            list(): head(NULL), tail(NULL){}
            ~list();
        void push_front(T);
        void push_back(T);
        T pop_back();
        T pop_front();
        bool empty() const { return ( !head || !tail ); }
        void print();
    };
    template< typename T>
    void list<T>::push_front(T value){

        head = new node(value, NULL, head);
        if( head->next ){
            head->next->prev = head;
        }
        if( list<T>::empty()){
            tail = head;
        }
    }

    template <typename T>
    void list<T>::push_back(T val){
        list::tail = new node(val, list::tail, NULL);
        if(list::tail->prev){
            list::tail->prev->next = tail;
        }
        if( list::empty()){
            list::head = list::tail;
        }
    }

    template<typename T>
    list<T>::~list(){
        while(head){
            node* temp(head);
            head=head->next;
            delete temp;
        }
    }
    template<typename T>
    T list<T>::pop_back(){
        if(list::empty()){
            throw("list : list empty");
        }
        node* temp(list::tail);
        T value = (list::tail->value);
        list::tail = list::tail->prev ;
        if(list::tail){
            list::tail->next = NULL;
        } else{
            list::head = NULL ;
        }
        delete temp;
        return value;
    }
    template<typename T>
    T list<T>::pop_front(){
        if(list::empty()){
            throw("list : list empty");
        }
        node* temp(list::head);
        T value = (list::head->value);
        list::head = list::head->next ;
        if(list::head){
            list::head->prev = NULL;
        } else {
            list::tail = NULL;
        }

        delete temp;
        return value;
    }
    template< typename T> 
    void list<T>::print() { 
        node* ptr(list::head);
        while(ptr != NULL) { 
            std::cout<< ptr->value <<" "; 
            ptr = ptr->next; 
        }
        std::cout << std::endl;
    } 
}
int main() {
custom::list< int > list;
list.push_back(9);
    list.print();
   return 0;
}  