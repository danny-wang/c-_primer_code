#ifndef AVL_TREE_H
#define AVL_TREE_H

//Description: 平衡二叉树（Balanced Binary Tree）是二叉查找树的一个进化体，也是第一个引入平衡概念的二叉树。
// 1962年，G.M. Adelson-Velsky 和 E.M. Landis发明了这棵树，所以它又叫AVL树。
// 平衡二叉树要求对于每一个节点来说，它的左右子树的高度之差不能超过1，
// 如果插入或者删除一个节点使得高度之差大于1，就要进行节点之间的旋转，将二叉树重新维持在一个平衡状态。
// 这个方案很好的解决了二叉查找树退化成链表的问题，把插入，查找，删除的时间复杂度最好情况和最坏情况都维持在O(logN)。
// 但是频繁旋转会使插入和删除牺牲掉O(logN)左右的时间，不过相对二叉查找树来说，时间上稳定了很多。
#include <iostream>
using std::cout;
using std::endl;
//AVL树节点信息
namespace avl{
template<class T>
class TreeNode
{
    public:
        TreeNode():lson(nullptr),rson(nullptr),freq(1),hgt(0){}
        T data;//值
        TreeNode* lson;//指向左儿子的地址
        TreeNode* rson;//指向右儿子的地址
        unsigned int freq;//频率
        int hgt;//以此节点为根的树的高度
};
//AVL树类的属性和方法声明
template<class T>
class AVLTree
{
    private:
        TreeNode<T>* root;//根节点
        void insertpri(TreeNode<T>* &node,T x);//插入
        TreeNode<T>* findpri(TreeNode<T>* node,T x);//查找
        void insubtree(TreeNode<T>* node);//中序遍历
        void Deletepri(TreeNode<T>* &node,T x);//删除
        int height(TreeNode<T>* node);//求树的高度
        void SingRotateLeft(TreeNode<T>* &k2);//左左情况下的旋转
        void SingRotateRight(TreeNode<T>* &k2);//右右情况下的旋转
        void DoubleRotateLR(TreeNode<T>* &k3);//左右情况下的旋转
        void DoubleRotateRL(TreeNode<T>* &k3);//右左情况下的旋转
        int Max(int cmpa,int cmpb);//求最大值

    public:
        AVLTree():root(nullptr){}
        void insert(T x);//插入接口
        TreeNode<T>* find(T x);//查找接口
        void Delete(T x);//删除接口
        void traversal();//遍历接口

};

//计算以节点为根的树的高度
//这里规定，一棵空树的高度为-1，只有一个根节点的树的高度为0，以后每多一层高度加1。
template<class T>
int AVLTree<T>::height(TreeNode<T>* node)
{
    if(node!=nullptr)
        return node->hgt;
    return -1;
}
//求最大值
template<class T>
int AVLTree<T>::Max(int cmpa,int cmpb)
{
    return cmpa>cmpb?cmpa:cmpb;
}

//左左情况下的旋转
template<class T>
void AVLTree<T>::SingRotateLeft(TreeNode<T>* &k2)
{
    TreeNode<T>* k1;
    k1=k2->lson;
    k2->lson=k1->rson;
    k1->rson=k2;

    k2->hgt=Max(height(k2->lson),height(k2->rson))+1;
    k1->hgt=Max(height(k1->lson),k2->hgt)+1;
    k2=k1;
}
//右右情况下的旋转
template<class T>
void AVLTree<T>::SingRotateRight(TreeNode<T>* &k2)
{
    TreeNode<T>* k1;
    k1=k2->rson;
    k2->rson=k1->lson;
    k1->lson=k2;

    k2->hgt=Max(height(k2->lson),height(k2->rson))+1;
    k1->hgt=Max(height(k1->rson),k2->hgt)+1;
    k2=k1;
}
//左右情况的旋转
template<class T>
void AVLTree<T>::DoubleRotateLR(TreeNode<T>* &k3)
{
    SingRotateRight(k3->lson);
    SingRotateLeft(k3);
}
//右左情况的旋转
template<class T>
void AVLTree<T>::DoubleRotateRL(TreeNode<T>* &k3)
{
    SingRotateLeft(k3->rson);
    SingRotateRight(k3);
}

//插入
template<class T>
void AVLTree<T>::insertpri(TreeNode<T>* &node,T x)
{
    if(node==nullptr)//如果节点为空,就在此节点处加入x信息
    {
        node=new TreeNode<T>();
        node->data=x;
        return;
    }
    if(node->data>x)//如果x小于节点的值,就继续在节点的左子树中插入x
    {
        insertpri(node->lson,x);
        if(2==(height(node->lson)-height(node->rson))){
        	if(x<node->lson->data)
                SingRotateLeft(node);
            else
                DoubleRotateLR(node);
        }
            
    }
    else if(node->data<x)//如果x大于节点的值,就继续在节点的右子树中插入x
    {
        insertpri(node->rson,x);
        if(2==(height(node->rson)-height(node->lson))){ //如果高度之差为2的话就失去了平衡,需要旋转
        	 if(x>node->rson->data)
                SingRotateRight(node);
            else
                DoubleRotateRL(node);
        }
           
    }
    else ++(node->freq);//如果相等,就把频率加1
    node->hgt=Max(height(node->lson),height(node->rson))+1;
}
//插入接口
template<class T>
void AVLTree<T>::insert(T x)
{
    insertpri(root,x);
}
//查找
template<class T>
TreeNode<T>* AVLTree<T>::findpri(TreeNode<T>* node,T x)
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
TreeNode<T>* AVLTree<T>::find(T x)
{
    return findpri(root,x);
}

//删除
template<class T>
void AVLTree<T>::Deletepri(TreeNode<T>* &node,T x)
{
    if(node==nullptr) return ;//没有找到值是x的节点
    if(x < node->data)
    {
         Deletepri(node->lson,x);//如果x小于节点的值,就继续在节点的左子树中删除x
         if(2==height(node->rson)-height(node->lson)){
         	if(node->rson->lson!=nullptr&&(height(node->rson->lson)>height(node->rson->rson)) )
                DoubleRotateRL(node);
            else
                SingRotateRight(node);
         }
            
    }

    else if(x > node->data)
    {
         Deletepri(node->rson,x);//如果x大于节点的值,就继续在节点的右子树中删除x
         if(2==height(node->lson)-height(node->rson)){
         	if(node->lson->rson!=nullptr&& (height(node->lson->rson)>height(node->lson->lson) ))
                DoubleRotateLR(node);
            else
                SingRotateLeft(node);
         }
            
    }

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
            if(2==height(node->lson)-height(node->rson))
            {
                if(node->lson->rson!=nullptr&& (height(node->lson->rson)>height(node->lson->lson) ))
                    DoubleRotateLR(node);
                else
                    SingRotateLeft(node);
            }
        }
        else//此节点有1个或0个儿子
        {
            TreeNode<T>* temp=node;
            if(node->lson==nullptr)//有右儿子或者没有儿子
            node=node->rson;
            else if(node->rson==nullptr)//有左儿子
            node=node->lson;
            delete(temp);
            temp=nullptr;
        }
    }
    if(node==nullptr) return;
    node->hgt=Max(height(node->lson),height(node->rson))+1;
    return;
}
//删除接口
template<class T>
void AVLTree<T>::Delete(T x)
{
    Deletepri(root,x);
}

//中序遍历函数
template<class T>
void AVLTree<T>::insubtree(TreeNode<T>* node)
{
    if(node==nullptr) return;
    insubtree(node->lson);//先遍历左子树
    cout<<node->data<<" ";//输出根节点
    insubtree(node->rson);//再遍历右子树
}
//中序遍历接口
template<class T>
void AVLTree<T>::traversal()
{
    insubtree(root);
}

}
#endif /* AVL_TREE_H */