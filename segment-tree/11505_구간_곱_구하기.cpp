#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

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
        
        return tree[index] = (initialize(arr, index * 2, left, mid) % MOD * initialize(arr, index * 2 + 1, mid + 1, right) % MOD) % MOD;
    }
    
    long long getRangeProduct(int L, int R, int index, int left, int right)
    {
        if(left > R || right < L)
        {
            return 1;
        }
        
        if(L <= left && right <= R)
        {
            return tree[index];
        }
        
        int mid = (left + right) / 2;
        
        return (getRangeProduct(L, R, index * 2, left, mid) % MOD * getRangeProduct(L, R, index * 2 + 1, mid + 1, right) % MOD) % MOD;
    }
    
    long long getRangeProduct(int L, int R)
    {
        return getRangeProduct(L, R, 1, 1, N);
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
        
        return tree[index] = (update(target, value, index * 2, left, mid) % MOD * update(target, value, index * 2 + 1, mid + 1, right) % MOD) % MOD;
    }
    
    void update(int target, long long value)
    {
        update(target, value, 1, 1, N);
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
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if(a == 1)
        {
            arr[b] = c;
            
            segmentTree.update(b, c);
        }
        
        else if(a == 2)
        {
            printf("%lld\n", segmentTree.getRangeProduct(b, c));
        }
        
    }
    
    return 0;
}
