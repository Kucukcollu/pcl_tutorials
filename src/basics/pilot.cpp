#include <iostream>
#include <pcl/pcl_config.h>

int main()
{
    std::cout << "PCL VERSION: ";
    std::cout << PCL_MAJOR_VERSION;
    std::cout << "." << PCL_MINOR_VERSION << std::endl;

    return 0;
}