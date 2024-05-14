BinTree Insert(BinTree BST, ElementType X)
{
    if (!BST)
    {
        BST = (BinTree)malloc(sizeof(BinTree));
        BST->Left = NULL;
        BST->Right = NULL;
        BST->Data = X;
    }
    else
    {
        if (X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else if (X > BST->Data)
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}
BinTree Delete(BinTree BST, ElementType X)
{
    Position Tmp;
    if (!BST)
        printf("Not Found\n");
    else
    {
        if (X < BST->Data)
            BST->Left = Delete(BST->Left, X);
        else if (X > BST->Data)
            BST->Right = Delete(BST->Right, X);
        else
        {
            if (BST->Left && BST->Right)
            {
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right, BST->Data);
            }
            else
            {
                Tmp = BST;
                if (!BST->Left)
                {
                    BST = BST->Right;
                }
                else
                {
                    BST = BST->Left;
                }
                free(Tmp);
            }
        }
    }
    return BST;
}
Position Find(BinTree BST, ElementType X)
{
    if (!BST)
        return NULL;
    else
    {
        if (X < BST->Data)
            return Find(BST->Left, X);
        else if (X > BST->Data)
            return Find(BST->Right, X);
        else
            return BST;
    }
}
Position FindMin(BinTree BST)
{
    if (!BST)
        return NULL;
    if (!BST->Left)
        return BST;
    else
        return FindMin(BST->Left);
}
Position FindMax(BinTree BST)
{
    if (!BST)
        return NULL;
    if (!BST->Right)
        return BST;
    else
        return FindMax(BST->Right);
}