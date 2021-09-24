#include <iostream>
#include <vector>

using namespace std;

const long long INF = 10987654321;

class SegmentTree
{
public:
    vector<long long> minTree;
    vector<long long> maxTree;
    int N;
    
    SegmentTree(const vector<long long>& arr)
        : minTree(arr.size() * 4), maxTree(arr.size() * 4), N(arr.size() - 1)
    {
        initialize_min(arr, 1, 1, N);
        initialize_max(arr, 1, 1, N);
    }
    
    long long initialize_min(const vector<long long>& arr, int index, int left, int right)
    {
        if(left == right)
        {
            return minTree[index] = arr[left];
        }
        
        int mid = (left + right) / 2;
        
        return minTree[index] = min(initialize_min(arr, index * 2, left, mid), initialize_min(arr, index * 2 + 1, mid + 1, right));
    }
    
    long long initialize_max(const vector<long long>& arr, int index, int left, int right)
    {
        if(left == right)
        {
            return maxTree[index] = arr[left];
        }
        
        int mid = (left + right) / 2;
        
        return maxTree[index] = max(initialize_max(arr, index * 2, left, mid), initialize_max(arr, index * 2 + 1, mid + 1, right));
    }
    
    long long getRangeMin(int L, int R, int index, int left, int right)
    {
        if(left > R || right < L)
        {
            return INF;
        }
        
        if(L <= left && right <= R)
        {
            return minTree[index];
        }
        
        int mid = (left + right) / 2;
        
        return min(getRangeMin(L, R, index * 2, left, mid), getRangeMin(L, R, index * 2 + 1, mid + 1, right));
    }
    
    long long getRangeMin(int L, int R)
    {
        return getRangeMin(L, R, 1, 1, N);
    }
    
    
    long long getRangeMax(int L, int R, int index, int left, int right)
    {
        if(left > R || right < L)
        {
            return -1;
        }
        
        if(L <= left && right <= R)
        {
            return maxTree[index];
        }
        
        int mid = (left + right) / 2;
        
        return max(getRangeMax(L, R, index * 2, left, mid), getRangeMax(L, R, index * 2 + 1, mid + 1, right));
    }
    
    long long getRangeMax(int L, int R)
    {
        return getRangeMax(L, R, 1, 1, N);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<long long> arr(N + 1);
    
    for(int i=1; i<=N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    
    SegmentTree segmentTree(arr);
    
    for(int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        printf("%lld %lld\n", segmentTree.getRangeMin(a, b), segmentTree.getRangeMax(a, b));
    }
    
    return 0;
}
