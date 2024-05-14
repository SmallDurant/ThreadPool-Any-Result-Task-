#include "result.h"

/////////////////   Result������ʵ��
Result::Result(std::shared_ptr<Task> task, bool isValid)
	: isValid_(isValid)
	, task_(task)
{
	task_->setResult(this);
}

Any Result::get() // �û����õ�
{
	if (!isValid_)
	{
		return "";
	}
	sem_.wait(); // task�������û��ִ���꣬����������û����߳�
	return std::move(any_);
}

void Result::setVal(Any any)  // ˭���õ��أ�����
{
	// �洢task�ķ���ֵ
	this->any_ = std::move(any);
	sem_.post(); // �Ѿ���ȡ������ķ���ֵ�������ź�����Դ
}