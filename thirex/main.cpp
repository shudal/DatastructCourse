#include <iostream>
#include <string>
#include "BTree.cpp"
using namespace std;
int main() {
    cout<<"括号表达式表示二叉树：";
    // cin>>s;

    //string ka = "A(B(C,D(,E)),)";
    //BTree<char> tree(ka);
    BTree<char> tree("A(B(C,D(,E)),)");
    // BTree<char> tree("a(b(c),d(e(,f),g))");

    cout<<"后序递归遍历输出:";
    tree.postOrder(tree.b);
    cout<<endl;

    cout<<"中序非递归输出：";
    tree.inOrderNotRe();
    cout<<endl;

    cout<<"前序非递归输出：";
    tree.preOrderNotRe();
    cout<<endl;

    cout<<"输入代号:";
    char c;
    cin>>c;
    cout<<"长辈们：";
    tree.showAncestors(c);

    cout<<endl<<"finish!"<<endl;
}
