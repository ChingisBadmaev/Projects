#include <iostream>
using namespace std;

template<class T>
struct BNode
{
	T data;
	BNode<T>* left, * right;
	BNode(T dd, BNode<T>* l = nullptr, BNode<T>* r = nullptr) :
		data(dd), left(l), right(r) {}
};

/*find the right-most grandson*/
template<class T>
BNode<T>* rightmost_grandson(BNode<T>* r)
{
	if (r == nullptr)
	{
		return nullptr;
	}

	if (r->right != nullptr)
	{
		if (r->right->right != nullptr)
		{
			return r->right->right;
		}
		if (r->right->left != nullptr)
		{
			return r->right->left;
		}
	}
	if (r->left != nullptr)
	{
		if (r->left->right != nullptr)
		{
			return r->left->right;
		}
		if (r->left->left != nullptr)
		{
			return r->left->left;
		}
	}
	return nullptr;
}

/*find the number of grandsons*/
template<class T>
int number_of_grandson(BNode<T>* r)
{
	int c = 0;
	if (r == nullptr)
	{
		return nullptr;
	}
	if (r->left != nullptr)
	{
		if (r->left->left != nullptr)
		{
			c++;
		}
		if (r->left->right != nullptr)
		{
			c++;
		}
	}
	if (r->right != nullptr)
	{
		if (r->right->left != nullptr)
		{
			c++;
		}
		if (r->right->right != nullptr)
		{
			c++;
		}
	}
	return c;
}

/*alternately moving left and right*/
template<class T>
void root_update(BNode<T>* r)
{
	if (r == nullptr)
	{
		return;
	}
	if (r->left == nullptr)
	{
		return nullptr;
	}
	BNode<T>* n_r = r;
	r = r->left;
	delete n_r;
}

/*the new node becomes the left son root
the old left son of the root becomes the left son of the new node
the new son will not have the right son*/
template<class T>
void new_root1(BNode<T>* r, T d)
{
	if (r == nullptr)
	{
		return;
	}
	BNode<T>* new_node;
	new_node; = r->left;
	new_node->data = d;
	new_node->left = r->left;
	new_node->right = nullptr;
}

/*the new node becomes left the son of the root
the old sons of the root become the sons of the new knot*/
template<class T>
void new_root2(BNode<T>* r, T d)
{
	if (r == nullptr)
	{
		return;
	}
	BNode<T>* new_root;
	new_root->data = d;
	new_root->left = r->left;
	new_root->right = r->right;
	r->left = new_root;
	new_root->right = nullptr;
}

/*swap of root and left son*/
template<class T>
void swap_root_left(BNode<T>* r)
{
	if (r == nullptr)
	{
		return nullptr;
	}
	BNode<T>* temp;
	if (r->left != nullptr)
	{
		temp->left = r->left;
		temp->right = r->right;
	}
	r->left = r->left->left;
	r->right = r->left->right;
	r->left = temp->left;
	r->right = temp->right;
}

/*find the leftmost node*/
template<class T>
BNode<T>* leftmost_knot(BNode<T>* r)
{
	if (r == nullptr)
	{
		return nullptr;
	}
	BNode<T>* temp = r;
	if (temp == nullptr)
	{
		return;
	}
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
}

/*alternately moving left and right*/
template<class T>
BNode<T>* zigzag(BNode<T>* r)
{
	if (r == nullptr)
	{
		return nullptr;
	}
	BNode<T>* temp = r;
	if (temp == nullptr)
	{
		return;
	}
	while (true)
	{
		if (temp->left != nullptr)
		{
			temp = temp->left;
		}
		else
		{
			return temp;
		}

		if (temp->right != nullptr)
		{
			temp = temp->right;
		}
		else
		{
			returen temp;
		}
	}
}

/*find the leftmost sheet*/
template<class T>
BNode<T>* leftmost_sheet(BNode<T>* r)
{
	if (r == nullptr)
	{
		return;
	}
	BNode<T>* temp = r;
	while (temp->left != nullptr || temp->right != nullptr)
	{
		if (temp->left != nullptr)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return temp;
}

/*find the second left sheet*/
template<class T>
BNode<T>* second_left_sheet(BNode<T>* r)
{
	if (r == nullptr)
	{
		return nullptr;
	}
	BNode<T>* temp1 = r;
	BNode<T>* temp2 = nullptr;
	while (temp1->left != nullpt || temp1->right != nullptr)
	{
		if (temp1->left != nullptr && temp1->right != nullptr)
		{
			temp2 = temp1;
		}
		if (temp1->left != nullptr)
		{
			temp1 = temp1->left;
		}
		else
		{
			temp1 = temp1->right;
		}
	}
	temp2 = temp2->right;
	while (temp2->left != nullpt || temp2->right != nullptr)
	{
		if (temp2->left != nullptr)
		{
			temp2 = temp1->left;
		}
		else
		{
			temp2 = temp1->right;
		}
	}
	return temp2;
}

/*delete the leftmost node
 his right son becomes his father's left son*/
template<class T>
void delete_rightmost_node(BNode<T>* r)
{
	if (r == nullptr)
	{
		return;
	}
	if (r->left == nullptr)
	{
		delete r;
		return;
	}
	BNode<T>* temp = r;
	while (temp->left->left != nullptr)
	{
		temp = temp->left;
	}
	if (temp->left->right != nullptr)
	{
		temp->left = temp->left->right;
	}
}

int main()
{
	return 0;
}
