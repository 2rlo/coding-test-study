#include <bits/stdc++.h>
using namespace std;

struct village {
    int snd, rcv, box;
};

bool cmp(const struct village& a, const struct village& b) {
    if (a.rcv != b.rcv)
        return a.rcv < b.rcv;
    else
        return a.snd < b.snd;
}

int main() {
    int N, C;
    cin >> N >> C;

    int M;
    cin >> M;

    int snd, rcv, box;
    vector<struct village> vil;
    for (int i = 0; i < M; i++) {
        cin >> snd >> rcv >> box;
        vil.push_back({snd, rcv, box});
    }

    sort(vil.begin(), vil.end(), cmp);

    int from, to, num;
    int delivered = 0;
    int truck[2001] = { 0 };
    for (int i = 0; i < M; i++) {
        from = vil[i].snd;
        to = vil[i].rcv;
        num = vil[i].box;

        int maxi = 0;
        for (int j = from; j < to; j++)
            maxi = max(truck[j], maxi);

        int remain = min(num, C - maxi);
        for (int j = from; j < to; j++)
            truck[j] += remain;

        delivered += remain;
    }
    cout << delivered;
    return 0;
}