#include <iostream>

using namespace std;

//节点
class Node
{
public:

    int id;
    int score;

    Node *Next;

    Node(int id, int score) : id(id), score(score), Next(NULL) {}

    Node() : Next(NULL), id(0), score(0) {}

    void putOut()
    {
        cout << id << '\t' << score << endl;
    }

};

//链表
class Link
{

public:
    Node *head;

    Link()
    {
        head = new Node();
        head->Next = NULL;
    }

    //析构函数
    ~Link()
    {
        Node *k = head;
        Node *t;
        while (k != NULL)
        {
            t = k->Next;
            delete k; //swap原理
            k = t;
        }
    }

    void addEnd(Node *p) //将p插入最后
    {
        Node *k = head;
        while (k->Next != NULL)
        {
            k = k->Next;
        }
        k->Next = p;
    }

    void addHead(int tid, int score)
    {
        Node *t = new Node(tid, score);
        Node *p = head->Next;
        head->Next = t;
        t->Next = p;
    }

    void fristDelete()
    {
        Node *q = head;
        Node *p = head->Next;
        if (p == NULL)
        {
            return;
        }
        q->Next = p->Next;
        delete p;
    }

    void endDelete()
    {
        Node *q = head;
        Node *p = head->Next;
        if (p == NULL)
        {
            return;
        }
        while (p->Next != NULL)
        {
            p = p->Next;
            q = q->Next;
        }
        q->Next = NULL;
        delete p;
    }

    void selectiveDelete(int value_Id)
    {
        Node *p = head;
        while (p->Next != NULL)
        {
            if (p->Next->id == value_Id)
            {
                Node *t = p->Next;
                p->Next = p->Next->Next;
                delete t;
            }
            else
            {
                p = p->Next;
            }
        }
    }

    void selectiveAdd(int value_Id, int id, int score)
    {
        Node *p = head->Next;
        while (p != NULL)
        {
            if (p->id == value_Id)
            {
                Node *t = new Node(id, score);
                t->Next = p->Next;
                p->Next = t;
                break; //一定要break 不然无限循环
            }
            else
            {
                p = p->Next;
            }
        }
    }

    void Show_all()
    {
        Node *p = head->Next;
        while (p != NULL)
        {
            p->putOut();
            p = p->Next;
        }
    }

    //更新
    void reNew(int id, int score)
    {
        Node *p = head;
        while (p->Next != NULL)
        {
            if (p->Next->id == id)
            {
                p->Next->score = score;
                return;
            }
            p = p->Next;
        }
        Node *P = new Node(id, score);
        sortAdd(p);
    }

    //插入排序
    void sortAdd(Node *r)
    {
        Node *p = head->Next;
        Node *q = head;
        while (p != NULL)
        {
            if (p->id > r->id) //找刚好比其小的
            {
                Node *t = new Node(r->id, r->score);
                t->Next = q->Next;
                q->Next = t;
                return;
            }
            else
            {
                p = p->Next;
                q = q->Next;
            }
        }
        Node *t = new Node(r->id, r->score); //如果找不到 则说明其是最大的 直接丢到末尾
        t->Next = q->Next;
        q->Next = t;
    }

    void sortLink(Link *q) //思路是再来一条链子 然后全部整到新的链子上 原有的链子
    {
        Link r; //新建一个新链子
        //现在开始找到原来头结点 按顺序 排序插入
        Node *p = q->head->Next; //指针p 指向原有的头结点
        while (p != NULL)
        {
            r.sortAdd(p); //将原Link里面的内容 丢进r的排序
            p = p->Next;
        }
        r.Show_all();
    }
};

int main()
{

    Link link;
    int id, score;

    cout << "FORMAT: \"id score\"" << endl;
    cout << "END ID = 0" << endl;

    while (cin >> id && id != 0)
    {
        cin >> score;
        Node *p = new Node(id, score);
        link.addEnd(p);
    }

    cout << "*** LISTING ***" << endl;
    link.Show_all();

    cout << "*** END OF FILE ***" << endl;
    cout << "*** NEW LISTING ***" << endl;

    link.sortLink(&link); //原有的链子丢进去

    /*link.Show_all();*/

    cout << "*** END OF FILE ***" << endl;

    return 0;

}
