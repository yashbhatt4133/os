#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum, sum1, sum2;
void *runner(void *param);
int main(int argc, char *argv[])
{
int arr[] = {1, 2, 3, 4, 100, 200, 300, 400};
pthread_t tid1;
pthread_t tid2;
pthread_attr_t attr1;
pthread_attr_t attr2;
if (argc != 2)
{
fprintf(stderr, "usage: a.out<integervalue>\n");
return -1;
}
if (atoi(argv[1]) < 0)
{
fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
return -1;
}
pthread_attr_init(&attr1);
pthread_attr_init(&attr2);
pthread_create(&tid1, &attr1, runner, argv[1]);
pthread_create(&tid2, &attr2, runner, argv[1]);
pthread_join(tid1, NULL);
pthread_join(tid2, NULL);printf("SUM: %d\n", sum);
return 0;
}
void *runner(void *param)
{
int i, upper = atoi(param);
sum = 0;
for (i = 1; i <= upper; i++)
sum += i;
pthread_exit(0);
}