#include <iostream>
#include <memory>

template<typename T>
struct link
{
	T data;
	std::shared_ptr<link> next;

	link(T value) : data(value) {}
	void add_to_end(T value)
	{
		if (next)
			next->add_to_end(value);
		else
			next.reset(new link(value));
	}

};

template<typename T>
class linked_list
{
public:
	linked_list() : head(nullptr) {};
	~linked_list() {};

	void push(T elem);
	void show(void);
	void reverse(void);
private:
	std::shared_ptr<link<T>> head;
};

template<typename T>
void linked_list<T>::push(T elem)
{
	if (head == nullptr)
		head.reset(new link<T>(elem));
	else
		head->add_to_end(elem);
}

template<typename T>
void linked_list<T>::reverse(void)
{
	std::shared_ptr<link<T>> prev;
	std::shared_ptr<link<T>> next;

	if (head == nullptr) return;

	while (head->next)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	head->next = prev;
}

template<typename T>
void linked_list<T>::show(void)
{
	std::shared_ptr<link<T>> current(head);
	while (current)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}


int main(int argc, char *argv[])
{
	linked_list<int> list;

	list.push(1);
	list.push(2);
	list.push(3);

	list.show();
	list.reverse();
	list.show();

	return 0;
}