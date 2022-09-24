#include <iostream>

// PCL
#include <pcl/visualization/cloud_viewer.h>

void function(pcl::visualization::PCLVisualizer& viewer)
{
    pcl::PointXYZRGB point;
    point.x = 1.0;
    point.y = 0.0;
    point.z = 0.0;
    
    viewer.setBackgroundColor(0.0, 0.0, 0.0);
    viewer.addSphere(point, 0.25, "sphere",0);
    viewer.addText("Point",200,300,"text",0);
}

int main()
{
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::visualization::CloudViewer viewer("Cloud Viewer");

    viewer.showCloud(cloud);
    viewer.runOnVisualizationThreadOnce (function);

    while (!viewer.wasStopped ())
    {
        // to do
    }
    
    return 0;
}