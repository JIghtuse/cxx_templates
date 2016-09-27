#include <iostream>

void adjust_values(double *alpha1, double *beta1, double *alpha2, double *beta2)
{
    *alpha1 += 1;
    *alpha2 += 1;
    *beta1 -= 1;
    *beta2 -= 1;
}

struct location
{

};

struct datetime
{
};

class reading {
public:
    reading(double alpha, double beta)
        : alpha_{alpha}
        , beta_{beta}
    {}
    double alpha_value(location, datetime) const
    {
        return alpha_;
    }
    double beta_value(location, datetime) const
    {
        return beta_;
    }
private:
    double alpha_;
    double beta_;
};

std::ostream& operator<<(std::ostream& out, const reading& r)
{
    return out << "alpha: " << r.alpha_value({}, {}) << ", "
               << "beta: " << r.beta_value({}, {});
}

int main()
{
    auto r = reading{2.3, 4.2};
    std::cout << r << '\n';
}
