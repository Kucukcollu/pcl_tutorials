FROM ubuntu:bionic

# Docker info
LABEL project="PCL Docker Image for Development"
LABEL version="0.0.1"
LABEL maintainer="Ali Aydin Kucukcollu <kucukcollu@outlook.com>"

# GPU support
ENV NVIDIA_VISIBLE_DEVICES \
    ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES \
    ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

# Update and upgrade
RUN apt-get update && \
    apt-get upgrade -y

ENV DEBIAN_FRONTEND=noninteractive

# Install tools
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    openssh-server \
    openssh-client \
    apt-utils \
    wget \
    unzip \
    git \
    htop \
    tmux \
    vim \
    nano \
    unzip

# Install CMake
WORKDIR /tmp

RUN apt-get update && \
    apt-get install -y \
    libssl-dev \
    libgl1-mesa-dev

ENV CMAKE_VERSION="3.10.2"
RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}.tar.gz && \
    tar -xvf cmake-${CMAKE_VERSION}.tar.gz && \
    cd cmake-${CMAKE_VERSION} && \
    ./bootstrap -- -DCMAKE_BUILD_TYPE:STRING=Release && \
    make && \
    make install

# Install VTK
WORKDIR /tmp

RUN apt-get update && \
    apt-get install -y \
    libxt-dev 

RUN wget https://www.vtk.org/files/release/8.2/VTK-8.2.0.tar.gz && \
    tar -xf VTK-8.2.0.tar.gz && \
    cd VTK-8.2.0 && mkdir build && cd build && \
    cmake .. -DVTK_MODULE_ENABLE_VTK_RenderingContextOpenGL2=YES \
             -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install

#  Install PCL
WORKDIR /tmp

# PCL dependencies
RUN apt-get install -y \
    libeigen3-dev \
    libflann-dev \
    libglu1-mesa-dev \
    freeglut3-dev \
    mesa-common-dev \
    libboost-all-dev \
    libusb-1.0-0-dev \
    libusb-dev \
    libopenni-dev \
    libopenni2-dev \
    libpcap-dev \
    libpng-dev \
    mpi-default-dev \
    openmpi-bin \
    openmpi-common \
    libqhull-dev \
    libgtest-dev

ENV PCL_VERSION="1.11.0"
RUN wget https://github.com/PointCloudLibrary/pcl/archive/pcl-${PCL_VERSION}.tar.gz && \
    tar -xf pcl-${PCL_VERSION}.tar.gz && \
    cd pcl-pcl-${PCL_VERSION} && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release \
              -DVTK_RENDERING_BACKEND=OpenGL2 && \
    make -j$(nproc) && \
    make install

RUN apt-get update && \
    apt-get install -y \
    pcl-tools

RUN unset PCL_VERSION

WORKDIR /root