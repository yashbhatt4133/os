#include<stdlib.h>
int main(){
    system("awk 'NR==1, NR==2 {print}' /proc/meminfo");
    system("cat /proc/meminfo |awk '{if (NR==1) a = $2;if(NR==2) b =$2}END{print a-b}'");
    return 0;
}
