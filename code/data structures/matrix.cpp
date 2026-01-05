// Matrix Structure

// A reusable structure for Matrix operations.
// Essential for solving linear recurrences (e.g., Fibonacci) in logarithmic time.

// - Multiplication: O(n³)
// - Exponentiation: O(n³ log(k))

template<typename T> struct Matrix : vector<vector<T>> {
    int n, m;

    Matrix(int n_, int m_, bool ident = false) :
        vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
            if (ident) {
                for (int i = 0; i < n; i++) (*this)[i][i] = 1;
            }
        }
    
    Matrix(const vector<vector<T>> &c) :
        vector<vector<T>>(c), n(c.size()), m(c[0].size()) {}

    Matrix<T> operator *(const Matrix<T> &r) {
        Matrix<T> res(n, r.m);

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if ((*this)[i][k] == 0) continue;

                for (int j = 0; j < r.m; j++) {
                    res[i][j] = mod_add(
                        res[i][j],
                        mod_mul((*this)[i][k], r[k][j])
                    );
                }
            }
        }

        return res;
    }

    Matrix<T> operator ^(ll e) {
        Matrix<T> res(n, n, true), base = *this;

        while(e) {
            if (e&1) res = res * base;
            e >>= 1;
            base = base * base;
        }

        return res;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
            cout << endl;
        }
    }
}