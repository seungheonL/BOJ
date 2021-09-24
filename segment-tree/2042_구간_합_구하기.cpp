#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
public:
    vector<long long> tree;
    int N;
    
    SegmentTree(const vector<long long>& arr)
        : tree(arr.size() * 4), N(arr.size() - 1)
    {
        initialize(arr, 1, 1, N);
    }
    
    long long initialize(const vector<long long>& arr, int index, int left, int right)
    {
        if(left == right)
        {
            return tree[index] = arr[left];
        }
        
        int mid = (left + right) / 2;
        
        return tree[index] = initialize(arr, index * 2, left, mid) + initialize(arr, index * 2 + 1, mid + 1, right);
    }
    
    long long getRangeSum(int L, int R, int index, int left, int right)
    {
        if(left > R || right < L)
        {
            return 0;
        }
        
        if(L <= left && right <= R)
        {
            return tree[index];
        }
        
        int mid = (left + right) / 2;
        
        return getRangeSum(L, R, index * 2, left, mid) + getRangeSum(L, R, index * 2 + 1, mid + 1, right);
    }
    
    long long getRangeSum(int L, int R)
    {
        return getRangeSum(L, R, 1, 1, N);
    }
    
    long long update(int target, long long value, int index, int left, int right)
    {
        if(target < left || right < target)
        {
            return tree[index];
        }
        
        if(left == right)
        {
            return tree[index] = value;
        }
        
        int mid = (left + right) / 2;
        
        return tree[index] = update(target, value, index * 2, left, mid) + update(target, value, index * 2 + 1, mid + 1, right);
    }
    
    void update(int target, long long difference)
    {
        update(target, difference, 1, 1, N);
    }
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<long long> arr(N + 1);
    
    for(int i=1; i<=N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    
    SegmentTree segmentTree(arr);
    
    for(int i=0; i<M+K; i++)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        
        if(a == 1)
        {
            arr[b] = c;
            
            segmentTree.update(b, c);
        }
        
        else if(a == 2)
        {
            printf("%lld\n", segmentTree.getRangeSum(b, c));
        }
    }
    
    return 0;
}
