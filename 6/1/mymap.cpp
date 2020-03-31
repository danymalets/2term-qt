#include "mymap.h"

int MyMap::getHight(Node *root)
{
    if (root == nullptr) return 0;
    else return root->hight;
}

int MyMap::getBalanceValue(Node *root)
{
    return getHight(root->right) - getHight(root->left);
}

void MyMap::fixHight(Node *root)
{
    root->hight = std::max(getHight(root->left), getHight(root->right)) + 1;
}

Node *MyMap::rotateLeft(Node *root)
{
    Node *t = root->right;
    root->right = t->left;
    t->left = root;
    fixHight(root);
    fixHight(t);
    return t;
}

Node *MyMap::rotateRight(Node *root)
{
    Node *t = root->left;
    root->left = t->right;
    t->right = root;
    fixHight(root);
    fixHight(t);
    return t;
}

Node *MyMap::balance(Node *root)
{
    fixHight(root);
    int th = getBalanceValue(root);
    if (th == 2){
        if (getBalanceValue(root->right) < 0){
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    }
    else if (th == -2){
        if (getBalanceValue(root->left) > 0){
            root->left = rotateLeft(root->left);
        }
        return rotateRight(root);
    }
    return root;
}

Node *MyMap::add(Node *root, int key, QString value)
{
    if (root == nullptr) return new Node(key, value);
    if (key == root->key){
        root->value = value;
    }
    else if (key < root->key){
        root->left = add(root->left, key, value);
    }
    else{
        root->right = add(root->right, key, value);
    }
    return balance(root);
}

void MyMap::rec(QTreeWidget *tree, QTreeWidgetItem *p, Node *r, bool b)
{
    if (r == nullptr) return;

    QTreeWidgetItem *itm = new QTreeWidgetItem();
    if (b) itm->setBackground(0, Qt::blue);
    else itm->setBackground(0, Qt::red);
    itm->setText(0, QString::number(r->key));
    itm->setText(1, r->value);
    p->addChild(itm);

    rec(tree, itm, r->left, true);
    rec(tree, itm, r->right, false);

    tree->expandItem(itm);
}

QString MyMap::getValue(Node *r, int key)
{
    if (r == nullptr) return NULL;
    if (key == r->key) {
        return r->value;
    }
    else if (key < r->key) {
        return getValue(r->left, key);
    }
    else{
        return getValue(r->right, key);
    }
}

Node *MyMap::removemin(Node *root)
{
    if (root->left == nullptr) return root->right;
    root->left = removemin(root->left);
    return balance(root);
}

Node *MyMap::remove(Node *root, int key)
{
    if (root == nullptr) return nullptr;
    if (key == root->key){
        Node *l = root->left;
        Node *r = root->right;
        delete root;
        if (r == nullptr) return l;
        Node *min_node = findmin(r);
        min_node->right = removemin(r);
        min_node->left = l;
        return balance(min_node);
    }
    else if (key < root->key){
        root->left = remove(root->left, key);
    }
    else{
        root->right = remove(root->right, key);
    }
    return balance(root);
}

void MyMap::clear(Node *root)
{
    if (root == nullptr) return;
    clear(root->left);
    clear(root->right);
    delete root;
}

void MyMap::output(QTreeWidget *tree)
{
    tree->clear();
    if (root == nullptr) return;
    QTreeWidgetItem *itm = new QTreeWidgetItem(tree);

    itm->setText(0, QString::number(root->key));
    itm->setText(1, root->value);
    tree->addTopLevelItem(itm);

    rec(tree, itm, root->left, true);
    rec(tree, itm, root->right, false);

    tree->expandItem(itm);

    tree->resizeColumnToContents(0);
}

void MyMap::insert(int key, QString value)
{
    root = add(root, key, value);
}

QString MyMap::getValue(int key)
{
    return getValue(root, key);
}

void MyMap::remove(int key)
{
    root = remove(root, key);
}

void MyMap::clear()
{
    clear(root);
    root = nullptr;
}

QString MyMap::dfs1(Node *root)
{
    if (root == nullptr) return "";
    QString s;
    s = "[" + QString::number(root->key) + "]" +root->value + "  ";
    s += dfs1(root->left);
    s += dfs1(root->right);
    return s;
}

QString MyMap::dfs2(Node *root)
{
    if (root == nullptr) return "";
    QString s;
    s = dfs1(root->left);
    s += dfs1(root->right);
    s += "[" + QString::number(root->key) + "]" +root->value + "  ";
    return s;
}

QString MyMap::dfs3(Node *root)
{
    if (root == nullptr) return "";
    QString s;
    s = dfs1(root->left);
    s += "[" + QString::number(root->key) + "]" +root->value + "  ";
    s += dfs1(root->right);
    return s;
}
