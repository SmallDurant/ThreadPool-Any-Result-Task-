#pragma once
#include <functional>
// 线程类型
class Thread
{
public:
	// 线程函数对象类型
	using ThreadFunc = std::function<void(int)>;

	// 线程构造
	Thread(ThreadFunc func);
	// 线程析构
	~Thread();
	// 启动线程
	void start();

	// 获取线程id
	int getId()const;
private:
	ThreadFunc func_;
	static int generateId_;
	int threadId_;  // 保存线程id
};
