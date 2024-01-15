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


void print_time_interval(struct timespec start, struct timespec end){
    long time_interval = (end.tv_sec - start.tv_sec)*1000000000 + end.tv_nsec - start.tv_nsec;
    cout << setw(3) << setfill('0') << time_interval/1000000000 << ",";
    cout << setw(3) << setfill('0') << (time_interval/1000000)%1000 << ",";
    cout << setw(3) << setfill('0') << (time_interval/1000)%1000 <<",";
    cout << setw(3) << setfill('0') << time_interval%1000 << " ns" << endl;
}

int main(){
    int* a = (int*) malloc(sizeof(int)*ARR_LEN);
    init_arr(a, ARR_LEN);
    print_arr(a, ARR_LEN);

    struct timespec start;
    struct timespec end;
    clock_gettime(CLOCK_REALTIME, &start);

    bubble_sort(a, ARR_LEN);

    clock_gettime(CLOCK_REALTIME, &end);

    print_arr(a, ARR_LEN);
    print_time_interval(start, end);

    return 0;
}
