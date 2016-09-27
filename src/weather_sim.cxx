#include <iostream>
#include <tuple>

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

template<typename Reading>
std::tuple<double, double, double, double> get_adjusted_values(
        const Reading& r,
        location,
        datetime t1,
        datetime t2)
{
    double alpha1 = r.alpha_value({}, t1);
    double beta1 = r.alpha_value({}, t1);

    double alpha2 = r.alpha_value({}, t2);
    double beta2 = r.alpha_value({}, t2);

    adjust_values(&alpha1, &beta1, &alpha2, &beta2);
    return std::make_tuple(alpha1, beta1, alpha2, beta2);
}


int main()
{
    auto r = reading{2.3, 4.2};
    std::cout << r << '\n';
    auto t = get_adjusted_values(r, {}, {}, {});
    std::cout << "alpha: " << std::get<0>(t)
              << ", beta: " << std::get<1>(t) << '\n';
    std::cout << "alpha: " << std::get<2>(t)
              << ", beta: " << std::get<3>(t) << '\n';
}
