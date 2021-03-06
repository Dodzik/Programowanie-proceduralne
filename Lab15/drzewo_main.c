#include "drzewoBST.h"
#include "drzewoBST.c"

int main(){
	int tab[]={15,5,16,20,3,12,18,23,10,13,6,7};
	tnode *root=NULL;
	tnode *leaf=NULL;
	for(int i=0;i<12;i++){
		AddLeaf(tab[i],&root,leaf);
	}
	AddLeaf(21,&root,leaf);
	AddLeaf(13,&root,leaf);
	AddLeaf(68,&root,leaf);
	printf("%d\n",root->value);
	printf("INORDER");
	showInOrder(root);
	printf("PREORDER");
	printPreorder(root);
	printf("POSTORDER");
	printPostorder(root);
	printf("\nMINIMUM:\n %d\n",minimum(root));
	printf("\nMAXIMUM: \n %d \n",max(root));
	printf("\nSearch_itr 12: \n %p \n",Search_iter(root,12));
	for(int i=0;i<12;i++){
		tnode *abc;
		abc=Search_iter(root,tab[i]);
		printf("\ntab[i]:%d\n",tab[i]);
		printf("\nSuccesor : \n %p \n",Succesor(abc));
		printf("\nPredecessor : \n %p \n",Predecessor(abc));
	}
	printf("\nSearch_rek 1:\n %p \n",Search_rek(root,1));
	printf("\nSuccesor dla root: \n %p \n",Succesor(root));
	printf("\nPredecessor dla root: \n %p \n",Predecessor(root));
	Left_Rotate(&root, root);
	freeTree(root);
	return 0;
}
