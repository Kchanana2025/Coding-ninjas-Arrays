// i pasted this .h file here because I wanted to include it into class BST
#include <vector>
template <typename T>
class Binary_tree
{
public: // we made it public taki hamien getter aur setter functions na bnane padhe
    T data;
    Binary_tree<T> *left;
    Binary_tree<T> *right;
    Binary_tree(T data)
    {
        this->data = data;
        left = NULL; // garbage set krna is not right,its better if you set it to NULL
        right = NULL;
    }
    ~Binary_tree()
    {                 // if it is single node then on calling left delete NULL will be called and phir delete NULL ignore ho jata hai kuch ni krta delete NULL
        delete left;  // sbse pehle root ka(provided u have written delete root)phir left Node ka destructor call hoga aur phir uske left ka same hi right ke lie hoga aur poora tree will be deleted
        delete right; // lekin deletion destructor poora jab call ho jata uske baad deletion hoti hai
    }
};