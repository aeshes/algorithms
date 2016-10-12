#include <iostream>
#include <memory>

template<typename T>
struct link
{
	using pointer = std::shared_ptr<link>;

	T data;
	pointer next = {};

	link(T value) : data{ std::move(value) } {}
};

template<typename T>
class linked_list
{
	using link_pointer = typename link<T>::pointer;

public:
	linked_list() : head(nullptr) {};
	~linked_list() {};

	void push(T elem);
	void show() const;
	void reverse();
private:
	link_pointer head = {};
	link<T> *tail = nullptr;
};

template<typename T>
void linked_list<T>::push(T elem)
{
	auto new_link = new link<T>(std::move(elem));

	if (tail)
		tail->next.reset(new_link);
	else
		head.reset(new_link);
	tail = new_link;
}

template<typename T>
void linked_list<T>::reverse(void)
{
	if (!head) return;

	link_pointer prev;
	link_pointer next;

	while (head->next)
	{
		next = std::move(head->next);
		head->next = std::move(prev);
		prev = std::move(head);
		head = std::move(next);
	}
	head->next = std::move(prev);
}

template<typename T>
void linked_list<T>::show(void) const
{
	auto current = head.get();
	while (current)
	{
		std::cout << current->data << std::endl;
		current = current->next.get();
	}
}


int main()
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