#include <iostream>
using  namespace std;

//对数器
int* generateRandomArray(int arr[], int size, int maxValue){
    for(int i = 0; i < size; i++){
        arr[i] = rand()%maxValue + 1;
    }
    return arr;
}

void print(int arr[], int count){
    for(int i = 0; i < count ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    srand(time(nullptr));
    int max_len = 10;
    int max_value = 100;
    int test_time = 10;
    for(int i = 0; i < test_time; i++){
        int size = rand()%max_len + 2;
        int* arr = new int[size];
        generateRandomArray(arr, size, max_value);
        print(arr,size);
        delete[] arr;
        cout << "==========================" << endl;
    }
    return 0;
}