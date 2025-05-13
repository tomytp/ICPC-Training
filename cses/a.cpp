template<typename T, T (*comb)(T, T), T neutral>
struct node {
    ll lm, rm;
    unique_ptr<node> lChild, rChild;
    T val = 0;

    node(ll lm_, ll rm_, vector<T>& v) : lm(lm_), rm(rm_), lChild(nullptr), rChild(nullptr) {
        if (lm == rm) {
            val = v[lm];
        } else {
            ll mid = (lm + rm) / 2;
            lChild = make_unique<node>(lm, mid, v);
            rChild = make_unique<node>(mid+1, rm, v);
            calc();
        }
    }

    void calc() {
        if (lm == rm) return;
        val = comb(lChild->val, rChild->val);
    }


    void point_update(ll idx, ll new_val) {
        if (lm == rm) {
            val = new_val;
            return;
        }

        if (idx <= lChild->rm) lChild->pointUpdate(idx, new_val);
        else rChild->pointUpdate(idx, new_val);
        calc();
    }

    ll rq(ll l, ll r) {
        if (l > rm || r < lm) return neutral;
        if (l <= lm && r >= rm) return val;
        return comb(lChild->rq(l, r), rChild->rq(l, r));
    }
};