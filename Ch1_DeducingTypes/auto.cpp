// Chapter 1 Deducing Types -- auto type deduction
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <boost/type_index.hpp>



int main()
{
    using std::cout; using std::endl;
    using boost::typeindex::type_id_with_cvr;

    int i = 42;
    const int ci = 42;
    const int& cri = i;

    auto a = i;
    const auto ca = i;
    const auto& cra = i;
    const auto cpa = &i;
    const auto cpca = &ci;
    const auto& cprca = &cri;
    cout << "a  = " << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
    cout << "ca = " << type_id_with_cvr<decltype(ca)>().pretty_name() << endl;
    cout << "cra = " << type_id_with_cvr<decltype(cra)>().pretty_name() << endl;
    cout << "cpa = " << type_id_with_cvr<decltype(cpa)>().pretty_name() << endl;
    cout << "cpca = " << type_id_with_cvr<decltype(cpca)>().pretty_name() << endl;
    cout << "cprca = " << type_id_with_cvr<decltype(cprca)>().pretty_name() << endl;
}
