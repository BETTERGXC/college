//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，
//根结点编号为1。现在有两个结点 a，b。请设计一个算法，
//求出a和b点的最近公共祖先的编号。 给定两个int a,b。为给定结点的编号。



int getLCA(int a, int b) {
    // write code here
    int less, more;
    if (a > b) {
        more = a;
        less = b;
    }
    else {
        more = b;
        less = a;
    }
    while (less > 0) {
        while (more > less) {
            //if (more % 2 != 0) {
            //    more = more - 1;
            //}
            more = more / 2;
        }
        if (more == less)
            return less;
        less = less / 2;
        if (more == less)
            return less;
    }
    
    
}