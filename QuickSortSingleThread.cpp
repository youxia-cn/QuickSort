#include <iostream>
#include <iomanip>
#include <sys/time.h>

using namespace std;

const int ARR_LEN = 1000000;

template<typename T>
void init_arr(T* a, int len){
    for(int i=0; i<len; i++){
        a[i] = (T)rand();
    }
}

template <typename T>
void print_arr(T* a, int len){
    if(len<10){
        for(int i=0; i<len; i++){
            cout << a[i] << "    ";
        }
        cout << endl;
    }else{
        for(int i=0; i<5; i++){
            cout << a[i] << "    ";
        }
        cout << "...   ";
        for(int i=len-5; i<len; i++){
            cout << a[i] << "    ";
        }
        cout << endl;
    }
}

template <typename T>
void bubble_sort(T* a, int len){
    if(len < 2){
        return;
    }
    for(int k=len-1; k>0; k--){
        for(int i=0; i<k; i++){
            if(a[i] > a[i+1]){
                T temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}


void print_timer(struct timespec start, struct timespec end){
    long timer = (end.tv_sec - start.tv_sec)*1000000000 + end.tv_nsec - start.tv_nsec;
    cout << setw(3) << setfill('0') << timer/1000000000 << ",";
    cout << setw(3) << setfill('0') << (timer/1000000)%1000 << ",";
    cout << setw(3) << setfill('0') << (timer/1000)%1000 <<",";
    cout << setw(3) << setfill('0') << timer%1000 << " ns" << endl;
}

template <typename T>
void quick_sort(T*a, int len){
    if(len < 2) return;
    if(len == 2){
        if(a[0] > a[1]){
            T temp = a[0];
            a[0] = a[1];
            a[1] = temp;
        }
    }

    int i=0, left=0, right=len-1;
    while(left < right){
        while(a[right]>a[i] && left < right){
            right --;
        }
        if(left < right){
            T temp = a[right];
            a[right] = a[i];
            a[i] = temp;
            i = right;
            left++;
        }

        while(a[left]<a[i] && left<right){
            left++;
        }
        if(left<right){
            T temp = a[left];
            a[left] = a[i];
            a[i] = temp;
            i = left;
            right--;
        }
    }

    quick_sort(a, i);
    quick_sort(a+i+1, len-i-1);
}

int main(){
    int* a = (int*) malloc(sizeof(int)*ARR_LEN);
    init_arr(a, ARR_LEN);
    print_arr(a, ARR_LEN);

    struct timespec start;
    struct timespec end;
    clock_gettime(CLOCK_REALTIME, &start);

    quick_sort(a, ARR_LEN);

    clock_gettime(CLOCK_REALTIME, &end);

    print_arr(a, ARR_LEN);
    print_timer(start, end);

    return 0;
}
