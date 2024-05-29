
/*描述
请把纸条竖着放在桌⼦上，然后从纸条的下边向上⽅对折，压出折痕后再展 开。此时有1条折痕，
突起的⽅向指向纸条的背⾯，这条折痕叫做“下”折痕 ；突起的⽅向指向纸条正⾯的折痕叫做“上”折痕
。如果每次都从下边向上⽅ 对折，对折N次。请从上到下计算出所有折痕的⽅向。

给定折的次数n,请返回从上到下的折痕的数组，若为下折痕则对应元素为"down",若为上折痕则为"up".

测试样例：
1
返回：["down"]*/



/*思路：类似与一颗二叉树，头节点是凸，每个节点的左是凸，右是凹，因此打印折痕方向就是对此二叉树中序遍历
每一次对折都会在上一次产生的折痕上下分别产生凸和凹痕*/




//题解：
class FoldPaper {
public:
    //true代表凹，false代表凸
    void printProcess(int i, int n, bool z, vector<string>& str)
    {
        if (i > n)//如果超过了最大层数则直接返回
            return;
        printProcess(i + 1, n, true, str);
        string a = z ? "down" : "up";
        str.push_back(a);
        printProcess(i + 1, n, false, str);
    }
    vector<string> foldPaper(int n) {
        // write code here
        vector<string> str;
        printProcess(1, n, true, str);
        return str;
    }

};