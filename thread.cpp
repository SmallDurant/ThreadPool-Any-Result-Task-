#include "thread.h"
#include <thread>
////////////////  �̷߳���ʵ��
int Thread::generateId_ = 0;

// �̹߳���
Thread::Thread(ThreadFunc func)
	: func_(func)
	, threadId_(generateId_++)
{}

// �߳�����
Thread::~Thread() {}

// �����߳�
void Thread::start()
{
	// ����һ���߳���ִ��һ���̺߳��� pthread_create
	std::thread t(func_, threadId_);  // C++11��˵ �̶߳���t  ���̺߳���func_
	t.detach(); // ���÷����߳�   pthread_detach  pthread_t���óɷ����߳�
}

int Thread::getId()const
{
	return threadId_;
}