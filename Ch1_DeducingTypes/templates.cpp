// Chapter 1 Deducing types
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <initializer_list>
#include <boost/type_index.hpp>


template<typename T>
void lvref_template( T& param );

template<typename T>
void const_lvref_template( const T& param );

template<typename T>
void uvref_template( T&& param );

template<typename T>
void ptr_template( T* param );

template<typename T>
void const_ptr_template( const T* param );

template<typename T>
void byvalue_template( T param );


int main()
{
    int i = 42;
    const int ci = i;
    const int& ri = i;
    const int* pci = &ci;
    const int* const cpci = &ci;

    std::cout << "===============\n";
    std::cout << "lvref_template( int ):\n";
    lvref_template( i );
    std::cout << "lvref_template( const int ):\n";
    lvref_template( ci );
    std::cout << "lvref_template( const int& ):\n";
    lvref_template( ri );
    std::cout << "lvref_template( const int* ):\n";
    lvref_template( pci );
    std::cout << "lvref_template( const int* const ):\n";
    lvref_template( cpci );
    // std::cout << "lvref_template( 42 ):\n";
    // lvref_template( 42 );
    std::cout << "===============\n" << std::endl;
    
    std::cout << "===============\n";
    std::cout << "const_lvref_template( int ):\n";
    const_lvref_template( i );
    std::cout << "const_lvref_template( const int ):\n";
    const_lvref_template( ci );
    std::cout << "const_lvref_template( const int& ):\n";
    const_lvref_template( ri );
    std::cout << "const_lvref_template( const int* ):\n";
    const_lvref_template( pci );
    std::cout << "const_lvref_template( const int* const ):\n";
    const_lvref_template( cpci );
    std::cout << "const_lvref_template( 42 ):\n";
    const_lvref_template( 42 );
    std::cout << "===============\n" << std::endl;

    std::cout << "===============\n";
    std::cout << "uvref_template( int ):\n";
    uvref_template( i );
    std::cout << "uvref_template( const int ):\n";
    uvref_template( ci );
    std::cout << "uvref_template( const int& ):\n";
    uvref_template( ri );
    std::cout << "uvref_template( const int* ):\n";
    uvref_template( pci );
    std::cout << "uvref_template( const int* const ):\n";
    uvref_template( cpci );
    std::cout << "uvref_template( 42 ):\n";
    uvref_template( 42 );
    std::cout << "===============\n" << std::endl;

    std::cout << "===============\n";
    std::cout << "byvalue_template( int ):\n";
    byvalue_template( i );
    std::cout << "byvalue_template( const int ):\n";
    byvalue_template( ci );
    std::cout << "byvalue_template( const int& ):\n";
    byvalue_template( ri );
    std::cout << "byvalue_template( const int* ):\n";
    byvalue_template( pci );
    std::cout << "byvalue_template( const int* const ):\n";
    byvalue_template( cpci );
    std::cout << "byvalue_template( 42 ):\n";
    byvalue_template( 42 );
    std::cout << "===============\n" << std::endl;

    std::cout << "===============\n";
    std::cout << "ptr_template( int* ):\n";
    ptr_template( &i );
    std::cout << "ptr_template( const int* ):\n";
    ptr_template( &ci );
    std::cout << "ptr_template( const int* ):\n";
    ptr_template( &ri );
    std::cout << "ptr_template( const int* ):\n";
    ptr_template( pci );
    std::cout << "ptr_template( const int* const ):\n";
    ptr_template( cpci );
    std::cout << "===============\n" << std::endl;

    std::cout << "===============\n";
    std::cout << "ptr_template( int* ):\n";
    const_ptr_template( &i );
    std::cout << "const_ptr_template( const int* ):\n";
    const_ptr_template( &ci );
    std::cout << "const_ptr_template( const int* ):\n";
    const_ptr_template( &ri );
    std::cout << "const_ptr_template( const int* ):\n";
    const_ptr_template( pci );
    std::cout << "const_ptr_template( const int* const ):\n";
    const_ptr_template( cpci );
    std::cout << "===============\n" << std::endl;
}


template<typename T>
void lvref_template( T& param )
{
    using std::cout; using std::endl;
    using boost::typeindex::type_id_with_cvr;
    cout << "\tT = " << type_id_with_cvr<T>().pretty_name() 
         << "\n\tparam = "
         << type_id_with_cvr<decltype(param)>().pretty_name() << endl;

}


template<typename T>
void const_lvref_template( const T& param )
{
    using std::cout; using std::endl;
    using boost::typeindex::type_id_with_cvr;
    cout << "\tT = " << type_id_with_cvr<T>().pretty_name() 
    << "\n\tparam = "
    << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}


template<typename T>
void uvref_template( T&& param )
{
    using std::cout; using std::endl;
    using boost::typeindex::type_id_with_cvr;
    cout << "\tT = " << type_id_with_cvr<T>().pretty_name() 
    << "\n\tparam = "
    << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}


template<typename T>
void ptr_template( T* param )
{
    using std::cout; using std::endl;
    using boost::typeindex::type_id_with_cvr;

    cout << "\tT = " << type_id_with_cvr<T>().pretty_name() 
    << "\n\tparam = "
    << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}


template<typename T>
void const_ptr_template( const T* param )
{
    using std::cout; using std::endl;
    using boost::typeindex::type_id_with_cvr;
    cout << "\tT = " << type_id_with_cvr<T>().pretty_name() 
    << "\n\tparam = "
    << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}


template<typename T>
void byvalue_template( T param )
{
    using std::cout; using std::endl;
    using boost::typeindex::type_id_with_cvr;
    cout << "\tT = " << type_id_with_cvr<T>().pretty_name() 
    << "\n\tparam = "
    << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}
