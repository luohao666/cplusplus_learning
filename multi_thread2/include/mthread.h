#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

namespace MThread
{
    //第一个例子
    void* thread(void *arg)
    {
        int res = *(int*)arg;
        cout << "first instacne arg = " << res << endl;
        *(int*)arg = 520;

        //pthread_detach(pthread_self());
        return arg;
    }

    int app01()
    {
        pthread_t p;                                                   //handle
        const pthread_attr_t *attr = NULL;                             //attr
        int arg=10;                                                    //arg
        int create_res = pthread_create(&p,attr,thread,&arg);          //func
        // if success,return 0
        if(create_res)
        {
            cout << "create thread error" <<endl;
            return -1;
        }
        cout << "This is main" <<endl;
        int *thread_res = NULL;
        //pthread_join(p,(void**)&thread_res);                            //回收线程的资源
        //cout << "thread_res = " << *thread_res << endl;
        pthread_detach(p);
        sleep(1);
        return 0;
    }

    //线程的属性
    //一般地，Linux下的线程有：绑定属性、分离属性、调度属性、堆栈大小属性和满占警戒区大小属性

    enum AttrType
    {
        SCOPE=0,
        DETACH,
        POLICY
    };

    int app02()
    {
        pthread_t p;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        int arg=10;
        int create_res = 0;
        int *thread_res = NULL;
        AttrType atype = POLICY;
        switch(atype)
        {
            case SCOPE:
                cout << "SCOPE" <<endl;
                 //设置线程绑定属性,can ignore
                pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);//bind
                //pthread_attr_setscope(&attr,PTHREAD_SCOPE_PROCESS);//not bind

                create_res = pthread_create(&p,&attr,thread,&arg);
                // if success,return 0
                if(create_res)
                {
                    cout << "create thread error" <<endl;
                    return -1;
                }
                cout << "This is main" <<endl;
                pthread_join(p,(void**)&thread_res);                            //回收线程的资源
                cout << "thread_res = " << *thread_res << endl;
                break;
            case DETACH:
                cout << "DETACH" <<endl;
                //设置线程分离属性
                pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
                //pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
                create_res = pthread_create(&p,&attr,thread,&arg);
                // if success,return 0
                if(create_res)
                {
                    cout << "create thread error" <<endl;
                    return -1;
                }
                cout << "This is main" <<endl;
                sleep(1);
                break;
            case POLICY:
                cout << "POLICY" <<endl;
                cout << "NEED SUDO RUN" <<endl;
                //线程的调度属性有三个，分别是：算法、优先级和继承权
                //Linux提供的线程调度算法有三个：轮询、先进先出和其它
                int po = pthread_attr_setschedpolicy(&attr,SCHED_FIFO);//先进先出
                struct sched_param param;
                param.sched_priority = sched_get_priority_max(SCHED_FIFO);
                int pa = pthread_attr_setschedparam(&attr,&param);//优先级
                int h = pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);//放弃继承权

                create_res = pthread_create(&p,&attr,thread,&arg);
                //create_res = pthread_create(&p,NULL,thread,&arg);
                /*
                int gpolicy;
                pthread_attr_getschedpolicy(&attr,&gpolicy);
                if(gpolicy == SCHED_RR)
                    cout << "gpolicy: " << "SCHED_RR" << endl;
                else if(gpolicy == SCHED_FIFO)
                    cout << "gpolicy: " << "SCHED_FIFO" << endl;
                else if(gpolicy == SCHED_OTHER)
                    cout << "gpolicy: " << "SCHED_OTHER" << endl;
                else
                    cout << "error policy" << endl;
                */
                // if success,return 0
                if(create_res)
                {
                    cout << "create thread error" <<endl;
                    cout << "error policy: " << po <<endl;
                    cout << "error param: " << pa <<endl;
                    cout << "error herits: " << h <<endl;
                    cout << "error id: " << create_res <<endl;
                    return -1;
                }
                cout << "This is main" <<endl;
                pthread_join(p,(void**)&thread_res);                            //回收线程的资源
                cout << "thread_res = " << *thread_res << endl;
                //pthread_attr_destroy(&attr);
                break;

        }
        return -1;
    } 

    //线程的互斥锁
    pthread_mutex_t g_mutex;
    int g_lockd_var = 0;

    void* thread1(void *arg)
    {
        time_t end = time(NULL)+10;
        while(time(NULL) < end)
        {
            int res = pthread_mutex_trylock(&g_mutex);
            if(res == EBUSY)
            {
                cout << "th1: locked by th2" <<endl; 
            }
            else
            {
                cout << "th1: lock" <<endl;
                ++g_lockd_var;
                pthread_mutex_unlock(&g_mutex); 
            }
            sleep(1);
        }
        return NULL;
    }

    void* thread2(void *arg)
    {
        time_t end = time(NULL)+10;
        while(time(NULL) < end)
        {
            int res = pthread_mutex_lock(&g_mutex);
            cout << "th2: lock" <<endl;
            ++g_lockd_var;
            pthread_mutex_unlock(&g_mutex); 
            sleep(1);

        }
        return NULL;
    }

    int app03()
    {
        pthread_t p1,p2;
        pthread_mutex_init(&g_mutex,NULL);
        pthread_create(&p1,NULL,thread1,NULL);
        pthread_create(&p2,NULL,thread2,NULL);
        pthread_join(p1,NULL);
        pthread_join(p2,NULL);
        pthread_mutex_destroy(&g_mutex);
        cout << g_lockd_var << endl;
        return 1;
    }

    //线程的条件变量

}