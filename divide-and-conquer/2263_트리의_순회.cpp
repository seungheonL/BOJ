#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inorder;
vector<int> postorder;

void preorder(int start_in, int end_in, int start_post, int end_post)
{
    if(start_in > end_in || start_post > end_post)
    {
        return;
    }
    
    int here = postorder[end_post];
    cout << here << " ";
    
    int mid;
    for(int i=start_in; i<=end_in; i++)
    {
        if(inorder[i] == here)
        {
            mid = i;
            break;
        }
    }
    
    preorder(start_in, mid - 1, start_post, start_post + mid - start_in - 1);
    preorder(mid + 1, end_in, start_post + mid - start_in, end_post-1);
    
    //preorder(slice(inorder, 0, mid), slice(postorder, 0, mid));
    //preorder(slice(inorder, mid+1, inorder.size()), slice(postorder, mid, postorder.size() - 1));
}

int main()
{
    int n;
    cin >> n;
    
    inorder = vector<int>(n), postorder = vector<int>(n);
    
    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        
        inorder[i] = in;
    }
    
    for(int i=0; i<n; i++)
    {
        int post;
        cin >> post;
        
        postorder[i] = post;
    }
    
    preorder(0, n-1, 0, n-1);
    
    return 0;
}
