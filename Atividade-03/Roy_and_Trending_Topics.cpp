// https://www.hackerearth.com/pt-br/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Post
{
    ll id;
    ll z_score;
    ll update;

    Post (ll id, ll z_score, ll update) {
        this->id = id;
        this->z_score = z_score;
        this->update = update;
    }
};

struct ComparePost
{
    bool operator()(const Post & p1, const Post & p2) {
        if (p1.update != p2.update)
        {
            return p1.update < p2.update;
        }
        else
        {
            return p1.id < p2.id;
        }
    }
};

int main(){
    ll N, I, Z, P, L, C, S, U;
    priority_queue <Post, vector<Post>, ComparePost> posts;

    cin >> N;

    while (N--)
    {
        cin >> I;
        cin >> Z >> P >> L >> C >> S;
        U = ((50 * P) + (5 * L) + (10 * C) + (20 * S));
        posts.push(Post(I, U, U - Z));
    }

    for (size_t i = 5; i > 0 && !posts.empty(); i--)
    {
        cout << posts.top().id << ' ' << posts.top().z_score << endl;
        posts.pop();
    }

    return 0;
}