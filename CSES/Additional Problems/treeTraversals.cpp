/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define esta(x, c) ((c).find(x) != (c).end())

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *buildTree(vector<int> &pre_order_seq, vector<int> &in_order_seq)
{
    if (pre_order_seq.empty() || in_order_seq.empty())
        return nullptr;
    unordered_map<int, TreeNode *> nodes;
    auto root = new TreeNode(pre_order_seq.front());
    auto curr = root;
    int in_order_index = 0;
    int in = in_order_seq.front();

    for (int i = 1; i < pre_order_seq.size(); ++i)
    {
        auto pre = pre_order_seq.at(i - 1);
        nodes.emplace(pre, curr);
        if (pre != in)
            curr = curr->left = new TreeNode(pre_order_seq.at(i));
        else
        {
            while (in_order_index < in_order_seq.size())
            {
                in = in_order_seq.at(in_order_index++);
                if (nodes.count(in))
                    curr = nodes[in];
                else
                    break;
            }
            curr = curr->right = new TreeNode(pre_order_seq.at(i));
        }
    }

    return root;
}

vi ans;

void post(TreeNode *t)
{
    if (!t)
        return;
    post(t->left);
    post(t->right);
    ans.pb(t->val);
}

int main()
{
    FIN;
    int n;
    cin >> n;
    vector<int> pre, in;
    forn(i, n)
    {
        int x;
        cin >> x;
        pre.pb(x);
    }
    forn(i, n)
    {
        int x;
        cin >> x;
        in.pb(x);
    }
    TreeNode *t = buildTree(pre, in);
    post(t);
    DBGV(ans, n);
    return 0;
}
