

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
        
    }

    int next(int price) {

        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

Input:
["StockSpanner","next","next","next","next","next","next","next"]
[[],[100],[80],[60],[70],[60],[75],[85]]

  Output: [null, 1, 1, 1, 2, 1, 4, 6]
