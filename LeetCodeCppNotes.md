<h1 align="center"><strong>Notes</strong></h1>

# 20251230

* 

# 20251229

* Solution to LeetCode 692 involves `priority_queue`, which is implemented as a template with a heap structure, defined as such:

```cpp
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
>
class priority_queue;
```
  parameterised by the element type, underlying container, and a comparison functor (lambda function). It has these member functions:
```cpp
priority_queue<
    pair<string, int>,
    vector<pair<string, int>>,
    decltype(cmp)
> que(cmp);

que.push(...)
que.pop()
que.top()
que.size()
```
  It is worth reviewing solution to the problem (top K frequent words):
```cpp
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> cnt;
    for (auto& word : words) {
        cnt[word]++;
    }

    auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }; 

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);
    for (auto& it: cnt) {
        que.emplace(it);
        if (que.size() > k) {
            que.pop();
        }
    }
    vector<string> res(k);
    for (int i = k - 1; i >= 0; i--) {
        res[i] = que.top().first;
        que.pop();
    }
    return res;
}
```

# 20251228

* Macros are more like last resort rather than a practical solution while coding. Two examples of common uses:
    * Access compile time variables (including platform or compiler detection) which is otherwise not obtainable. Note that this is usually combined with some inline functions.
    ```cpp
    #define LOG(...) log_impl(__FILE__, __LINE__, __VA_ARGS__)

    #ifdef _WIN32
        // Windows code
    #elif defined(__linux__)
        // Linux code
    #endif
    ```
    * Conditional compilation: debug vs. release builds.
    ```cpp
    #ifdef DEBUG
        ...
    #endif
    ```
  Some examples where macros should be avoided:
    * Constants:
    ```cpp
    #define PI 3.14 // NG
    inline constexpr double PI = 3.14;
    ```
    * Functions:
    ```cpp
    #define MAX(a,b) ((a) > (b) ? (a) : (b)) // NG
    template <typename T>
    constexpr T max(T a, T b) { return a > b ? a : b; }
    ```
    * Type aliases:
    ```cpp
    #define ull unsigned long long // NG
    using ull = unsigned long long;
    ```
* The `inline` keyword allows multiple definition of the same function (with the same name). A common scenario is that a non-inline function in `.h` files cannot be included multiple times. It can also be used for `constexpr` as exemplified above.
* For `std::vector`, we should use `emplace_back` (which avoids additional copying) when creating the object on the spot and use `push_back` when we already have the object. For primitives, either is fine.