#include <iostream>

// PCL
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main(int argc,char **argv)
{
    pcl::PointCloud<pcl::PointXYZRGB> cloud;

    cloud.width = 10000;
    cloud.height = 1;
    cloud.is_dense = false;
    cloud.points.resize(cloud.width * cloud.height);

    std::cout << "Points: " << std::endl;
    
    for(auto& point: cloud)
    {
        point.x = 1024 * rand () / (RAND_MAX + 1.0f);
        point.y = 1024 * rand () / (RAND_MAX + 1.0f);
        point.z = 1024 * rand () / (RAND_MAX + 1.0f);

        std::cerr << "    " << point.x << " " << point.y << " " << point.z << std::endl;
    }

    //pcl::io::savePCDFileASCII("points.pcd", cloud);
    pcl::io::savePCDFile("/root/pcl_tutorials/data/points.pcd",cloud,true);

    return 0;
}