#include <iostream>
template <class Type>
class CNode
{
private:
    CNode* left, * right, * parent;
    Type key;
public:
    CNode() : left(nullptr), right(nullptr), parent(nullptr), key(1)
    {}
    void setLeft(CNode<Type>* ptr);
    void setRight(CNode<Type>* ptr);
    void setParent(CNode<Type>* ptr);
    void setKey(Type value);
    Type getKey();
    CNode<Type>* getLeft();
    CNode<Type>* getRight();
    CNode<Type>* getParent();
};
template <class Type>
void CNode<Type>::setLeft(CNode<Type>* ptr)
{
    left = ptr;
}
template <class Type>
void CNode<Type>::setRight(CNode<Type>* ptr)
{
    right = ptr;
}
template <class Type>
void CNode<Type>::setParent(CNode<Type>* ptr)
{
    parent = ptr;
}
template <class Type>
void CNode<Type>::setKey(Type value)
{
    key = value;
}
template <class Type>
Type CNode<Type>::getKey()
{
    if (this != nullptr)
    {
        return key;
    }
}
template <class Type>
CNode<Type>* CNode<Type>::getLeft()
{
    return left;
}
template <class Type>
CNode<Type>* CNode<Type>::getRight()
{
    return right;
}
template <class Type>
CNode<Type>* CNode<Type>::getParent()
{
    return parent;
}

template <class Type>
class CBinaryTree
{
protected:
    CNode<Type>* root;
public:
    CBinaryTree<Type>(): root(nullptr)
    {}
    CNode<Type>* getRoot();
    void add(Type value);
    void print();
};

template <class Type>
CNode<Type>* CBinaryTree<Type>::getRoot()
{
    return root;
}
template <class Type>
void CBinaryTree<Type>::add(Type value)
{
    addNode(value, root);
}
template <class Type>
void CBinaryTree<Type>::print()
{
    treePrint(root);
}

template <class Type>
void treePrint(CNode<Type>* ptr);
template <class Type>
void addNode(Type value, CNode<Type>* ptr);

int main()
{
    CBinaryTree<int> tr;
    tr.add(2);
    tr.add(3);
    tr.print();
    return 0;
}

template <class Type>
void treePrint(CNode<Type>* ptr)
{
    if (ptr != nullptr)
    {
        std::cout << ptr->getKey() << std::endl;
        treePrint(ptr->getLeft());
        treePrint(ptr->getRight());
    }
}

template <class Type>
void addNode(Type value, CNode<Type>* ptr)
{
    if (ptr == nullptr)
    {
        //Не работает связь между узлами => не выводит
        CNode<Type>* node = new CNode<Type>;
        node->setLeft(nullptr);
        node->setRight(nullptr);
        node->setParent(nullptr);
        node->setKey(value);
    }
    else if (value <= ptr->getKey())
    {
        ptr.
        ptr->getLeft()->setParent(ptr);
        addNode(value, ptr->getLeft());
    }
    else
    {
        addNode(value, ptr->getRight());
    }
}