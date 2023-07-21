#include "2105002.h"


int main(){
    BST b;
    FILE* fp = fopen("in.txt","r");
    char ch;
    char str1[] = "not found";
    char str2[] = "found";
    char str[10];
    int n;
    while(!feof(fp)){
        fscanf(fp,"%c",&ch);
        if(ch == 'I'){
            fscanf(fp,"%c",&ch);
            if(ch == ' '){
            fscanf(fp,"%d",&n);
            b.insert(n);
            b.printBST();
            
            }

        }

        if(ch == 'D'){
            fscanf(fp,"%c",&ch);
            if(ch == ' '){
                fscanf(fp,"%d",&n);
                b.deleteBST(n);
                b.printBST();
            }
        }

        if(ch == 'F'){
            fscanf(fp,"%c",&ch);
            if(ch == ' '){
                fscanf(fp,"%d",&n);
                bool x = b.search(n);
                if(x){
                    fprintf(ofp,"%s",str2);
                    fprintf(ofp,"\n");
                }

                else{
                    fprintf(ofp,"%s",str1);
                    fprintf(ofp,"\n");
                }
            }
        }

        if(ch == 'T'){
            fscanf(fp,"%c",&ch);
            if(ch == ' '){
                fscanf(fp,"%s",&str);
                if(!strcmp(str,"Pre")){
                    b.Preorder();
                    fprintf(ofp,"\n");
                }

                if(!strcmp(str,"Post")){
                    b.Postorder();
                    fprintf(ofp,"\n");
                }


                if(!strcmp(str,"In")){
                    b.Inorder();
                    fprintf(ofp,"\n");
                }
            }
        }
    }
    
}