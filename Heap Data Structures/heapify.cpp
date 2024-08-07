#include<iostream>
using namespace std;

class MinHeap{
    public:
    int *arr;
    int size;
    int capacity;

    MinHeap(int a){
        arr = new int[a];
        capacity = a;
        size = 0;
    }

    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int x){
        if(size==capacity){
            cout<<"overflow"<<endl;
            return;
        }
        size++;
        arr[size-1]=x;
        int i = size-1;
        while(i!=0 and arr[parent(i)]>arr[i]){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i) {
        int smallest = i;
        int lt = left(i), rt = right(i);
        if (lt < size && arr[lt] < arr[smallest]) { 
            smallest = lt;
        }
        if (rt < size && arr[rt] < arr[smallest]) {
            smallest = rt;
        }
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    ~MinHeap() {
        delete[] arr;
    }
};

int main(){
    MinHeap h(2);
    h.insert(20);
    h.insert(10);
    h.arr[0]=40;
    cout<<h.arr[0]<<endl;
    h.heapify(0);
    cout<<h.arr[0]<<endl;
    return 0;
}