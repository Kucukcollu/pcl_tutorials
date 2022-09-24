#include <iostream>
#include <string>

// PCL
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main(int argc, char **argv)
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);

    if(pcl::io::loadPCDFile<pcl::PointXYZRGB>("/root/pcl_tutorials/data/points.pcd", *cloud) == -1)
    {
        PCL_ERROR ("Couldn't read file custom.pcd \n");
        return -1;
    }
    else
    {
        std::cout << "Loaded " << cloud->width * cloud->height
                    << " data points from custom.pcd with the following fields: "
                    << std::endl;

        for(const auto& point: *cloud)
        {
            std::cout << "  " << point.x
                        << "  " << point.y
                        << "  " << point.z
                        << "  " << std::endl;
        }
    }

    return 0;
}