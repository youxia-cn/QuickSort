#include <iostream>
#include <iomanip>
#include <sys/time.h>

using namespace std;

void print_time_interval(struct timespec start, struct timespec end){
    long time_interval = (end.tv_sec - start.tv_sec)*1000000000 + end.tv_nsec - start.tv_nsec;
    cout << setw(3) << setfill('0') << time_interval/1000000000 << ",";
    cout << setw(3) << setfill('0') << (time_interval/1000000)%1000 << ",";
    cout << setw(3) << setfill('0') << (time_interval/1000)%1000 <<",";
    cout << setw(3) << setfill('0') << time_interval%1000 << " ns" << endl;
}

int main(){
    struct timespec start;
    struct timespec end;

    clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_REALTIME, &end);

    print_time_interval(start, end);

    return 0;
}
