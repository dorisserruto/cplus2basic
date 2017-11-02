#include <iostream>

#include "BinaryTree.h"
#include "TreeTraits.h"

using namespace std;

int main(){

	char anyKey;
	cout<<"Arboles Binarios"<<endl;

	BinaryTree<TreeTraits> btMyTree;
	
	btMyTree.insert(33);
	btMyTree.insert(23);
	btMyTree.insert(41);
	btMyTree.insert(11);
	btMyTree.insert(27);
	btMyTree.insert(37);
	btMyTree.insert(51);
	
	cout<<"InOrder"<<endl;
	btMyTree.in_order(btMyTree.root);
	cout<<"PreOrder"<<endl;
	btMyTree.pre_order(btMyTree.root);
	cout<<"PostOrder"<<endl;
	btMyTree.post_order(btMyTree.root);

	cout<<"Wait any key ..."<<endl;
	cin>>anyKey;
	return 0;
};