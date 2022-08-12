#include <iostream>
#include <string>

using namespace std;

struct branch             //Создание ветвей
{
     string word;          
    struct branch* left; 
    struct branch* right;
};
void treeprint (branch* tree) //Печать дерева в терминал
{
    if (tree != NULL)
    {      
        treeprint(tree->left);  
        cout << tree->word << " "; 
        treeprint(tree->right);
    }
}
struct branch* addnodein(string word1, branch* tree) //Добавить элемент в дерево по возрастанию
{
    if (tree == NULL)     
    {
        tree = new branch; 
        tree->word = word1;   
        tree->left = NULL;
        tree->right = NULL; 
    }
    else     
        if (word1.length() < tree-> word.length())   
            tree->left = addnodein(word1, tree->left); 
        else  
            tree->right = addnodein(word1, tree->right); 
    return(tree);
}
struct branch* addnodeou(string word1, branch* tree) //Добавить элемент в дерево по убыванию
{
    if (tree == NULL)
    {
        tree = new branch;
        tree->word = word1;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
        if (word1.length() > tree->word.length())
            tree->left = addnodeou(word1, tree->left);
        else
            tree->right = addnodeou(word1, tree->right);
    return(tree);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    struct branch* root1 = 0;
    struct branch* root2 = 0;
    string tert, word;
    int schet = 0;
    cout << "Введите строку: ";
    getline(cin, tert);
    tert += (char)' ';
    for (int i = 0; i < tert.length(); i++)
    {
        if (tert[i] != (char)' ')
        {
            schet++;
        }
        if (tert[i] == (char)' ')
        {
            for (int j = i - schet; j < i; j++)
            {
                word += (char)tert[j];
            }
            root1 = addnodein(word, root1);
            root2 = addnodeou(word, root2);
            schet = 0;
            word.clear();
        }  
    }
    cout << "Сортировка дерева по возрастанию: \n";
    treeprint(root1);
    cout << endl;
    cout << "Сортировка дерева по убыванию: \n";
    treeprint(root2);
}
