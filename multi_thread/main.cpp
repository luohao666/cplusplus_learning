#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include <fstream>
#include <queue>
#include <condition_variable>

using namespace std;

mutex mu;
deque<int> q;
condition_variable cond;

void func_1()
{
    cout << "func_1 started!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "func_1 finished!" << endl;
}

void func_2()
{
    cout << "func_2 started!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "func_2 finished!" << endl;
}

void shared_print(string msg,int id)
{
    mu.lock();//线程在执行cout时不会被其他线程打扰
    cout<<msg<<id<<endl;
    mu.unlock();
}

void func_3()
{
    for(int i=0;i<100;i++)
        shared_print("from t1:",i);
}

void func_4()
{
    for(int i=0;i<100;i++)
        cout<<"from t1:"<<i<<endl;
}

class Factor
{
    public:
        void operator() ()
        {
            for(int i=0;i<100;i++)
                cout<<"from t1:"<<i<<endl;
        }

        void operator() (string &msg)
        {
            cout<<"from t1:"<<msg<<endl;
            msg="changable!";
        }

        void operator() (string msg)
        {
            cout<<"from t1:"<<msg<<endl;
            msg="changable!";
        }
};

class LogFile
{
    //对mu,f进行绑定？
    public:
        LogFile()
        {
            f.open("log.txt");
        }
        void shared_print(string id,int value)
        {
            lock_guard<mutex> locker(mu);//lock()发生异常时，lock会被析构掉
            //mu.lock();//线程在执行cout时不会被其他线程打扰
            f<<"from"<<id<<":"<<value<<endl;
            //cout<<"from "<<id<<":"<<value<<endl;
            //mu.unlock();
        }
    private:
        mutex mu;
        ofstream f;
};

//避免死锁
//保持顺序一致
//or 使用lock
class LogFile2
{
    //对mu,f进行绑定？
    public:
        LogFile2()
        {
            f.open("log.txt");
        }
        ~LogFile2()
        {
            f.close();
        }
        void shared_print(string id,int value)
        {
            lock(mu,mu2);
            //lock_guard<mutex> locker1(mu);//lock()发生异常时，lock会被析构掉
            //lock_guard<mutex> locker2(mu2);//lock()发生异常时，lock会被析构掉

            lock_guard<mutex> locker1(mu,adopt_lock);//lock()发生异常时，lock会被析构掉
            lock_guard<mutex> locker2(mu2,adopt_lock);//lock()发生异常时，lock会被析构掉

            //mu.lock();//线程在执行cout时不会被其他线程打扰
            f<<"from"<<id<<":"<<value<<endl;
            //cout<<"from "<<id<<":"<<value<<endl;
            //mu.unlock();
        }
        void shared_print2(string id,int value)
        {
            lock(mu,mu2);
            lock_guard<mutex> locker2(mu2,adopt_lock);//lock()发生异常时，lock会被析构掉 
            lock_guard<mutex> locker1(mu,adopt_lock);//lock()发生异常时，lock会被析构掉
            //mu.lock();//线程在执行cout时不会被其他线程打扰
            f<<"from "<<id<<":"<<value<<endl;
            //cout<<"from "<<id<<":"<<value<<endl;
            //mu.unlock();
        }
    private:
        mutex mu;
        mutex mu2;
        ofstream f;
};

//使用unique_lock
class LogFile3
{
    public:
        LogFile3()
        {
            //f.open("log.txt");
        }
        ~LogFile3()
        {
            f.close();
        }
        void shared_print(string id,int value)
        {
            /*
            //way1
            {
                unique_lock<mutex> locker(mu_open,defer_lock);//更多的弹性
                if(!f.is_open())
                {
                    f.open("log.txt");
                }
            }
            */

            //way2
            call_once(m_flag,[&](){f.open("log.txt");});
            unique_lock<mutex> locker(mu,defer_lock);//更多的弹性
            //...

            locker.lock();
            f<<"from "<<id<<":"<<value<<endl;
            locker.unlock();

            //...

            //unique_lock<mutex> locker2=move(locker);//允许移动
        }
    private:
        mutex mu;
        //mutex mu_open;
        once_flag m_flag;
        ofstream f;
};

void func_5(LogFile &log)
{
    for(int i=0;i<100;i++)
        log.shared_print("t1:",i);
}

void func_6(LogFile2 &log)
{
    for(int i=0;i<100;i++)
        log.shared_print("t1:",i);
}

void func_7(LogFile3 &log)
{
    for(int i=0;i<100;i++)
        log.shared_print("t1:",i);
}

// this thread feed data
void function_1()
{
    int count=10;
    while(count>0)
    {
        unique_lock<mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        //cond.notify_one();//激活一个等待这个条件的线程
        cond.notify_all();//激活一个等待这个条件的线程
        this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}

// this thread use data
void function_2()
{
    int data=0;
    while(data!=1)
    {
        unique_lock<mutex> locker(mu);
        /*
        if(!q.empty())
        {
            data=q.back();
            q.pop_back();
            locker.unlock();
            cout << "t2 got a value from t1: " << data << endl;
        }
        else
        {
            locker.unlock();
            this_thread::sleep_for(chrono::seconds(10));
        }
        */
        cond.wait(locker,[](){return !q.empty();});
        data=q.back();
        q.pop_back();
        locker.unlock();
        cout << "t2 got a value from t1: " << data << endl;
    }
}

//条件变量
int main(int argc,char *argv[])
{
    //cpu线程
    cout<<thread::hardware_concurrency()<<endl;

    thread t1(function_1);
    thread t2(function_2);

    t1.join();
    t2.join();

    return 0;
}


/*
int main(int argc,char *argv[])
{
    cout << "starting func_1!" << endl;
    thread t1(func_1);

    cout << "starting func_2!" << endl;
    thread t2(func_2);

    cout<< "waiting" << endl;
    t1.join();//让主线程等待子线程执行完
    t2.join();//让主线程等待子线程执行完

    //t1.detach();
    if(t1.joinable())
    {
        t1.join();
    }

    cout << "done!" << endl;
    return 0;
}
*/


/*
int main(int argc,char *argv[])
{
    // not safe
    /*
    thread t1(func_1);
    for(int i=0;i<100;i++)
    {
        cout<<"main:"<<i<<endl;
    }
    t1.join();
    */

    // safe
    /*
    thread t1(func_1);
    try
    {
        for(int i=0;i<100;i++)
        {
            cout<<"main:"<<i<<endl;
        }
    }
    catch(...)
    {
        t1.join();
        throw;
    }
    t1.join();
    */

    // use class thread
    /*
    Factor factor1;
    thread t1(factor1);
    try
    {
        for(int i=0;i<100;i++)
        {
            cout<<"main:"<<i<<endl;
        }
    }
    catch(...)
    {
        t1.join();
        throw;
    }
    t1.join();
    */

    // pass by value
    /*
    string s="join";
    thread t1((Factor()),s);
    t1.join();
    cout<<"mian:"<<s<<endl;
    */

    // pass by ref
    /*
    string s="join";
    thread t1((Factor()),ref(s));
    t1.join();
    cout<<"mian:"<<s<<endl;
    */

    // 对象移动
    /*
    string s= "join";
    cout<<this_thread::get_id()<<endl;

    thread t1((Factor()),move(s));//t1线程开始运行
    thread t2=move(t1);//线程对象只能移动，不能赋值，此时t1为空
    cout<<t2.get_id()<<endl;

    t2.join();
    */

    //cpu线程
    //cout<<thread::hardware_concurrency()<<endl;

    //数据竞争与互斥对象
    
    /*
    thread t1(func_4);
    for(int i=0;i<100;i++)
    {
        cout<<"main:"<<i<<endl;
    }
    t1.join();
    */

    //不是一个好方法
    /*
        thread t1(func_3);
        for(int i=0;i<100;i++)
        {
            shared_print("from main:",i);
        }
        t1.join();
    */

    //用一个类
    /*
    LogFile log;
    thread t1(func_5,ref(log));
    for(int i=0;i<100;i++)
    {
        log.shared_print("main:",i);
    }
    t1.join();
    */

    //死锁
    /*
    LogFile2 log;
    thread t1(func_6,ref(log));
    for(int i=0;i<100;i++)
    {
        log.shared_print2("main:",i);
    }
    t1.join();
    */

    //unique_lock
    /*
    LogFile3 log;
    thread t1(func_7,ref(log));
    for(int i=0;i<100;i++)
    {
        log.shared_print("main:",i);
    }
    t1.join();

    return 0;

}
*/