class Solution {
public:

    vector <int> tree;
    int n;

    void build(int node , int start , int end , vector<int>&baskets){

        if(start == end){

            tree[node] = baskets[start];
            return;

        }

        int mid = (start + end) / 2;

        build(2 * node , start , mid , baskets);
        build(2 * node + 1 , mid + 1 , end , baskets);

        tree[node] = max(tree[2 * node] , tree[2 * node + 1]);

    }

    int query(int node , int start , int end , int fruit){

        if(tree[node] < fruit) {

            return -1;

        }

        if(start == end)
            return start;
        

            int mid = (start + end) / 2;

            if(tree[2 * node] >= fruit)
                return query(2 * node , start , mid , fruit);


            return query(2 * node + 1 , mid + 1 , end , fruit);
    }
    void update(int node , int start , int end , int idx){

            if(start == end){

                tree[node] = 0;
                return;

            }
            int mid = (start + end) / 2;

            if(idx <= mid) {
                
                update(2 * node , start , mid , idx);

            }
            else{

                update(2 * node + 1 , mid + 1 , end , idx);
            }

            tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
        }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        n = baskets.size();
        tree.resize(4 * n);

        build(1 , 0 , n - 1 , baskets);

        int ans = 0;

        for(int fruit : fruits){

            int idx = query(1 , 0 , n - 1 , fruit);

            if(idx == -1){

                ans++;

            }
            else{

                update(1 , 0 , n - 1 , idx);
            }
        }
        return ans;
    }
};