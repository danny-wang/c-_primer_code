
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
//-----------------------------------------------------------------------------
//二叉查找树（BST）是二叉树的一个重要的应用，它在二叉树的基础上加上了这样的一个性质：
//	对于树中的每一个节点来说，如果有左儿子的话，它的左儿子的值一定小于它本身的值，如果有右儿子的话，它的右儿子的值一定大于它本身的值。

//二叉查找树节点信息
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
class TreeNode
{
    public:
        TreeNode():lson(nullptr),rson(nullptr),freq(1){}//初始化
        T data;//值
        TreeNode* lson;//指向左儿子的坐标
        TreeNode* rson;//指向右儿子的坐标
        unsigned int freq;//值出现的次数
};

//二叉查找树类的属性和方法声明
template<class T>
class BST
{
    private:
        TreeNode<T>* root;//根节点
        unsigned   int size_of_BST=0;
        void insertpri(TreeNode<T>* &node,T x);//插入
        TreeNode<T>* findpri(TreeNode<T>* node,T x);//查找
        void insubtree(TreeNode<T>* node);//中序遍历
        void Deletepri(TreeNode<T>* &node,T x);//删除
    public:
        BST():root(nullptr){}
        void insert(T x);//插入接口
        TreeNode<T>* find(T x);//查找接口
        void Delete(T x);//删除接口
        void traversal();//遍历接口
        unsigned int size();
 
};

//插入
template<class T>
void BST<T>::insertpri(TreeNode<T>* &node,T x)
{
    if(node==nullptr)//如果节点为空,就在此节点处加入x信息
    {
        node=new TreeNode<T>();
        node->data=x;
        size_of_BST++;
        return;
    }
    if(node->data>x)//如果x小于节点的值,就继续在节点的左子树中插入x
    {
        insertpri(node->lson,x);
    }
    else if(node->data<x)//如果x大于节点的值,就继续在节点的右子树中插入x
    {
        insertpri(node->rson,x);
    }
    else {
    	++(node->freq);//如果相等,就把频率加1
    	size_of_BST++;
    }
}
//插入接口
template<class T>
void BST<T>::insert(T x)
{
    insertpri(root,x);
}

//查找
template<class T>
TreeNode<T>* BST<T>::findpri(TreeNode<T>* node,T x)
{
    if(node==nullptr)//如果节点为空说明没找到,返回nullptr
    {
        return nullptr;
    }
    if(node->data>x)//如果x小于节点的值,就继续在节点的左子树中查找x
    {
        return findpri(node->lson,x);
    }
    else if(node->data<x)//如果x大于节点的值,就继续在节点的左子树中查找x
    {
        return findpri(node->rson,x);
    }
    else return node;//如果相等,就找到了此节点
}
//查找接口
template<class T>
TreeNode<T>* BST<T>::find(T x)
{
    return findpri(root,x);
}

//删除
template<class T>
void BST<T>::Deletepri(TreeNode<T>* &node,T x)
{
    if(node==nullptr) return ;//没有找到值是x的节点
    if(x < node->data)
    	Deletepri(node->lson,x);//如果x小于节点的值,就继续在节点的左子树中删除x
    else if(x > node->data)
    	Deletepri(node->rson,x);//如果x大于节点的值,就继续在节点的右子树中删除x
    else//如果相等,此节点就是要删除的节点
    {
        if(node->lson&&node->rson)//此节点有两个儿子
        {
            TreeNode<T>* temp=node->rson;//temp指向节点的右儿子
            while(temp->lson!=nullptr) temp=temp->lson;//找到右子树中值最小的节点
            //把右子树中最小节点的值赋值给本节点
            node->data=temp->data;
            node->freq=temp->freq;
            Deletepri(node->rson,temp->data);//删除右子树中最小值的节点
        }
        else//此节点有1个或0个儿子
        {
            TreeNode<T>* temp=node;
            if(node->lson==nullptr)//有右儿子或者没有儿子
            node=node->rson;
            else if(node->rson==nullptr)//有左儿子
            node=node->lson;
            delete(temp);
            size_of_BST--;
        }
    }
    return;
}
//删除接口
template<class T>
void BST<T>::Delete(T x)
{
    Deletepri(root,x);
}

//中序遍历函数
template<class T>
void BST<T>::insubtree(TreeNode<T>* node)
{
    if(node==nullptr) return;
    insubtree(node->lson);//先遍历左子树
    cout<<node->data<<" ";//输出根节点
    insubtree(node->rson);//再遍历右子树
}
//中序遍历接口
template<class T>
void BST<T>::traversal()
{
    insubtree(root);
}

template<typename T>
unsigned int BST<T>::size(){
	return size_of_BST;
}
#endif /* BINARYSEARCHTREE_H */