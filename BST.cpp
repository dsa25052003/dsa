
#include<iostream>
using namespace std;

class TreeNode
{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        value=0;
        left=NULL;
        right=NULL;

    }

    TreeNode(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
};

class BST
{
    public:
    TreeNode* root;
    TreeNode* temp;

    BST()
    {
        root=NULL;
    }

    bool isEmpty()
    {
        if(root=NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertNode(TreeNode* newnode)
    {
        if (root=NULL)
        {
            root=newnode;
        }
        else
        TreeNode* temp=root;
        while(temp!=NULL)
        {
                if(newnode->value==temp->value)
                {
                    cout<<"No need to insert"<<endl;
                    return;
                }

                else if((newnode->value<temp->value) && (temp->left==NULL))
                {
                    temp->left=newnode;
                    cout<<"Inserted to the left"<<endl;
                    break;
                }

                else if(newnode->value<temp->value)
                {
                    temp=temp->left;
                }
                else if((newnode->value>temp->value) && (temp->right==NULL))
                {
                    temp->right=newnode;
                    cout<<"Inserted to the right"<<endl;
                    break;
                
                }
                else
                {
                    temp=temp->right;
                }
        } 
        
    }

    TreeNode* 


};

int main()
{
    BST obj;
    int val;
    int option;
    do
    {
    cout<<"Enter the operation you want to perform";
    cout<<"Press 1 to insert"<<endl;
    cout<<"Press 2 to search"<<endl;
    cout<<"Press 3 to delete"<<endl;
    cout<<"Press 4 to print"<<endl;
    cout<<"Press 5 to clear"<<endl;
    cout<<"Press 0 to exit"<<endl;
    cin>>option;
    TreeNode* newnode = new TreeNode();


    switch(option)
    {
        case 0:
        break;
        case 1:
        cout<<"INSERT"<<endl;
        cout<<"Enter the value to be inserted"<<endl;
        cin>>val;
        newnode->value=val;
        obj.insertNode(newnode);
        break;
        case 2:
        cout<<"SEARCH"<<endl;
        break;
        case 3:
        cout<<"DELETE"<<endl;
        break;
        case 4:
        cout<<"PRINT"<<endl;
        break;
        case 5:
        cout<<"CLEAR"<<endl;
        break;
    }
    }while(option!=0);
    return 0;
}























#include<iostream>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
    
};
TreeNode* findmin(TreeNode* root)
{
    TreeNode*temp=root;
    while(temp&& temp->left!=NULL)
        {
            temp=temp->left;
        }
    cout<<"minimum element is"<<temp->data;
    return temp;
    
}
TreeNode* findmax(TreeNode* root)
{
    TreeNode*temp=root;
    while(temp&& temp->right!=NULL)
        {
            temp=temp->right;
        }
    cout<<"maximum element is"<<temp->data;
    return temp;
    
}
TreeNode* insert(TreeNode*root,int val)
{
    if (root==NULL)
        {
            return new TreeNode(val);
        }
    if (root->data>val)
        {
            root->left=insert(root->left,val);
        }
    else
        {
            root->right=insert(root->right,val);
        }
    return root;
}
TreeNode* deletes (TreeNode* root,int val)
{
    if (root->data>val)
        {
            root->left=deletes(root->left,val);
        }
    else if (root->data<val)
        {
            root->right=deletes(root->right,val);
        }
    else
        {
            if (root->left==NULL)
                {
                    TreeNode* temp= root->right;
                    delete(root);
                    return temp;
                }
            else if (root->right==NULL)
                {
                    TreeNode* temp= root->left;
                    delete(root);
                    return temp;
                }
            TreeNode*temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletes(root->right,temp->data);
        }
    return root;
}

void inorder(TreeNode* root)
{
    if (root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}
void preorder(TreeNode* root)
{
    if (root==NULL)
        {
            return;
        }
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root)
{
    if (root==NULL)
        {
            return;
        }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
}
TreeNode* search(TreeNode* root,int val)
{
    if (root->data==val)
        {
            cout<<"node exists"<<endl;
        }
    else if(root->data>val)
        {
            if (root->left!=NULL)
                search(root->left,val);
            else
                {
                    cout<<"node does not exist"<<endl;
                }
        }
    else if (root->data<val)
        {
            if (root->right!=NULL)
                search(root->right,val);
            else
                cout<<"node does not exist"<<endl;
        }
    
}
int main()
{
    TreeNode*root=NULL;
    int ch;
    do{
        cout<<"\n1. initialising\n2. insert\n3. delete\n4. find min\n5.find max\n6.inorder traversal\n7.preorder traversal\n8.postorder traversal\n9.exit\n";
        cin>>ch;
        switch (ch)
        {
            case 1:
                int a;
                cout<<"enter element "<<endl;
                cin>>a;
                root=insert(root,a);
                break;
            case 2:
                int o;
                int g;
                cout<<"how many elemets to be inserted"<<endl;
                cin>>o;
                for (int i=0;i<o;i++)
                    {
                        cout<<"enter element"<<endl;
                        cin>>g;
                        insert(root,g);
                    }
                break;
            case 3:
                int c;
                cout<<"enter element "<<endl;
                cin>>c;
                root=deletes(root,c);
                break;
            case 4:
                findmin (root);
                break;
            case 5:
                findmax(root);
                break;
            case 6:
                inorder (root);
                break;
            case 7:
                preorder(root);
                break;
            case 8:
                postorder(root);
                break;
            case 9:
                ch =9;
                break;
        }
    }while(ch<9);
}

