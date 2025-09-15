template <typename T>
pair<T, T> extended_eucledian(T a, T b) {
    // [a * x + b * y = g]
    // [b * x_  + (a % b) y_ = g]   =>  [b * x_ + (a - (a / b) * b) y_ = g]  => [a * y_ + b * (x_ + (a / b) y_) = g]
    // so x = y_ and y = x_ - (a / b) y_
    // base case g * 1 + 0 = g    =>    x__ = 1 and y__ = 0
    if (a < b) swap(a, b);
    if (b == 0) return {1, 0};
    pair<T, T> mp = extended_eucledian(b, a % b);
    T x_ = mp.first;
    T y_ = mp.second;
    T x = y_;
    T y = x_ - (a / b) * y_;
    return {x, y};
}

template <typename T>
pair<T, T> linear_diophantine(T a, T b, T c) {
    // a * x + b * y = c
    // as a and b are multiples of g, so c will also be a multiple of g, where g = gcd(a, b)
    // a * x + b * y = (k * g)
    // a * (x / k) + b * (y / k) = g
    // a * x_ + b * y_ = g
    T k = c / __gcd(a, b);
    pair<T, T> cur = extended_eucledian(a, b);
    T x_ = cur.first, y_ = cur.second;
    T x = k * x_;
    T y = k * y_;
    return {x, y};
}