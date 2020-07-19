#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *task0(void *arg)
{
    while(1)
    {
        sleep(1);
        printf("task0.\n");
    }
}

void *task1(void *arg)
{
    while(1)
    {
        sleep(1);
        printf("task1.\n");
    }
}

int main(void)
{
    pthread_attr_t attr;		
    struct sched_param parm;
    pthread_t tid0, tid1;
    void* retval;

    pthread_attr_init(&attr);

    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED); //不继承创建者的调度策略，而是设置以下的调度
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO); //为线程属性设置调度策略

    parm.sched_priority = 1;					// 设置线程优先级
    pthread_attr_setschedparam(&attr,&parm);	// 设置线程优先级

    int p0 = pthread_create(&tid0, &attr, task0, NULL);  // 为线程task0设置优先级
    int p1 = pthread_create(&tid1, NULL , task1, NULL);  // 让线程task1使用默认优先级

    printf("task0. %d\n",p0);
    printf("task1. %d\n",p1);

    while(1);

    // 等待线程的结束（实际上由于线程一直在循环中，所以main函数不会结束）
    pthread_join(tid0, &retval); // 等待线程的结束，并取返回值
    pthread_attr_destroy(&attr);
    pthread_join(tid1, &retval); // 等待线程的结束，并取返回值

    return -1;
}