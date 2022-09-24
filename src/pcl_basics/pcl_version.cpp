#include <iostream>

// PCL
#include <pcl/pcl_config.h>

int main(int argc, char **argv)
{
    std::cout << "PCL VERSION: ";
    std::cout << PCL_MAJOR_VERSION;
    std::cout << "." << PCL_MINOR_VERSION;
    std::cout << "." << PCL_REVISION_VERSION << std::endl;

    return 0;
}