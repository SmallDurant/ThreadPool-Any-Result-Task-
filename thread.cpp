#include "thread.h"
#include <thread>
////////////////  线程方法实现
int Thread::generateId_ = 0;

// 线程构造
Thread::Thread(ThreadFunc func)
	: func_(func)
	, threadId_(generateId_++)
{}

// 线程析构
Thread::~Thread() {}

// 启动线程
void Thread::start()
{
	// 创建一个线程来执行一个线程函数 pthread_create
	std::thread t(func_, threadId_);  // C++11来说 线程对象t  和线程函数func_
	t.detach(); // 设置分离线程   pthread_detach  pthread_t设置成分离线程
}

int Thread::getId()const
{
	return threadId_;
}