#include <iostream>
using namespace std;
void withchange();
void withrefchange();
struct chain
{
	int data;
	chain* next;
};

void toStr(chain* ptr)
{
	chain* curr = ptr;
	while (curr != NULL)
	{
		cout<<curr->data <<endl;
		curr = curr->next;
	}
}
chain** change(chain* input)
{
	
	return &input->next;
}
chain*& refchange(chain* input)
{
	return input->next;
}
void twomain()
{
	withchange();
	cout<< "=============="<<endl;
	withrefchange();

	//���ۣ����þ���һ��ָ�� ���õ�ʱ���Զ� ������
}
void withchange()
{
	chain* node1 = new chain();
	node1->data = 1;
	node1->next = NULL;
	toStr(node1);
	cout<< "֮ǰ---֮��"<<endl;
	chain** ptr = change(node1);
	*ptr = new chain();
	(*ptr)->data = 233;
	(*ptr)->next = NULL;
	toStr(node1);
}
void withrefchange()
{
	chain* node1 = new chain();
	node1->data = 1;
	node1->next = NULL;
	toStr(node1);
	cout << "֮ǰ---֮��" << endl;
	chain*& ptr = refchange(node1);
	ptr = new chain();
	ptr->data = 233;
	ptr->next = NULL;
	toStr(node1);
}
