/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std; 
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define Int long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define mp make_pair
#define maxN 100005


struct Edge {
    bool open;
    int x, yMin, yMax;
    Edge(int x, int y1, int y2, bool op) {
        this->x = x;
        yMin = y1, yMax = y2;
        open = op;
    }
    bool operator < (const Edge &e) const {
        return (x < e.x);
    }
};


int n, m, h[maxN << 1];
int sum[maxN << 5], counter[maxN << 5];
vector<Edge> edges;




void update(int p, int l, int r, int yMin, int yMax, bool open) {

  if (h[r] < yMin || yMax < h[l]) return;

  int c = p << 1, mid = (l + r) >> 1;

  if (yMin <= h[l] && h[r] <= yMax)
  { // ymin --- h[l] --- h[r] --- ymax
      counter[p] += open ? 1 : -1;
      if (counter[p])
          sum[p] = h[r] - h[l]; //if there is a rectangle at that posn that is bw h[l] and h[r] we will add that to length
      else
          sum[p] = sum[c] + sum[c + 1]; // else we will just sumup of lengths above and beloew this region
      return;
    }

    if (l + 1 >= r) return;

    update(c, l, mid, yMin, yMax, open);
    update(c + 1, mid, r, yMin, yMax, open);

    if (counter[p]) sum[p] = h[r] - h[l];
    else sum[p] = sum[c] + sum[c + 1];



}

int64 solve() {
                                // process height for horzntl. sweep line
    sort(h + 1, h + m + 1);    //  Sorting the hieght according to the y coordinates
    int k = 1;

    REP (i, 2, m) if (h[i] != h[k])  //  Deleting the same horizontal sweeplines
       h[++k] = h[i];                //     as they are redundant
           m = k;
        long long num  = m;
    for (int i = 0, lm = maxN << 4; i < lm; i++) // This is the initialization step of segment tree
        sum[i] = 0, counter[i] = 0;

    int64 area = 0LL;  //  Initializing the Area
    sort(all(edges));  // Sorting according to x coordinates for ver. swp line
    update(1, 1, m, edges[0].yMin, edges[0].yMax, edges[0].open);
    for (int i = 1; i < edges.size(); i++) {
        area += sum[1] * (int64)(edges[i].x - edges[i - 1].x);
        update(1, 1, m, edges[i].yMin, edges[i].yMax, edges[i].open);
    }
    return area;
}

int main() {
      int n;
      cin>>n;
      int  x1, y1, x2, y2;
    edges.clear();
    m = 0;
    REP (i, 1, n) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1==x2 && y1>y2)swap(y1,y2);
        else if(y1==y2   && x1>x2)swap(x1,x2);
        x2+=1;    // x1 and y1 are bottom left coordinates
        y2+=1;    // x2 and y2 are top right coordinates
        edges.pb(Edge(x1, y1, y2, true));   // Inserting the Left edge
        edges.pb(Edge(x2, y1, y2, false));  // Inserting the Right Edge
        h[++m] = y1;
        h[++m] = y2;
    }
    printf("%lld\n", solve());

    return 0;
}