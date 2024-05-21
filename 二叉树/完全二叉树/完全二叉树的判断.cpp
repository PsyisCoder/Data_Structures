
//完全二叉树的判断

/*思路：（1）任一节点有右孩子无左孩子返回false
	    （2）在一不违规的条件下，如果遇到了第一个左右孩子不全的情况，则后续皆是叶子节点*/


//在层序遍历的基础上

bool FloorPrint_QUEUE(pTreeNode& Tree) //层序遍历_队列实现
{
    queue < pTreeNode> q;
    bool leaf = false;
    pTreeNode l = NULL;
    pTreeNode r = NULL;
    if (Tree != NULL)
    {
        q.push(Tree);   //根节点进队列
    }

    while (q.empty() == false)  //队列不为空判断
    {
        l = q.front()->leftPtr;
        r = q.front()->rightPtr;

        if (
            //如果遇到了不双全的节点，又发现当前节点有孩子
            (leaf && (l != NULL || r != NULL))
            ||
            (l == NULL && r != NULL)
            ) {
            return false;
        }

        if (q.front()->leftPtr != NULL)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->leftPtr);
        }

        if (q.front()->rightPtr != NULL)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->rightPtr);
        }
        if (l == NULL || r == NULL)
            leaf = true;
        q.pop();  //已经遍历过的节点出队列
    }
    return true;
}