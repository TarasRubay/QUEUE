#include "queue.h"
int main() {
	queue<int> que;
	for (int i = 0; i < 5; i++)
	{
		int q = rand() % 200;
		que.en_queue(q);
	cout << "en_queue() " << setw(7) << q <<" ind - "<< i+1 <<endl;
	}
	
	cout << "\nqueue size -  " << que.size_list()<<endl;
	cout << "\ntop() " <<que.top()<<endl;
	cout << endl;
	
	int size = que.size_list();
	for (int i = 0; i < size; i++)
	{
		cout << "de_queue() " << setw(7) << que.de_queue() << "  ind - " << i + 1 <<endl;
	}

	cout << "\nqueue size -  " << que.size_list()<<endl;
	cout << "\nqueue empty -  " << boolalpha << que.empty()<<endl;
	cout << endl;
	
	for (int i = 0; i < 5; i++)
	{
		int q = rand() % 200;
		que.en_queue(q);
		cout << "en_queue() " << setw(7) << q  << " ind - " << i+1 << endl;
	}
	cout << "\n operator=  que = 5555;" << endl;
	que = 5555;
	
	cout << "\ncopy constructor()  queue<int> r = que; " << endl;
	queue<int> r = que;
	
	cout << "\nqueue size -  " << que.size_list() << endl;
	cout << "\nqueue empty -  " << boolalpha << que.empty() << endl;
	cout << "\ntop() " <<que.top()<<endl;
	cout << "\nqueue clear()" << endl;
	que.clear();
	cout << "\nqueue size -  " << que.size_list() << endl;
	cout << "\nqueue empty -  " << boolalpha << que.empty() << endl;

	
	cout << "\nR_queue size -  " << r.size_list() << endl;
	cout << "\nR_queue empty -  " << boolalpha << r.empty() << endl;

	size = r.size_list();
	for (int i = 0; i < size; i++)
	{
		cout << "r_de_queue() " << setw(7) << r.de_queue()  << "  ind - " << i+1 << endl;
	}

	return 0;
}