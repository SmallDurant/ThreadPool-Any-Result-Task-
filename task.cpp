#include "task.h"



/////////////////  Task����ʵ��
Task::Task()
	: result_(nullptr)
{}

void Task::exec()
{
	if (result_ != nullptr)
	{
		result_->setVal(run()); // ���﷢����̬����
	}
}

void Task::setResult(Result* res)
{
	result_ = res;
}