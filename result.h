#pragma once
#include <memory>
#include <atomic>
#include "any.h"
#include "task.h"
#include "semaphore.h"

class Task;
// ʵ�ֽ����ύ���̳߳ص�task����ִ����ɺ�ķ���ֵ����Result
class Result
{
public:
	Result(std::shared_ptr<Task> task, bool isValid = true);
	~Result() = default;

	// ����һ��setVal��������ȡ����ִ����ķ���ֵ��
	void setVal(Any any);

	// �������get�������û��������������ȡtask�ķ���ֵ
	Any get();
private:
	Any any_; // �洢����ķ���ֵ
	Semaphore sem_; // �߳�ͨ���ź���
	std::shared_ptr<Task> task_; //ָ���Ӧ��ȡ����ֵ��������� 
	std::atomic_bool isValid_; // ����ֵ�Ƿ���Ч
};

