## PCL Tutorials

PCL(Point CLoud Library) is a library which widely used in Robotics and so on.
For detailed information yoou can search the [official repo](https://github.com/PointCloudLibrary/pcl) 
and [website](https://pointclouds.org/).
The main reason of this repo is that learning Point Cloud via hands on implementation with PCL library.

#### Important Note
The project has Dockerfile which is inspired from [Daniel Lopez Madrid](https://github.com/DLopezMadrid)
and it is possible to reach related repo [by link](https://github.com/DLopezMadrid/pcl-docker).

#### Docker

To run, test and development the codes on the Docker:

```bash
# clone the repo
$ cd ~/
$ git clone https://github.com/Kucukcollu/pcl_tutorials.git

# change directory
$ cd ~/pcl_tutorials/docker

# build Docker image
$ ./build.sh

# run Docker container
$ ./run.sh

```